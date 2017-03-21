/**
* @file DynamicComposition.cpp
* @author FH-Minden Musikinformatik 2015, Musicgroup (Marcel, Patrick, Scott)
* @brief Encapsulates a plugin
*
*/
#pragma once
#pragma comment(lib,"Ws2_32.lib")
#include <winsock2.h>  
#ifndef TTMM_Dynamic_Composition_H
#define TTMM_Dynamic_Composition_H

#include "FileWriter.h"
#include "GeneralPluginProcessor.h"
#include "../Model/Song.h"
#include "../src/MidiReader.h"
#include "../src/MidiHandler.h"
#include "TimeTools.h"
#include "IPCConnection.h"
#include <chrono>
#include <thread>
#include <iostream>  

namespace ttmm
{

/**
	* @class DynamicComposition
	* @brief inherits to the class GeneralPluginProcessor and supports to process the block events between the plugins on Host, 
				to put mididata into the structures for postprocessing,
				to update Midibuffer with the new input 
				to send new MidiBuffer to another groups
	*
	* @see MidiReader, MidiHandler, Song, MidiBuffer, GlobalObject
	*/
class DynamicComposition : public GeneralPluginProcessor
{
public:
    const std::string PIPE_NAME = "18cmPENIS";
	const std::string HOST_NAME = "127.0.0.1";

    /**
		* Constructor: create a DynamicComposition
		*/
    DynamicComposition();
    /**
		* Destructor
		*/
    ~DynamicComposition();
    /**
		* override the virtual function of the class Audio processeor
		* 
		* @param sampleRate a double argument
		*/
    void initializePlugin(Samplerate sampleRate) final override
    {
        this->samplerate = sampleRate;
		start(); //<read Midifile to internal structure

        //fill the songinfo object with the default values & create pipe
        this->localmusician = this->songInfo.add_musician();
        auto musician = this->localmusician;
        musician->set_accuracy(0);
        musician->set_tune(IPCSongInfo_IPCMusician_Tune::IPCSongInfo_IPCMusician_Tune_MIDDLE_UP);
        musician->set_volumech1(121);
        musician->set_volumech2(77);
        musician->set_volumech3(50);
        connectionPipe.createPipe(PIPE_NAME, 1000);

        //save the playTime and system time of plugin music to a file, when pluginMusic starts
        std::ofstream fstartPluginMusic;
        fstartPluginMusic.open("bigbang.txt", std::ios::out);
        timebase = TimeInfo::timeInfo().realtimeInNanoseconds();
        fstartPluginMusic << timebase << " " << this->playTime << std::endl;
        fstartPluginMusic.close();
		openVisAndSocket("");
    }

    /**
		* override the virtual function of the class Audio processeor
		*
		*/
    void shutdown() final override
    {
		stop();
		closesocket(connectionSocket);
        // Disconnecting would be obvious and shouldn't do harm - but this causes a memory leak.
        // The connection is closed anyway in the destructor of IPCConnection.
        // connection.disconnect();
    }

    /**
		* override the virtual function of the class Audio processeor and process the block datas between the plugins on host
		* 
		* @param audioBuffer a reference to AudioBuffer
		* @param midiBuffer a reference to MidiBuffer
		*/
    void processAudioAndMidiSignals(AudioBuffer& audioBuffer,
        juce::MidiBuffer& midiBuffer) final override;
    
	/**
		* merge musicians from IPC to local Songinfo
		*/
    void mergeMusicians();
    
	/**
		* override the virtual function of the class GeneralPluginProcessor
		*
		* @param object a SongInfo object received through IPC
		*/
    void receivedIPC(IPCSongInfo object) override final;
	
	String getSongName() {
		return songname;
	}
	String getSongTempo() {
		return std::to_string(song.getBpm());
	}

	void stop()
	{
		playing = false;
		this->song.~Song();
		this->song = NULL;
		//playTime = -5;

		this->localmusician = this->songInfo.add_musician();
		auto musician = this->localmusician;
		musician->set_accuracy(0);
		musician->set_tune(IPCSongInfo_IPCMusician_Tune::IPCSongInfo_IPCMusician_Tune_MIDDLE_UP);
		musician->set_volumech1(121);
		musician->set_volumech2(77);
		musician->set_volumech3(50);
		sendMessageToVis("Stop 1");
	}
	bool isPlaying()
	{
		return playing;
	}
	void start()
	{
		if (playing == false) {
			playing = true;
			// read Midifile to Songobj
			songname = this->mReader.readToSong(this->song);
			ttmm::logfileMusic->write("read mididata to Song structure");

			//generate track 2 times
			for (int i = 0; i < 2; i++)
			{
				this->song.generateTrack(0);
			}
			this->song.readAllTracks();
			ttmm::logfileMusic->write("printed out the song structure");
			ttmm::logfileMusic->write("Playtime of plugin music at: ", this->playTime);
		}
		else
		{
			ttmm::logfileMusic->write("Already running!");
		}
	}
	void openVisAndSocket(String appName)
	{
		if (appName != "")
		{
			std::cout << "Opening Visualisation" << std::endl;
			std::string filepath = appName.toStdString();
			ShellExecute(NULL, "open", filepath.c_str(), NULL, NULL, SW_SHOWDEFAULT);
		}
		socketThread = std::thread(&DynamicComposition::startSocket, this);
		if (!socketThread.joinable())
		{
			std::cout << "Failed to start the SocketThread" << std::endl;
		}
	}

	juce::AudioProcessorEditor* createEditor() override; //<create custom UI for drum plugin
	bool hasEditor() const override { return true; }

private:
    MidiReader mReader; ///<a MidiReader object
	bool playing = false; ///<true, if a MidiFile was loaded and is playing
	String songname; ///<the name of the current song (filename)
    Song song = NULL; ///<a Song object
    MidiHandler mHandler; ///< a MidiHandler object
    double playTime = -5; ///<calculate the playtime of host based on Samplenumber (Buffersize) and Samplerate (44100)
    std::vector<juce::MidiMessageSequence> buffers; ///<a list of midiSequences object
    Samplerate samplerate; ///<samplerate of host
	long long timebase; ///<starting time of this plugin

    IPCConnection connectionPipe; ///<init a IPC connection by pipe for internal use
    IPCSongInfo songInfo; ///<Merged Parameters from other Plugins
    IPCSongInfo_IPCMusician* localmusician;
    std::vector<IPCSongInfo_IPCMusician> musiciansToMerge; ///<Musicians from IPC to merge
	
	int connectionSocket; ///<holds socket for connection with visualisation
	std::thread socketThread;
	bool socketConnected = false;

	void startSocket()
	{
		WSADATA w;
		if (int result = WSAStartup(MAKEWORD(2, 2), &w) != 0)
		{
			std::cout << "Winsock 2 konnte nicht gestartet werden! Error #" << result << std::endl;
		}
		using namespace std;
		connectionSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (connectionSocket == -1)
		{
			cout << "Socket konnte nicht erstellt werden!" << endl;
		}
		sockaddr_in service; // Normale IPv4 Struktur 
		service.sin_family = AF_INET; // AF_INET für IPv4, für IPv6 wäre es AF_INET6
		service.sin_port = htons(8888); // Das HTTP-Protokoll benutzt Port 80
		service.sin_addr.s_addr = inet_addr(HOST_NAME.c_str());

		std::cout << "Started connecting..." << std::endl;
		bool connected = false;
		while (!connected)
		{
			int result = connect(connectionSocket, reinterpret_cast<sockaddr*>(&service), sizeof(service));
			if (result == -1)
			{
				// could not connect
				this_thread::sleep_for(std::chrono::milliseconds(10));
			}
			else
			{
				connected = true;
				socketConnected = true;
				cout << "Connected with Socket..." << std::endl;
			}
		}
		sendMessageToVis("Start " + std::to_string((timebase / 1000000) + 5000));
	}
	void sendMessageToVis(std::string msg)
	{
		if (socketConnected) {
			send(connectionSocket, msg.c_str(), msg.size(), 0);
			std::cout << "Sending: " << msg << std::endl;
		}
	}

    TIMER_REGISTER("TimerMusic")
};
}
#endif

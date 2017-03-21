/**
* @file DrumInputPluginProecessor.h
* @author FH-Minden Musikinformatik 2015, Drumgroup (Ricco Schoenebeck, Holger Heeren, Philipp Kroos)
* @brief 
*
*/

#ifndef DRUM_INPUT_PLUGIN_PROCESSOR
#define DRUM_INPUT_PLUGIN_PROCESSOR

#include <string>

#include "DeviceInputPluginProcessor.h"
#include "DrumDevice.h"
#include "DrumMusician.h"
#include "FileWriter.h"
#include "TimeTools.h"

namespace ttmm
{

namespace
{
    using DataType = DrumDevice::DataType;
    auto const BufferSize = size_t(200);
    auto const inputDeviceName = std::wstring(L"TriggerIO");
}

class DrumInputPluginProcessor
    : public DeviceInputPluginProcessor<DrumDevice, DrumMusician, BufferSize>
{
public:
    using DataType = DrumDevice::DataType;

    DrumInputPluginProcessor()
        : DeviceInputPluginProcessor<DrumDevice, DrumMusician, BufferSize>("Trommel", DrumDevice::drumDevice(), 0)
    {
        inputDevice.addMusicians(&musicians);
        timeNow = std::chrono::system_clock::now(); //<reading the time-zero timepoint
    }
    ~DrumInputPluginProcessor();

	enum class ParameterType
	{
		MATCH_TOL,
		MAIN_CHANNEL_IN,
		MAIN_CHANNEL_OUT,
		SIDE_CHANNEL_IN,
		SIDE_CHANNEL_OUT
	};

	void updateParam(ParameterType type, int paramValue)
	{
		switch (type)
		{
		case (ParameterType::MATCH_TOL):
			matchTolerance = paramValue;
			break;
		case (ParameterType::MAIN_CHANNEL_IN) :
			midiMainChannel = paramValue;
			break;
		case (ParameterType::MAIN_CHANNEL_OUT) :
			audioMain = paramValue;
			break;
		case (ParameterType::SIDE_CHANNEL_IN) :
			midiSideChannel = paramValue;
			break;
		case (ParameterType::SIDE_CHANNEL_OUT) :
			audioSide = paramValue;
			break;
		}
	}

	int getParam(ParameterType type)
	{
		int tol = 0;
		switch (type)
		{
		case (ParameterType::MAIN_CHANNEL_IN) :
			return midiMainChannel;
			break;
		case (ParameterType::SIDE_CHANNEL_IN) :
			return midiSideChannel;
			break;
		case (ParameterType::MAIN_CHANNEL_OUT) :
			return audioMain;
			break;
		case (ParameterType::SIDE_CHANNEL_OUT) :
			return audioSide;
			break;
		case (ParameterType::MATCH_TOL) :
			return matchTolerance;
			break;
		}
		return tol;
	}

protected:
    int getAudioMainChannel() const override
    {
		return audioMain;
    }
    int getAudioSideChannel() const override
    {
		return audioSide;
    }
    int getDefaultToleranceNoteValue() const override
    {
		return matchTolerance;
    }

	juce::AudioProcessorEditor* createEditor() override; //<create custom UI for drum plugin

	bool hasEditor() const override { return true; }

private:
	int midiMainChannel = 2;
	int midiSideChannel = 3;
	int audioMain = 4;
	int audioSide = 5;
	int matchTolerance = 16;
    void calculateCustomValues(DrumMusician& m, IPCSongInfo::IPCMusician* musi) override final;
    bool init(DrumDevice& device, ttmm::Samplerate sampleRate) final override;
    void close(DrumDevice& device) final override;
    DrumMusician m;



    TIMER_REGISTER("TimerDrum")
};
}
#endif

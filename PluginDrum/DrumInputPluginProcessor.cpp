#include "DrumInputPluginProcessor.h"
#include "DrumPluginEditor.h"

bool ttmm::DrumInputPluginProcessor::init(ttmm::DrumDevice& device,
    ttmm::Samplerate samplerate)
{
    //drumSound.setSamplerate(samplerate);
    return device.openDevice(inputDeviceName);
}

void ttmm::DrumInputPluginProcessor::close(ttmm::DrumDevice& device)
{
    device.closeDevice();
}

ttmm::DrumInputPluginProcessor::~DrumInputPluginProcessor()
{
    ttmm::logger.write("DrumInputPluginProcessor:  Destroyed");
}

void ttmm::DrumInputPluginProcessor::calculateCustomValues(DrumMusician& m, IPCSongInfo::IPCMusician* musi)
{
    musi->set_accuracy(m.getAccuracy());
    musi->set_volumech3(m.getVolumeAverage());
}

juce::AudioProcessorEditor* ttmm::DrumInputPluginProcessor::createEditor()
{
	return new DrumPluginEditor(*this);
}


// This macro-call creates the required instantiation method for the plugin
TTMM_REGISTER_PLUGIN(ttmm::DrumInputPluginProcessor)

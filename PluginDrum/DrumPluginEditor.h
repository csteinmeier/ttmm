#pragma once
#include "DrumInputPluginProcessor.h"

namespace ttmm
{
	class DrumPluginEditor : public juce::AudioProcessorEditor, private juce::TextEditor::Listener
	{
	public:
		DrumPluginEditor(DrumInputPluginProcessor &);
		~DrumPluginEditor();
		void paint(Graphics&) override;
		void textEditorTextChanged(juce::TextEditor&) override;

	private:
		const int WIN_WIDTH = 500;
		const int WIN_HEIGHT = 400;
		const int PADDING = 20;

		juce::TextEditor* txtMainChannelIn;
		juce::TextEditor* txtMainChannelOut;
		juce::TextEditor* txtSideChannelIn;
		juce::TextEditor* txtSideChannelOut;
		juce::TextEditor* txtMatchTol;

		Label* lblMainChannelIn;
		Label* lblMainChannelOut;
		Label* lblSideChannelIn;
		Label* lblSideChannelOut;
		Label* lblMatchTol;

		DrumInputPluginProcessor& processor;
	};
}


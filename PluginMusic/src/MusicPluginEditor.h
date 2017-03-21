#pragma once
#include "ListDisplay.h"

namespace ttmm
{
	class MusicPluginEditor : public juce::AudioProcessorEditor, public juce::Button::Listener
	{
	public:
		MusicPluginEditor(DynamicComposition &);
		~MusicPluginEditor() = default;

		void paint(Graphics&) override;
		void buttonClicked(Button *) override;
		void addContent(String content);

	private:
		const int WIN_WIDTH = 500;
		const int WIN_HEIGHT = 500;
		const int PADDING = 10;

		TextEditor* txtSong;
		TextEditor* txtTempo;
		TextEditor* txtStatus;
		TextEditor* txtVis;

		Label* lblSong;
		Label* lblTempo;
		Label* lblVis;

		TextButton* btnSong;
		TextButton* btnPlus;
		TextButton* btnMinus;
		TextButton* btnStart;
		TextButton* btnStop;
		TextButton* btnVis;
		
		ListBox* boxNotes;

		DynamicComposition& processor;
		void checkStatus();

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MusicPluginEditor)
	};
}
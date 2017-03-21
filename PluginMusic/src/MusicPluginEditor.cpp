#include "MusicPluginEditor.h"

namespace ttmm {
	MusicPluginEditor::MusicPluginEditor(DynamicComposition &p)
		: AudioProcessorEditor(&p), processor(p)
	{
		logger.write("Plugin Window opened");
		setSize(WIN_WIDTH, WIN_HEIGHT);

		txtSong = new TextEditor("txtSong", 0);
		txtTempo = new TextEditor("txtTempo", 0);
		txtVis = new TextEditor("txtVis", 0);
		lblSong = new Label("lblSong", "Song-Name:");
		lblTempo = new Label("lblTempo", "Song-Tempo:");
		lblVis = new Label("lblVis", "Visualisierungsdatei:");
		btnSong = new TextButton("Aendern ...", "Klicken um neues MIDI File auszuwaehlen");
		btnPlus = new TextButton("+", "Klicken um Tempo zu erhoehen");
		btnMinus = new TextButton("-", "Klicken um Tempo zu verringern");
		txtStatus = new TextEditor("txtStatus", 0);
		btnStart = new TextButton("btnStart", "");
		btnStop = new TextButton("btnStop", "");
		btnVis = new TextButton("btnVis", "");
		boxNotes = new ListBox();

		lblSong->setSize(100, 20);
		lblSong->setTopLeftPosition(20, 20);
		txtSong->setSize(200, 20);
		txtSong->setTopLeftPosition(150, 20);
		txtSong->setText(processor.getSongName());
		txtSong->setReadOnly(true);
		btnSong->setSize(70, 20);
		btnSong->setTopLeftPosition(360, 20);
		
		lblTempo->setSize(100, 20);
		lblTempo->setTopLeftPosition(20, 50);
		txtTempo->setSize(200, 20);
		txtTempo->setTopLeftPosition(150, 50);
		txtTempo->setText(processor.getSongTempo());
		txtTempo->setReadOnly(true);
		btnMinus->setSize(30, 20);
		btnMinus->setTopLeftPosition(360, 50);
		btnPlus->setSize(30, 20);
		btnPlus->setTopLeftPosition(400, 50);

		lblVis->setSize(100, 20);
		lblVis->setTopLeftPosition(20, 80);
		txtVis->setSize(200, 20);
		txtVis->setTopLeftPosition(150, 80);
		btnVis->setSize(50, 20);
		btnVis->setTopLeftPosition(360, 80);
		btnVis->setButtonText("Starte Visualisierung");
		btnVis->addListener(this);

		txtStatus->setReadOnly(true);
		int width = (WIN_WIDTH - (PADDING * 4)) / 3;
		txtStatus->setSize(width, 40);
		btnStart->setSize(width, 40);
		btnStop->setSize(width, 40);
		btnStart->setTopLeftPosition(PADDING, 110);
		txtStatus->setTopLeftPosition((PADDING * 2) + width, 110);
		btnStop->setTopLeftPosition((PADDING * 3) + (width * 2), 110);
		btnStart->setButtonText("Starte Lied");
		btnStop->setButtonText("Stoppe Lied");
		checkStatus();
		btnStart->addListener(this);
		btnStop->addListener(this);
		
		boxNotes->setSize(WIN_WIDTH - 40, WIN_HEIGHT - 200);
		boxNotes->setTopLeftPosition(20, 140);
		boxNotes->setModel(new ListDisplay());

		addAndMakeVisible(txtSong);
		addAndMakeVisible(lblSong);
		addAndMakeVisible(btnSong);
		addAndMakeVisible(txtTempo);
		addAndMakeVisible(lblTempo);
		addAndMakeVisible(btnPlus);
		addAndMakeVisible(btnMinus);
		addAndMakeVisible(boxNotes);
		addAndMakeVisible(btnStart);
		addAndMakeVisible(btnStop);
		addAndMakeVisible(txtStatus);
		addAndMakeVisible(txtVis);
		addAndMakeVisible(lblVis);
		addAndMakeVisible(btnVis);
	}

	void MusicPluginEditor::paint(Graphics& g)
	{
		//// fill the whole window white
		g.fillAll(Colours::white);
	}

	void MusicPluginEditor::checkStatus()
	{
		if (processor.isPlaying())
		{
			txtStatus->setText("Lied wird gespielt");
			btnStart->setEnabled(false);
			btnStop->setEnabled(true);
		}
		else
		{
			txtStatus->setText("Lied ist gestoppt");
			btnStart->setEnabled(true);
			btnStop->setEnabled(false);
		}
	}

	void MusicPluginEditor::buttonClicked(Button* b)
	{
		ttmm::logfileMusic->write(b->getName().toStdString() + "was clicked");
		if (b==nullptr)
		{
			ttmm::logfileMusic->write("No Button");
			return;
		}
		if (b->getName().toStdString() == "btnStart")
		{
			ttmm::logfileMusic->write("Pressed Start");
			processor.start();
			checkStatus();
			return;
		}
		if (b->getName().toStdString() == "btnStop")
		{
			ttmm::logfileMusic->write("Pressed Stop");
			processor.stop();
			checkStatus();
			return;
		}
		if (b->getName().toStdString() == "btnVis")
		{
			ttmm::logfileMusic->write("Pressed Visualisation Start");
			processor.openVisAndSocket(txtVis->getText());
			return;
		}
	}

	void MusicPluginEditor::addContent(String content)
	{
		if (this == nullptr)
		{
			//ttmm::logfileMusic->write("editor fenster existiert nicht");
			return;
		}
		else
		{
			//ttmm::logfileMusic->write("editor fenster ist offen, schreibe eintrag in liste");
			int nr = ((ListDisplay*)boxNotes->getModel())->addRow(content);
			//boxNotes->scrollToEnsureRowIsOnscreen(nr);
			boxNotes->repaint();
		}
	}
}

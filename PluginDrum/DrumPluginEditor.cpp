#pragma once
#include "DrumPluginEditor.h"

ttmm::DrumPluginEditor::DrumPluginEditor(DrumInputPluginProcessor & p)
: AudioProcessorEditor(&p), processor(p)
{
	logger.write("Plugin Window opened");
	setSize(WIN_WIDTH, WIN_HEIGHT);

	// create gui objects
	txtMainChannelIn = new TextEditor("txtMainChannelIn", 0);
	txtMainChannelOut = new TextEditor("txtMainChannelOut", 0);
	txtSideChannelIn = new TextEditor("txtSideChannelIn", 0);
	txtSideChannelOut = new TextEditor("txtSideChannelOut", 0);
	txtMatchTol = new TextEditor("txtMatchTol", 0);
	lblMainChannelIn = new Label("lblMainChannelIn", "Main Channel (In)");
	lblMainChannelOut = new Label("lblMainChannelOut", "Main Channel (Out)");
	lblSideChannelIn = new Label("lblSideChannelIn", "Side Channel (In)");
	lblSideChannelOut = new Label("lblSideChannelOut", "Side Channel (Out)");
	lblMatchTol = new Label("lblMatchTol", "Match Tolerance");

	// set gui objects' parameters (size, position, listener)
	int width = (WIN_WIDTH - (PADDING * 2)) / 2;
	int height = 20;
	txtMainChannelIn->setSize(width, height);
	txtMainChannelOut->setSize(width, height);
	txtSideChannelIn->setSize(width, height);
	txtSideChannelOut->setSize(width, height);
	txtMatchTol->setSize(width, height);
	lblMainChannelIn->setSize(width, height);
	lblMainChannelOut->setSize(width, height);
	lblSideChannelIn->setSize(width, height);
	lblSideChannelOut->setSize(width, height);
	lblMatchTol->setSize(width, height);
	txtMainChannelIn->addListener(this);
	txtMainChannelOut->addListener(this);
	txtSideChannelIn->addListener(this);
	txtSideChannelOut->addListener(this);
	txtMatchTol->addListener(this);

	txtMainChannelIn->setTopLeftPosition(PADDING + width, PADDING + 20);
	txtSideChannelIn->setTopLeftPosition(PADDING + width, PADDING + 50);
	txtMainChannelOut->setTopLeftPosition(PADDING + width, PADDING + 80);
	txtSideChannelOut->setTopLeftPosition(PADDING + width, PADDING + 110);
	txtMatchTol->setTopLeftPosition(PADDING + width, PADDING + 140);
	lblMainChannelIn->setTopLeftPosition(PADDING, PADDING + 20);
	lblSideChannelIn->setTopLeftPosition(PADDING, PADDING + 50);
	lblMainChannelOut->setTopLeftPosition(PADDING, PADDING + 80);
	lblSideChannelOut->setTopLeftPosition(PADDING, PADDING + 110);
	lblMatchTol->setTopLeftPosition(PADDING, PADDING + 140);

	// fill text boxes with values:
	txtMainChannelIn->setText(juce::String(processor.getParam(DrumInputPluginProcessor::ParameterType::MAIN_CHANNEL_IN)), false);
	txtMainChannelOut->setText(juce::String(processor.getParam(DrumInputPluginProcessor::ParameterType::MAIN_CHANNEL_OUT)), false);
	txtSideChannelIn->setText(juce::String(processor.getParam(DrumInputPluginProcessor::ParameterType::SIDE_CHANNEL_IN)), false);
	txtSideChannelOut->setText(juce::String(processor.getParam(DrumInputPluginProcessor::ParameterType::SIDE_CHANNEL_OUT)), false);
	txtMatchTol->setText(juce::String(processor.getParam(DrumInputPluginProcessor::ParameterType::MATCH_TOL)), false);

	// add gui components to editor
	addAndMakeVisible(txtMainChannelIn);
	addAndMakeVisible(txtMainChannelOut);
	addAndMakeVisible(txtSideChannelIn);
	addAndMakeVisible(txtSideChannelOut);
	addAndMakeVisible(lblMainChannelIn);
	addAndMakeVisible(lblMainChannelOut);
	addAndMakeVisible(lblSideChannelIn);
	addAndMakeVisible(lblSideChannelOut);
	addAndMakeVisible(lblMatchTol);
	addAndMakeVisible(txtMatchTol);
}


ttmm::DrumPluginEditor::~DrumPluginEditor()
{
	ttmm::logger.write("Closing Plugin Window");
}

void ttmm::DrumPluginEditor::paint(Graphics& g)
{
	//fill the whole window white
	g.fillAll(Colours::white);
}

void ttmm::DrumPluginEditor::textEditorTextChanged(TextEditor& e)
{
	if (e.isEmpty())
	{
		// yet not defined
		return;
	}
	int val = e.getText().getIntValue();
	if (e.getName().toStdString() == "txtMainChannelIn")
	{
		processor.updateParam(DrumInputPluginProcessor::ParameterType::MAIN_CHANNEL_IN, val);
	}
	if (e.getName().toStdString() == "txtMainChannelOut")
	{
		processor.updateParam(DrumInputPluginProcessor::ParameterType::MAIN_CHANNEL_OUT, val);
	}
	if (e.getName().toStdString() == "txtSideChannelIn")
	{
		processor.updateParam(DrumInputPluginProcessor::ParameterType::SIDE_CHANNEL_IN, val);
	}
	if (e.getName().toStdString() == "txtSideChannelOut")
	{
		processor.updateParam(DrumInputPluginProcessor::ParameterType::SIDE_CHANNEL_OUT, val);
	}
	if (e.getName().toStdString() == "txtMatchTol")
	{
		processor.updateParam(DrumInputPluginProcessor::ParameterType::MATCH_TOL, val);
	}
}

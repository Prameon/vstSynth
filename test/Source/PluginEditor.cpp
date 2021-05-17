/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TestAudioProcessorEditor::TestAudioProcessorEditor (TestAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    
    SliderGain.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    SliderGain.setTextValueSuffix("dB");
    //SliderGain.setRange(0.0, 1.0f, 0.01f);
    //SliderGain.setValue(0.5f);
    addAndMakeVisible(SliderGain);
    AttachmentGainSlider = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.getValueTree(), "GAIN", SliderGain);
    


    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 300);
}

TestAudioProcessorEditor::~TestAudioProcessorEditor()
{
}

//==============================================================================
void TestAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

   
}

void TestAudioProcessorEditor::resized()
{
    SliderGain.setBounds(10, 1, 500, 100);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

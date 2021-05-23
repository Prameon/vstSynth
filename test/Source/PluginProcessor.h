/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "Sound.h"
#include "Voice.h"

//==============================================================================
/**
*/
class TestAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    TestAudioProcessor();
    ~TestAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState& getValueTree() { return apvts; }
private:
    /*Создание Синтезатора*/
    const int NumberVoice {16}; 
    juce::Synthesiser synth;   
    /*
    Количество голосов в synth будет 16,
    Создание Синтезатора (для того чтобы он играл нужно создать juce::SynthesiserVoice, juce::SynthesiserSound)
    Создал и подключил #include "Sound.h", #include "Voice.h"  
    */


    /*Дерево значений параметров.*/
    juce::AudioProcessorValueTreeState apvts;
    juce::AudioProcessorValueTreeState::ParameterLayout createParameters();
    void setParams(); 
    /*
    Создал Дерево значений параметров. (apvts)
    функция createParameters() создание самих параметров и значений.
    
    setParams() моя функция для передачи параметров из дерева в voice
    */
 
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TestAudioProcessor)
};

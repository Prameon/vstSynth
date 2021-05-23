/*
  ==============================================================================

    Voice.h
    
  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Sound.h"

class Voice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);// +
    void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples) override;
    void setGain(float* gain); //передать значение gain в dB. 
private:
    juce::dsp::Oscillator<float> Osc1 { [](float x) { return std::sin(x); } }; //sin
    juce::dsp::Gain<float> gain; //Громкость
    double Gain;
};


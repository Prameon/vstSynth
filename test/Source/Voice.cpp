/*
  ==============================================================================

    Voice.cpp

  ==============================================================================
*/

#include "Voice.h"

bool Voice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}

void Voice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{ 
}

void Voice::stopNote(float velocity, bool allowTailOff)
{
}

void Voice::controllerMoved(int controllerNumber, int newControllerValue)
{
}


void Voice::pitchWheelMoved(int newPitchWheelValue)
{
}

void Voice::setGain(float* gain)
{
    this->Gain = *gain;  
}

void Voice::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels)
{
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    Osc1.prepare(spec);
    gain.prepare(spec);
}

void Voice::renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples)
{
    juce::dsp::AudioBlock<float> audioBlock{ outputBuffer };
    Osc1.setFrequency(220.0f); //hz
    Osc1.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));

    gain.setGainDecibels(Gain);  // принимает dB  
    gain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
}


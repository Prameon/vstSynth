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


void Voice::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels)
{
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    Osc1.prepare(spec);
    Osc1.setFrequency(220.0f);

}

void Voice::renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples)
{
    juce::dsp::AudioBlock<float> audioBlock{ outputBuffer };
    Osc1.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
}

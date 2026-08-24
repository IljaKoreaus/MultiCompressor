/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

/*
 GUI RoadMap:
 1) Global Controls (x-over sliders, gain sliders)
 2) Main Band Controls (attack, threshold, ratio, release)
 3) add solo/mute/bypass buttons
 4) Band Select Functionality
 5) Band Select Buttons reflect the Solo/Mute/Bypass State
 6) Custom Look And Feel For Sliders & Toggle Buttons
 7) Spectrum Analyzer Overview
 8) Data Structures for spectrum Analyzer
 9) Fifo usage in pluginProcessor::processBlock
 10) implementation of the analyzer rendering pre-computed paths
 11) Drawing crossovers on to of the analyzer plot
 12) Drawing gain reduction on top of the analyzer
 13) Analyzer Bypass
 14) Global Bypass button
 */
#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
struct Placeholder : juce::Component
{
    Placeholder();
    
    void paint(juce::Graphics& g) override
    {
        g.fillAll(customColor);
    }
    juce::Colour customColor;
};
/**
*/
class SimpleMBCompAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SimpleMBCompAudioProcessorEditor (SimpleMBCompAudioProcessor&);
    ~SimpleMBCompAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleMBCompAudioProcessor& audioProcessor;
    
    Placeholder controlBar, analyzer, globalControls, bandControls;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleMBCompAudioProcessorEditor)
};

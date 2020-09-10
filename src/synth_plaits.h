#ifndef SYNTH_PLAITS_H_
#define SYNTH_PLAITS_H_

#include "core_pins.h"
#include "AudioStream.h"
#include "plaits/dsp/dsp.h"
#include "plaits/dsp/voice.h"
#include "stmlib/utils/buffer_allocator.h"

using namespace plaits;
using namespace stmlib;

enum synthParameters {
    engine,
    note,
    frequency,    
    harmonics,
    timbre,
    morph,
    frequencyModulationAmount,
    timbreModulationAmount,
    morphModulationAmount,
    decay,
    lpgColour,
    level,
    trigger,
    frequencyPatched,
    timbrePatched,
    morphPatched,
    triggerPatched,
    levelPatched    
};

class AudioSynthPlaits: public AudioStream
{
    public:
        AudioSynthPlaits(): AudioStream(0, NULL)
        { initPlaits();	}
        ~AudioSynthPlaits() { }
            
        inline void initPlaits()
        {
            BufferAllocator allocator(shared_buffer, 16384);
            voice.Init(&allocator);
            patch.note = 48.0f;

            modulations.note = 0.0f;
            modulations.engine = 0.0f;
            modulations.frequency = 0.0f;
            modulations.note = 0.0f;
            modulations.harmonics = 0.0f;
            modulations.morph = 0.0;
            modulations.level = 1.0f;
            modulations.trigger = 0.0f;
            modulations.frequency_patched = false;
            modulations.timbre_patched = false;
            modulations.morph_patched = false;
            modulations.trigger_patched = true;
            modulations.level_patched = false;            
        }

        void setPatchParameter(synthParameters parameter, float value)
        {
            switch (parameter) {
                case engine:
                    patch.engine = (int)value;
                    break;
                case note:
                    patch.note = value;
                    break;
                case harmonics:
                    patch.harmonics = value;
                    break;
                case timbre:
                    patch.timbre = value;
                    break;
                case morph:
                    patch.morph = value;
                    break;
                case frequencyModulationAmount:
                    patch.frequency_modulation_amount = value;
                    break;
                case timbreModulationAmount:
                    patch.timbre_modulation_amount = value;
                    break;
                case morphModulationAmount:
                    patch.morph_modulation_amount = value;
                    break;
                case decay:
                    patch.decay = value;
                    break;
                case lpgColour:
                    patch.lpg_colour = value;
                    break;
            }         
        }

        float getPatchParameter(synthParameters parameter)
        {
            switch (parameter) {
                case engine:
                    return patch.engine;
                case note:
                    return patch.note;
                case harmonics:
                    return patch.harmonics;
                case timbre:
                    return patch.timbre;
                case morph:
                    return patch.morph;
                case frequencyModulationAmount:
                    return patch.frequency_modulation_amount;
                case timbreModulationAmount:
                    return patch.timbre_modulation_amount;
                case morphModulationAmount:
                    return patch.morph_modulation_amount;
                case decay:
                    return patch.decay;
                case lpgColour:
                    return patch.lpg_colour;
                    break;
            }  
        }

        void setModulationsParameter(synthParameters parameter, float value)
        {
            switch (parameter) {
                case note:
                    modulations.note = value;
                    break;
                case engine:
                    modulations.engine = value;
                    break;
                case frequency:
                    modulations.frequency = value;
                    break;
                case harmonics:
                    modulations.harmonics = value;
                    break;
                case timbre:
                    modulations.timbre = value;
                    break;                    
                case morph:
                    modulations.morph = value;
                    break;
                case level:
                    modulations.level = value;
                    break;
                case trigger:
                    modulations.trigger = value;
                    break;
                case frequencyPatched:
                    modulations.frequency_patched = (bool)value;
                    break;
                case timbrePatched:
                    modulations.timbre_patched = (bool)value;
                    break;
                case morphPatched:
                    modulations.morph_patched = (bool)value;
                    break;
                case triggerPatched:
                    modulations.trigger_patched = (bool)value;
                    break;
                case levelPatched:
                    modulations.level_patched = (bool)value;
                    break;
            }
        }

        float getModulationsParameter(synthParameters parameter)
        {
            switch (parameter) {
                case note:
                    return modulations.note;
                case engine:
                    return modulations.engine;
                case frequency:
                    return modulations.frequency;
                case harmonics:
                    return modulations.harmonics;
                case morph:
                    return modulations.morph;
                case level:
                    return modulations.level;
                case trigger:
                    return modulations.trigger;
                case frequencyPatched:
                    return modulations.frequency_patched;
                case timbrePatched:
                    return (float)modulations.timbre_patched;
                case morphPatched:
                    return (float)modulations.morph_patched;
                case triggerPatched:
                    return (float)modulations.trigger_patched;
                case levelPatched:
                    return (float)modulations.level_patched;
                    break;
            }
        }

        virtual void update(void);

private:
        Modulations modulations;
        Patch patch;
        Voice voice;
        char shared_buffer[16384];        
        
};

#endif

#ifndef SYNTH_PLAITS_H_
#define SYNTH_PLAITS_H_

#include "core_pins.h"
#include "AudioStream.h"
#include "plaits/dsp/dsp.h"
#include "plaits/dsp/voice.h"
#include "stmlib/utils/buffer_allocator.h"

using namespace plaits;
using namespace stmlib;

class AudioSynthPlaits: public AudioStream
{
public:
        AudioSynthPlaits(): AudioStream(0, NULL)
        { initPlaits();	}
        ~AudioSynthPlaits() { }
      	
        inline void initPlaits(){
                BufferAllocator allocator(shared_buffer, 16384);
                voice.Init(&allocator);
        }

        virtual void update(void);

private:
        Modulations modulations;
        Patch patch;
        Voice voice;
        char shared_buffer[16384];        
        
};

#endif

#include "synth_plaits.h"
#include "plaits/dsp/dsp.h"
#include "plaits/dsp/voice.h"

using namespace plaits;
using namespace stmlib;

void AudioSynthPlaits::update(void)
{
	audio_block_t *block;
	uint8_t sync_buffer[AUDIO_BLOCK_SAMPLES]; 

	memset(sync_buffer, 0, sizeof(sync_buffer));
	block = allocate();
	if (block == NULL) return;

	Voice::Frame out[AUDIO_BLOCK_SAMPLES];
	voice.Render(patch, modulations, out, AUDIO_BLOCK_SAMPLES);
	for (int i=0; i<AUDIO_BLOCK_SAMPLES; i++) {
		block->data[i]=out[i].out;
	}
	transmit(block, 0);
	release(block);
	return;
}

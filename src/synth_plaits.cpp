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

	voice.Render(patch, modulations, (Voice::Frame*)(block->data), AUDIO_BLOCK_SAMPLES);
	transmit(block, 0);
	release(block);
	return;
}

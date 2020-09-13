#include "synth_plaits.h"
#include "plaits/dsp/dsp.h"
#include "plaits/dsp/voice.h"

using namespace plaits;
using namespace stmlib;

void AudioSynthPlaits::update(void)
{
	audio_block_t *blockOutMain;
	audio_block_t *blockOutAux;

	blockOutMain = allocate();
	blockOutAux = allocate();
	if (blockOutMain == NULL || blockOutAux == NULL) return;

	Voice::Frame out[AUDIO_BLOCK_SAMPLES];
	voice.Render(patch, modulations, out, AUDIO_BLOCK_SAMPLES);
	for (int i=0; i<AUDIO_BLOCK_SAMPLES; i++) {
		blockOutMain->data[i]=out[i].out;
		blockOutAux->data[i]=out[i].aux;
	}
	transmit(blockOutMain, 0);
	transmit(blockOutAux, 1);
	release(blockOutMain);
	release(blockOutAux);
	return;
}

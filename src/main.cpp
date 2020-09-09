//************LIBRARIES USED**************

#include "Wire.h"
#include "synth_plaits.h"
#include "SPI.h"
#include "Audio.h"

AudioSynthPlaits         synthPlaits;
AudioMixer4              mix1;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(synthPlaits, 0, mix1, 0);
AudioConnection          patchCord2(mix1, 0, i2s1, 0);
AudioConnection          patchCord3(mix1, 0, i2s1, 1);

AudioControlSGTL5000     sgtl5000_1;

IntervalTimer			myTimer;

// Handles note on events
void OnNoteOn(byte channel, byte note, byte velocity){
    // If the velocity is larger than zero, means that is turning on

}

void makeSomeNoise()
{
  Serial.println("Still alive");
}

//************SETUP**************
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(19200);

  // Configure the DACs
  AudioMemory(5);

  usbMIDI.setHandleNoteOn(OnNoteOn);
  myTimer.begin(makeSomeNoise, 10000);
}

//************LOOP**************
void loop() {
    usbMIDI.read();
}

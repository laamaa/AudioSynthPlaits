//************LIBRARIES USED**************

#include "Wire.h"
#include "synth_plaits.h"
#include "SPI.h"
#include "Audio.h"

AudioSynthPlaits         synthPlaits;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(synthPlaits, 0, i2s1, 0);
AudioConnection          patchCord2(synthPlaits, 0, i2s1, 1);

IntervalTimer			myTimer;

// Handles note on events
void OnNoteOn(byte channel, byte midinote, byte velocity){
    // If the velocity is larger than zero, means that is turning on
  if (velocity)
    synthPlaits.setPatchParameter(note,(float)midinote);
}

void testModulate(){
  if (synthPlaits.getModulationsParameter(trigger) == 0.0f) {
    synthPlaits.setModulationsParameter(trigger, 1.0f);
  } else {
    synthPlaits.setModulationsParameter(trigger,0.0f);
  }
}

//************SETUP**************
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(19200);

  // Configure the DACs
  AudioMemory(5);

  usbMIDI.setHandleNoteOn(OnNoteOn);
  myTimer.begin(testModulate,200000);

  synthPlaits.setPatchParameter(engine,0.0f);
}

//************LOOP**************
void loop() {
  usbMIDI.read();
}

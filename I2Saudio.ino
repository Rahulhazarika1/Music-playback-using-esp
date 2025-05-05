 #include "AudioGeneratorAAC.h"
#include "AudioOutputI2S.h"
#include "AudioFileSourcePROGMEM.h"
#include "sound1.h" // Should define sound_aac[] and sound_aac_len

AudioFileSourcePROGMEM *in;
AudioGeneratorAAC *aac;
AudioOutputI2S *out;

void setup() {
  Serial.begin(115200);

  in = new AudioFileSourcePROGMEM(sound_wav, sound_wav_len);
  aac = new AudioGeneratorAAC();
  out = new AudioOutputI2S();
  out->SetGain(0.125);
  out->SetPinout(26, 25, 22);

  aac->begin(in, out);
}

void loop() {
  if (aac->isRunning()) {
    aac->loop();
  } else {
    aac->stop();
    Serial.println("Playback finished");
    delay(1000);
    // Uncomment below to loop the audio
    // aac->begin(in, out);
  }
}

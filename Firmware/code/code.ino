#include <BleKeyboard.h>

BleKeyboard bleKb("MediaPad", "DIY", 100);

const int btnPlay = 13, btnNext = 12, btnPrev = 14;
const int encCLK = 27, encDT = 26, encSW = 25;
int lastCLK;

void setup() {
  bleKb.begin();
  pinMode(btnPlay, INPUT_PULLUP);
  pinMode(btnNext, INPUT_PULLUP);
  pinMode(btnPrev, INPUT_PULLUP);
  pinMode(encCLK, INPUT_PULLUP);
  pinMode(encDT, INPUT_PULLUP);
  pinMode(encSW, INPUT_PULLUP);
  lastCLK = digitalRead(encCLK);
}

void loop() {
  if (!bleKb.isConnected()) return;

  if (!digitalRead(btnPlay)) { bleKb.write(KEY_MEDIA_PLAY_PAUSE); delay(300); }
  if (!digitalRead(btnNext)) { bleKb.write(KEY_MEDIA_NEXT_TRACK); delay(300); }
  if (!digitalRead(btnPrev)) { bleKb.write(KEY_MEDIA_PREVIOUS_TRACK); delay(300); }

  int curCLK = digitalRead(encCLK);
  if (curCLK != lastCLK && curCLK == 0) {
    if (digitalRead(encDT) != curCLK)
      bleKb.write(KEY_MEDIA_VOLUME_UP);
    else
      bleKb.write(KEY_MEDIA_VOLUME_DOWN);
    delay(50);
  }
  lastCLK = curCLK;

  if (!digitalRead(encSW)) { bleKb.write(KEY_MEDIA_MUTE); delay(300); }
}
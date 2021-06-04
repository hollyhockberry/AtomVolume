// AtomVolume
// BLE volume controller
//
// Copyright (c) 2021 Inaba

#include <M5Atom.h>
#include <BleKeyboard.h>
#include "chatterremover.h"

namespace {
BleKeyboard bleyKeyBoard("AtomVolume");

ChatterRemover A(21);
ChatterRemover B(25);
ChatterRemover SW(33);
int lastA;
int lastSW;

// Detection of pushdown edge
bool isPressSW() {
  const auto curr = SW.read();
  if (lastSW != curr) {
    lastSW = curr;
    return lastSW == LOW;
  }
  return false;
}
}  // namespace

void setup() {
  bleyKeyBoard.begin();
  A.begin();
  B.begin();
  SW.begin();
  lastA = A.read();
  lastSW = SW.read();
}

void loop() {
  if (bleyKeyBoard.isConnected()) {
    const auto a = A.read();
    const auto b = B.read();
    if (a != lastA) {
      const auto cw = b != a;
      lastA = a;
      bleyKeyBoard.write(cw ? KEY_MEDIA_VOLUME_UP : KEY_MEDIA_VOLUME_DOWN);
    }
    if (isPressSW()) {
      bleyKeyBoard.write(KEY_MEDIA_MUTE);
    }
  }
}

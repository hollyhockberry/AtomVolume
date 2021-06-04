// AtomVolume
// BLE volume controller
//
// Copyright (c) 2021 Inaba

#include <M5Atom.h>
#include <BleKeyboard.h>
#include "chatterremover.h"
#include "keys.h"

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

int mode = 0;
}  // namespace

void setup() {
  M5.begin(true, false, true);
  M5.dis.begin(1);
  bleyKeyBoard.begin();
  A.begin();
  B.begin();
  SW.begin();
  lastA = A.read();
  lastSW = SW.read();
}

void loop() {
  M5.update();
  if (M5.Btn.wasPressed()) {
    mode = (mode + 1) % IKeys::Keys();
  }

  if (bleyKeyBoard.isConnected()) {
    auto keys = IKeys::KeyTable()[mode];
    const auto a = A.read();
    const auto b = B.read();
    if (a != lastA) {
      const auto cw = b != a;
      lastA = a;
      cw ? keys->CW(&bleyKeyBoard) : keys->CCW(&bleyKeyBoard);
    }
    if (isPressSW()) {
      keys->Switch(&bleyKeyBoard);
    }
  }
}

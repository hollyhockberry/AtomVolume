// Copyright (c) 2021 Inaba

#include "chatterremover.h"
#include <M5Atom.h>

ChatterRemover::ChatterRemover(int port)
: port(port), changedTime(0), last() {
}

void ChatterRemover::begin() {
  changedTime = 0;
  ::pinMode(port, INPUT_PULLUP);
  last = ::digitalRead(port);
}

int ChatterRemover::read() {
  int curr = ::digitalRead(port);

  if (changedTime <= 0) {
    if (curr != last) {
      changedTime = ::millis();
    }
  } else if ((::millis() - changedTime) >= 5) {
    if (curr != last) {
      last = curr;
    }
    changedTime = 0;
  }
  return last;
}

// Copyright (c) 2021 Inaba

#ifndef KEYS_H_
#define KEYS_H_

#include <BleKeyboard.h>
#include <M5Atom.h>

class IKeys {
 public:
  virtual void CW(BleKeyboard* key) const = 0;
  virtual void CCW(BleKeyboard* key) const = 0;
  virtual void Switch(BleKeyboard* key) const = 0;
  virtual void Show(LED_DisPlay* dis) const = 0;

  static size_t Keys();
  static IKeys** KeyTable();
};

#endif  // KEYS_H_

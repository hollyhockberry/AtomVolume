// Copyright (c) 2021 Inaba

#include "keys.h"

class VolumeKeys : public IKeys {
 public:
  void CW(BleKeyboard* key) const override {
    key->write(KEY_MEDIA_VOLUME_UP);
  }
  void CCW(BleKeyboard* key) const override {
    key->write(KEY_MEDIA_VOLUME_DOWN);
  }
  void Switch(BleKeyboard* key) const override {
    key->write(KEY_MEDIA_MUTE);
  }
  void Show(LED_DisPlay* dis) const override {
    dis->drawpix(0, 0xff0000);
  }
};

class MediaKeys : public IKeys {
 public:
  void CW(BleKeyboard* key) const override {
    key->write(KEY_MEDIA_NEXT_TRACK);
  }
  void CCW(BleKeyboard* key) const override {
    key->write(KEY_MEDIA_PREVIOUS_TRACK);
  }
  void Switch(BleKeyboard* key) const override {
    key->write(KEY_MEDIA_PLAY_PAUSE);
  }
  void Show(LED_DisPlay* dis) const override {
    dis->drawpix(0, 0xff00);
  }
};

class YoutubeKeys : public IKeys {
 public:
  void CW(BleKeyboard* key) const override {
    key->write(KEY_RIGHT_ARROW);
  }
  void CCW(BleKeyboard* key) const override {
    key->write(KEY_LEFT_ARROW);
  }
  void Switch(BleKeyboard* key) const override {
    key->write(' ');
  }
  void Show(LED_DisPlay* dis) const override {
    dis->drawpix(0, 0xff);
  }
};

namespace {
IKeys* table[] = {
  new VolumeKeys(),
  new MediaKeys(),
  new YoutubeKeys(),
};

template <typename T, std::size_t N>
std::size_t sizeofarray(const T (&)[N]) {
  return N;
}
}  // namespace

size_t IKeys::Keys() {
  return sizeofarray(table);
}

IKeys** IKeys::KeyTable() {
  return table;
}

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

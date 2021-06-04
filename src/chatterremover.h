// Copyright (c) 2021 Inaba

#ifndef CHATTERREMOVER_H_
#define CHATTERREMOVER_H_

class ChatterRemover {
  const int port;
  unsigned int changedTime;
  int last;
 public:
  explicit ChatterRemover(int port);

  void begin();
  int read();
 private:
  ChatterRemover(const ChatterRemover&);
  void operator=(const ChatterRemover&);
};

#endif  // CHATTERREMOVER_H_

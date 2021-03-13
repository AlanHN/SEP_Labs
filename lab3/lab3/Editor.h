#pragma once

#include <string>
#include "ListBuffer.h"

class Editor {
private:
  ListBuffer *buffer;
  void dispatchCmd(const string &cmd);
public:
  Editor();
  ~Editor();
  void run();
};

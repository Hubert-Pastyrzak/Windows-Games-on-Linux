#include "display.h"

Display* _defaultDisplay = NULL;

Display* defaultDisplay() {
  if (!_defaultDisplay) {
    _defaultDisplay = XOpenDisplay(NULL);
  }

  return _defaultDisplay;
}

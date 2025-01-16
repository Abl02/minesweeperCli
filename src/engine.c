#include "engine.h"

void selectRenderType(renderType type) { RENDER_TYPE = type; }

void toggleMouse() { mouse = !mouse; }

void setup() {
  // SETUP ENGINE MODULES AND ENV
}

int run() {
  running = true;
  while (running) {
    // DO STUFF
    running = false;
  }
  return 0;
}

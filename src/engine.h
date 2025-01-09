#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>

typedef enum {
  Static,
  Continious
} renderType;

extern const renderType RENDER_TYPE;

extern bool running;
extern bool mouse;

void selectRenderType(renderType);
void enableMouse();

void setup();

int run();

#endif

#ifndef ENGINE_H
#define ENGINE_H

#include <stdbool.h>

typedef enum {
  Static,
  Continious
} renderType;

extern renderType RENDER_TYPE;

extern bool running;
extern bool mouse;

/*
 * Select the type of render
 * @param type: the type to select (Static, Continious)
 */
void selectRenderType(renderType type);

/*
 * toggle mouse
 */
void toggleMouse();

/*
 * Setup Engine modules, and environment
 */
void setup();

/*
 * Start game loop
 * @return: an int status code
 */
int run();

#endif

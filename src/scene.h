#ifndef SCENE_H
#define SCENE_H

#include "node.h"
#include <stdlib.h>

typedef struct {
  int score;
  char* header;
} Meta;

typedef struct {
  Node *data;
  size_t size;
  size_t capacity;
} ActiveNodes;

void initActiveNodes();

#endif

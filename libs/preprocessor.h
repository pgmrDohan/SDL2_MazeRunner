#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 600

#define FONT TTF_OpenFont("../resources/ark-pixel.bdf", 10)
#include "SDL_Colors.h"

#define CHECK_ERROR(test, message)        \
  do {                                    \
    if ((test)) {                         \
      fprintf(stderr, "%s\n", (message)); \
      exit(1);                            \
    }                                     \
  } while (0)
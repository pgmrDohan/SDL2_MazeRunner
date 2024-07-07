#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define Malloc(t) (t *)malloc(sizeof(t))
#define Max(a, b) (a > b) ? a : b
#define Min(a, b) (a < b) ? a : b

#define grid_cell_size 40
#define grid_width 25
#define grid_height 15
#define WIDTH (grid_width * grid_cell_size) + 20
#define HEIGHT (grid_height * grid_cell_size) + 40
#define nbOfCells (grid_width * grid_height)

#define TITLE_FONT TTF_OpenFont("../resources/MooseNooks.bdf", 30)
#define FONT TTF_OpenFont("../resources/ark-pixel.bdf", 16)

#define CHECK_ERROR(test, message)        \
  do {                                    \
    if ((test)) {                         \
      fprintf(stderr, "%s\n", (message)); \
      exit(1);                            \
    }                                     \
  } while (0)

typedef struct {
  int posX;
  int posY;
} cell;

#include "./SDL_Circle.h"
#include "./SDL_Colors.h"
#include "./SDL_Inits.h"
#include "./SDL_Text.h"
//
#include "./Stack.h"
//
#include "./MAZE_Generater.h"
#include "./MAZE_Init.h"
#include "./MAZE_SelectMenu.h"
#include "./MAZE_Selects.h"
#include "./MAZE_Texts.h"
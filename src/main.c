#include "../libs/preprocessor.h"

int main(int argc, char **argv) {
  SDL_Inits();
  TTF_Init();

  SDL_Window *window = SDL_CreateMazeRunnerWindow();
  SDL_Renderer *renderer = SDL_CreateMazeRunnerRenderer(window);

  MazeRunnerTitle *logo = MAZE_SetTitle(renderer);
  MazeRunnerHelp *manual = MAZE_SetHelp(renderer);

  SDL_Rect Main_rect = {10, 10, 980, 550};

  bool running = true;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        running = false;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 10, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &Main_rect);

    MAZE_RenderTitle(renderer, logo);
    MAZE_RenderHelp(renderer, manual);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  MAZE_DestroyTitle(logo);
  MAZE_DestroyHelp(manual);
  TTF_Quit();
  SDL_Quit();

  return 0;
}
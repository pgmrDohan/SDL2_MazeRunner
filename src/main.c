#include "../libs/preprocessor.h"

int main(int argc, char **argv) {
  SDL_Inits();
  TTF_Init();

  SDL_Window *window = SDL_CreateMazeRunnerWindow();
  SDL_Renderer *renderer = SDL_CreateMazeRunnerRenderer(window);

  MazeRunnerTitle *logo = MAZE_SetTitle(renderer);
  MazeRunnerHelp *manual = MAZE_SetHelp(renderer);

  int gameSatus = 0;
  /*
  0: Ready
  1: Generate
  2: Solve
  */

  int activeSelectMenu = 0;
  /*
  0: "Generate now", "Exit"
  1: "Solve now", "Exit"
  2: "DFS", "BFS", "Prim's", "Kruskal's"
  3: "DFS", "BFS", "Dijkstra's", "A*", "Left-hand rule", "Right-hand rule"
  */

  int generateOpt = -1;
  /*
  0: "DFS"
  1: "BFS"
  2: "Prim's"
  3: "Kruskal's"
  */

  int solveOpt = -1;
  /*
  0: "DFS"
  1: "BFS"
  2: "Dijkstra's"
  3: "A*"
  4: "Left-hand rule"
  5: "Right-hand rule"
  */

  MazeRunnerSelectMenu *firstSelects =
      MAZE_SetSelectMenu(renderer, (char **)SEL_FIRST, LEN_FIRST);
  MazeRunnerSelectMenu *todo =
      MAZE_SetSelectMenu(renderer, (char **)SEL_TO_DO, LEN_TO_DO);
  MazeRunnerSelectMenu *generateOpts = MAZE_SetSelectMenu(
      renderer, (char **)SEL_GENRERATE_OPT, LEN_GENRERATE_OPT);
  MazeRunnerSelectMenu *solveOpts =
      MAZE_SetSelectMenu(renderer, (char **)SEL_SOLVE_OPT, LEN_SOLVE_OPT);

  SDL_Rect Main_rect = {10, 10, 980, 550};

  bool running = true;
  SDL_Event event;
  while (running) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_KEYUP:
          switch (event.key.keysym.sym) {
            case SDLK_1:
              if (activeSelectMenu == 0) {
                activeSelectMenu = 2;
              } else if (activeSelectMenu == 1) {
                activeSelectMenu = 3;
              } else {
                generateOpt = 0;
                solveOpt = 0;
                if (activeSelectMenu == 2) {
                  gameSatus = 1;
                  activeSelectMenu = 1;
                }
                if (activeSelectMenu == 3) {
                  gameSatus = 2;
                  activeSelectMenu = 0;
                }
              }
              break;
            case SDLK_2:
              if (activeSelectMenu == 0 || activeSelectMenu == 1) {
                running = false;
              } else {
                generateOpt = 1;
                solveOpt = 1;
                if (activeSelectMenu == 2) {
                  gameSatus = 1;
                  activeSelectMenu = 1;
                }
                if (activeSelectMenu == 3) {
                  gameSatus = 2;
                  activeSelectMenu = 0;
                }
              }
              break;
            case SDLK_3:
              generateOpt = 2;
              solveOpt = 2;
              if (activeSelectMenu == 2) {
                gameSatus = 1;
                activeSelectMenu = 1;
              }
              if (activeSelectMenu == 3) {
                gameSatus = 2;
                activeSelectMenu = 0;
              }
              break;
            case SDLK_4:
              if (activeSelectMenu == 2) {
                generateOpt = 3;
                gameSatus = 1;
                activeSelectMenu = 1;
              }
              if (activeSelectMenu == 3) {
                solveOpt = 3;
                gameSatus = 2;
                activeSelectMenu = 0;
              }
              break;
            case SDLK_5:
              if (activeSelectMenu == 3) solveOpt = 4;
              gameSatus = 2;
              activeSelectMenu = 0;
              break;
            case SDLK_6:
              if (activeSelectMenu == 3) solveOpt = 5;
              gameSatus = 2;
              activeSelectMenu = 0;
              break;
            default:
              break;
          }
          break;
        case SDL_QUIT:
          running = false;
          break;
        default:
          break;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 10, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &Main_rect);

    if (activeSelectMenu == 0)
      MAZE_RenderSelectMenu(renderer, firstSelects);
    else if (activeSelectMenu == 1)
      MAZE_RenderSelectMenu(renderer, todo);
    else if (activeSelectMenu == 2)
      MAZE_RenderSelectMenu(renderer, generateOpts);
    else if (activeSelectMenu == 3)
      MAZE_RenderSelectMenu(renderer, solveOpts);

    switch (gameSatus) {
      case 0:
        MAZE_RenderTitle(renderer, logo);
        MAZE_RenderHelp(renderer, manual);
        break;
      case 1:
        printf("%d", generateOpt);
        break;
      case 2:
        printf("%d", solveOpt);
        break;
      default:
        break;
    }

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  MAZE_DestroyTitle(logo);
  MAZE_DestroyHelp(manual);
  MAZE_DestroySelectMenu(firstSelects);
  MAZE_DestroySelectMenu(todo);
  MAZE_DestroySelectMenu(generateOpts);
  MAZE_DestroySelectMenu(solveOpts);
  TTF_Quit();
  SDL_Quit();

  return 0;
}
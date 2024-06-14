typedef struct MazeRunnerTitle {
  SDL_Text *title;
  SDL_Text *secondline;
  SDL_Text *titleShadow;
  SDL_Text *secondlineShadow;
} MazeRunnerTitle;

typedef struct MazeRunnerHelp {
  SDL_Text *firstline;
  SDL_Text *secondline;
} MazeRunnerHelp;

MazeRunnerTitle *MAZE_SetTitle(SDL_Renderer *renderer) {
  SDL_Text *title = SDL_CreateTextRect(renderer, "Maze", SDL_CYAN, 0, 90);
  title->TextRect.w = title->TextRect.w * 150 / title->TextRect.h;
  title->TextRect.h = 150;
  title->TextRect.x = (WIDTH / 2) - (title->TextRect.w / 2);

  SDL_Text *secondline =
      SDL_CreateTextRect(renderer, "Runner", SDL_CYAN, 0, 180);
  secondline->TextRect.w =
      secondline->TextRect.w * 150 / secondline->TextRect.h;
  secondline->TextRect.h = 150;
  secondline->TextRect.x = (WIDTH / 2) - (secondline->TextRect.w / 2);

  SDL_Text *titleShadow =
      SDL_CreateTextRect(renderer, "Maze", (SDL_Color){0, 255, 255, 100},
                         title->TextRect.x + 3, title->TextRect.y + 3);
  titleShadow->TextRect.w = title->TextRect.w;
  titleShadow->TextRect.h = title->TextRect.h;

  SDL_Text *secondlineShadow = SDL_CreateTextRect(
      renderer, "Runner", (SDL_Color){0, 255, 255, 100},
      secondline->TextRect.x + 3, secondline->TextRect.y + 3);
  secondlineShadow->TextRect.w = secondline->TextRect.w;
  secondlineShadow->TextRect.h = secondline->TextRect.h;

  MazeRunnerTitle *logo = (MazeRunnerTitle *)malloc(sizeof(MazeRunnerTitle));
  logo->title = title;
  logo->titleShadow = titleShadow;
  logo->secondline = secondline;
  logo->secondlineShadow = secondlineShadow;

  return logo;
}

void MAZE_RenderTitle(SDL_Renderer *renderer, MazeRunnerTitle *logo) {
  SDL_RenderCopy(renderer, logo->titleShadow->Text, NULL,
                 &logo->titleShadow->TextRect);
  SDL_RenderCopy(renderer, logo->title->Text, NULL, &logo->title->TextRect);
  SDL_RenderCopy(renderer, logo->secondlineShadow->Text, NULL,
                 &logo->secondlineShadow->TextRect);
  SDL_RenderCopy(renderer, logo->secondline->Text, NULL,
                 &logo->secondline->TextRect);
}

void MAZE_DestroyTitle(MazeRunnerTitle *logo) {
  SDL_DestroyTexture(logo->title->Text);
  SDL_DestroyTexture(logo->titleShadow->Text);
  SDL_DestroyTexture(logo->secondline->Text);
  SDL_DestroyTexture(logo->secondlineShadow->Text);
}

MazeRunnerHelp *MAZE_SetHelp(SDL_Renderer *renderer) {
  SDL_Text *firstline =
      SDL_CreateTextRect(renderer,
                         "[──] In Below Menu, You can use Arrow Key to move "
                         "cursor and Enter Key to select.",
                         SDL_WHITE, 0, 500);
  firstline->TextRect.w = firstline->TextRect.w * 25 / firstline->TextRect.h;
  firstline->TextRect.h = 25;
  firstline->TextRect.x = (WIDTH / 2) - (firstline->TextRect.w / 2);

  SDL_Text *secondline = SDL_CreateTextRect(
      renderer, "[──] https://github.com/pgmrDohan/SDL2_MazeRunner", SDL_WHITE,
      0, 524);
  secondline->TextRect.w = secondline->TextRect.w * 25 / secondline->TextRect.h;
  secondline->TextRect.h = 25;
  secondline->TextRect.x = firstline->TextRect.x;

  MazeRunnerHelp *manual = (MazeRunnerHelp *)malloc(sizeof(MazeRunnerHelp));
  manual->firstline = firstline;
  manual->secondline = secondline;

  return manual;
}

void MAZE_RenderHelp(SDL_Renderer *renderer, MazeRunnerHelp *manual) {
  SDL_RenderCopy(renderer, manual->firstline->Text, NULL,
                 &manual->firstline->TextRect);
  SDL_RenderCopy(renderer, manual->secondline->Text, NULL,
                 &manual->secondline->TextRect);
}

void MAZE_DestroyHelp(MazeRunnerHelp *logo) {
  SDL_DestroyTexture(logo->firstline->Text);
  SDL_DestroyTexture(logo->secondline->Text);
}
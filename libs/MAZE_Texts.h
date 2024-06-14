typedef struct MazeRunnerTitle {
  SDL_Text *title;
  SDL_Text *titleShadow;
} MazeRunnerTitle;

MazeRunnerTitle *MAZE_SetTitle(SDL_Renderer *renderer) {
  SDL_Text *title =
      SDL_CreateTextRect(renderer, "Maze Runner", SDL_CYAN, 0, 40);
  title->TextRect.w = title->TextRect.w * 100 / title->TextRect.h;
  title->TextRect.h = 100;
  title->TextRect.x = (WIDTH / 2) - (title->TextRect.w / 2);

  SDL_Text *titleShadow =
      SDL_CreateTextRect(renderer, "Maze Runner", (SDL_Color){0, 255, 255, 100},
                         title->TextRect.x + 3, title->TextRect.y + 3);
  titleShadow->TextRect.w = title->TextRect.w;
  titleShadow->TextRect.h = title->TextRect.h;

  MazeRunnerTitle *logo = (MazeRunnerTitle *)malloc(sizeof(MazeRunnerTitle));
  logo->title = title;
  logo->titleShadow = titleShadow;

  return logo;
}

void MAZE_RenderTitle(SDL_Renderer *renderer, MazeRunnerTitle *logo) {
  SDL_RenderCopy(renderer, logo->titleShadow->Text, NULL,
                 &logo->titleShadow->TextRect);
  SDL_RenderCopy(renderer, logo->title->Text, NULL, &logo->title->TextRect);
}

void MAZE_DestroyTitle(MazeRunnerTitle *logo) {
  SDL_DestroyTexture(logo->title->Text);
  SDL_DestroyTexture(logo->titleShadow->Text);
}
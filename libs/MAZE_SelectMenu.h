typedef struct MazeRunnerSelectMenu {
  SDL_Text *select;
} MazeRunnerSelectMenu;

char itoc(int foo) {
  char bar;
  SDL_itoa(foo, &bar, 10);
  return bar;
}

MazeRunnerSelectMenu *MAZE_SetSelectMenu(SDL_Renderer *renderer, char **selects,
                                         int len) {
  int selectStrLen = 0;
  for (int i = 0; i < len; i++) {
    selectStrLen += strlen(selects[i]) + 7;
  }
  char *selectStr = (char *)malloc(sizeof(char) * selectStrLen);
  int selectStrI = 0;
  for (int i = 0; i < len; i++) {
    selectStr[selectStrI++] = '(';
    selectStr[selectStrI++] = itoc(i + 1);
    selectStr[selectStrI++] = ')';
    selectStr[selectStrI++] = ' ';
    for (int j = 0; selects[i][j]; j++) {
      selectStr[selectStrI++] = selects[i][j];
    }
    selectStr[selectStrI++] = ' ';
    selectStr[selectStrI++] = '|';
    selectStr[selectStrI++] = ' ';
  }
  selectStr[selectStrI++] = '\0';
  SDL_Text *select = SDL_CreateTextRect(renderer, selectStr, SDL_WHITE,
                                        TTF_STYLE_NORMAL, 0, 560);
  select->TextRect.w = select->TextRect.w * 25 / select->TextRect.h;
  select->TextRect.h = 25;
  select->TextRect.x = 10;
  MazeRunnerSelectMenu *selectMenu =
      (MazeRunnerSelectMenu *)malloc(sizeof(MazeRunnerSelectMenu));
  selectMenu->select = select;

  return selectMenu;
}

void MAZE_RenderSelectMenu(SDL_Renderer *renderer,
                           MazeRunnerSelectMenu *selectMenu) {
  SDL_RenderCopy(renderer, selectMenu->select->Text, NULL,
                 &selectMenu->select->TextRect);
}

void MAZE_DestroySelectMenu(MazeRunnerSelectMenu *selectMenu) {
  SDL_DestroyTexture(selectMenu->select->Text);
}
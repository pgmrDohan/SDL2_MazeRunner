void SDL_Inits() {
  CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
}

SDL_Window* SDL_CreateMazeRunnerWindow() {
  SDL_Window* window = SDL_CreateWindow(
      "Maze Runner @Dohan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_GRABBED);
  CHECK_ERROR(window == NULL, SDL_GetError());

  SDL_Surface* icon;
  icon = IMG_Load("resources/icon.png");
  SDL_SetWindowIcon(window, icon);
  SDL_SetWindowOpacity(window, 0.8);

  return window;
}

SDL_Renderer* SDL_CreateMazeRunnerRenderer(SDL_Window* window) {
  SDL_Renderer* renderer =
      SDL_CreateRenderer(window, -1,
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC |
                             SDL_RENDERER_TARGETTEXTURE);
  CHECK_ERROR(renderer == NULL, SDL_GetError());

  return renderer;
}
#include "../libs/preprocessor.h"

int main(int argc, char **argv) {
  CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());

  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
  SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

  SDL_Window *window = SDL_CreateWindow(
      "Maze Runner @Dohan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
      WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_GRABBED);
  CHECK_ERROR(window == NULL, SDL_GetError());

  SDL_Surface *icon;
  icon = IMG_Load("resources/icon.png");
  SDL_SetWindowIcon(window, icon);
  SDL_SetWindowOpacity(window, 0.8);

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1,
                         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC |
                             SDL_RENDERER_TARGETTEXTURE);
  CHECK_ERROR(renderer == NULL, SDL_GetError());

  TTF_Init();

  SDL_Surface *surfaceMessage =
      TTF_RenderUTF8_Blended(FONT, "Maze Runner", SDL_WHITE);
  SDL_Texture *Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
  SDL_Rect Message_rect = {100, 10, 0, 0};
  TTF_SizeText(FONT, "Maze Runner", &Message_rect.w, &Message_rect.h);
  Message_rect.w = Message_rect.w * 100 / Message_rect.h;
  Message_rect.h = 100;
  SDL_FreeSurface(surfaceMessage);

  SDL_Rect Main_rect;
  Main_rect.x = 10;
  Main_rect.y = 10;
  Main_rect.w = 980;
  Main_rect.h = 560;

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
    SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_DestroyTexture(Message);
  TTF_Quit();
  SDL_Quit();

  return 0;
}
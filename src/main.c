#include "../libs/preprocessor.h"

static const int width = 1000;
static const int height = 600;

int main(int argc, char **argv) {
    CHECK_ERROR(SDL_Init(SDL_INIT_VIDEO) != 0, SDL_GetError());

    SDL_Window *window = SDL_CreateWindow(
        "Maze Runner @Dohan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,
        height, SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_GRABBED);
    CHECK_ERROR(window == NULL, SDL_GetError());

    SDL_SetWindowOpacity(window, 0.8);

    SDL_Surface* icon;
    icon = IMG_Load("resources/icon.png");
    SDL_SetWindowIcon(window,icon);

    SDL_Renderer *renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
    CHECK_ERROR(renderer == NULL, SDL_GetError());

    TTF_Init();
    TTF_Font* Sans = TTF_OpenFont("resources/terminal.ttf", 15);
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "Maze Runner", (SDL_Color){255,255,255}); 
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect Text_rect;
    Text_rect.x = 0;
    Text_rect.y = 0;
    TTF_SizeText(Sans, "Maze Runner", &Text_rect.w, &Text_rect.h);
    SDL_FreeSurface(surfaceMessage);

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

        SDL_RenderCopy(renderer, Message, NULL, &Text_rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(Message);
    SDL_Quit();

    return 0;
}
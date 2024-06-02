#include "./libs/preprocessor.h"

static int sel = 0;
static SDL_Window* window;
static SDL_Renderer* renderer;
static int* size;
static bool isGenerated = false;

int WINAPI tf(LPVOID a) {
    window = SDL_CreateWindow(SEL_GENRERATE_OPT[sel], SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, size[0], size[1],
                              SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    isGenerated = false;
    return 0;
}

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    while (1) {
        if (!isGenerated) {
            sel = selectMenu(SEL_FIRST, LEN_FIRST, DISC_FIRST);
            if (sel == 1) break;
        } else {
            sel = selectMenu(SEL_TO_DO, LEN_TO_DO, DISC_TO_DO);
            if (sel == 2) break;
        }

        if (sel == 0) {
            if (isGenerated) {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
            }
            isGenerated = true;
            int* size = selectSize();
            sel = selectMenu(SEL_GENRERATE_OPT, LEN_GENRERATE_OPT,
                             DISC_GENRERATE_OPT);
            int threadid;
            HANDLE threadHandle1;
            threadHandle1 = CreateThread(NULL, 0, tf, NULL, 0, &threadid);
        } else if (sel == 1) {
            // solve
        } else {
            break;
        }
    }
    return 0;
}
#include <SDL2/SDL.h>

int MAZE_GENERATE_DFS(SDL_Renderer *renderer, int width, int height) {
    return SDL_RenderDrawLine(renderer, 0, 0, width, height);
}

int MAZE_GENERATE_BFS(SDL_Renderer *renderer, int width, int height) {
    return SDL_RenderDrawLine(renderer, 0, 0, width, height);
}

int MAZE_GENERATE_PRIM(SDL_Renderer *renderer, int width, int height) {
    return SDL_RenderDrawLine(renderer, 0, 0, width, height);
}

int MAZE_GENERATE_KRUSKAL(SDL_Renderer *renderer, int width, int height) {
    return SDL_RenderDrawLine(renderer, 0, 0, width, height);
}

int MAZE_RENDER(SDL_Renderer *renderer, int width, int height) {
    return SDL_RenderDrawLine(renderer, width, 0, 0, height);
}
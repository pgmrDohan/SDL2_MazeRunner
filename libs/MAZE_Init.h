void initGrid(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  for (int x = 10; x < WIDTH - 10; x += grid_cell_size)
    SDL_RenderDrawLine(renderer, x, 10, x, HEIGHT - 32);

  for (int y = 10; y < HEIGHT - 30; y += grid_cell_size)
    SDL_RenderDrawLine(renderer, 10, y, WIDTH - 12, y);

  /***** Starting cell *****/
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderFillCircle(renderer, 10 + grid_cell_size / 2,
                       10 + grid_cell_size / 2, grid_cell_size / 4);

  // /***** Terminal cell *****/
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
  SDL_RenderFillCircle(renderer, WIDTH - 10 - grid_cell_size / 2,
                       HEIGHT - 30 - grid_cell_size / 2, grid_cell_size / 4);
}
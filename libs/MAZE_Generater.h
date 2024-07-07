/***** DFS *****/
int erasedWall[nbOfCells][4];
int s_erasedWall = 0;
SDL_bool adjacencyMatrix[nbOfCells][nbOfCells];
SDL_bool visited[grid_width + 2][grid_height + 2];
Stack *stack = NULL;
cell *Cell = NULL;

void wallErase(SDL_Renderer *renderer) {
  for (int i = 0; i < s_erasedWall - 1; i++) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 10, 255);
    SDL_RenderDrawLine(renderer, erasedWall[i][0], erasedWall[i][1],
                       erasedWall[i][2], erasedWall[i][3]);
  }
}

void initMaze() {
  for (int i = 1; i <= grid_width; i++)
    for (int j = 1; j <= grid_height; j++) visited[i][j] = SDL_FALSE;
  for (int j = 0; j < grid_height + 2; j++) {
    visited[0][j] = SDL_TRUE;
    visited[grid_width + 1][j] = SDL_TRUE;
  }
  for (int i = 1; i <= grid_width; i++) {
    visited[i][0] = SDL_TRUE;
    visited[i][grid_height + 1] = SDL_TRUE;
  }
  for (int i = 0; i < nbOfCells; i++)
    for (int j = 0; j < nbOfCells; j++) adjacencyMatrix[i][j] = SDL_FALSE;

  for (int i = 0; i < nbOfCells; i++)
    for (int j = 1; j <= 4; j++) erasedWall[i][j] = -1;
  s_erasedWall = 0;

  stack = initStack();
  srand(time(NULL));
}

cell *cellNeighbour(cell *Cell) {
  cell *neighbour = Malloc(cell);
  cell *nullCell = NULL;

  if ((visited[Cell->posX - 1][Cell->posY] == SDL_TRUE) &&
      (visited[Cell->posX][Cell->posY - 1] == SDL_TRUE) &&
      (visited[Cell->posX][Cell->posY + 1] == SDL_TRUE) &&
      (visited[Cell->posX + 1][Cell->posY] == SDL_TRUE))
    return nullCell;

  do {
    int randomNeighbour = (rand() % 4) + 1;
    switch (randomNeighbour) {
      case 1:
        neighbour->posX = Cell->posX - 1;
        neighbour->posY = Cell->posY;
        break;
      case 2:
        neighbour->posX = Cell->posX;
        neighbour->posY = Cell->posY - 1;
        break;
      case 3:
        neighbour->posX = Cell->posX;
        neighbour->posY = Cell->posY + 1;
        break;
      case 4:
        neighbour->posX = Cell->posX + 1;
        neighbour->posY = Cell->posY;
        break;
    }
  } while (visited[neighbour->posX][neighbour->posY] == SDL_TRUE);

  return neighbour;
}

void removeWall(cell *Cell, cell *neighbour) {
  if (Cell->posX == neighbour->posX) {
    int posY = Max(Cell->posY, neighbour->posY);
    erasedWall[s_erasedWall][0] = (Cell->posX - 1) * grid_cell_size + 10 + 1;
    erasedWall[s_erasedWall][1] = (posY - 1) * grid_cell_size + 10;
    erasedWall[s_erasedWall][2] = (Cell->posX) * grid_cell_size + 10 - 1;
    erasedWall[s_erasedWall++][3] = (posY - 1) * grid_cell_size + 10;
  }

  else if (Cell->posY == neighbour->posY) {
    int posX = Max(Cell->posX, neighbour->posX);
    erasedWall[s_erasedWall][0] = (posX - 1) * grid_cell_size + 10;
    erasedWall[s_erasedWall][1] = (Cell->posY - 1) * grid_cell_size + 10 + 1;
    erasedWall[s_erasedWall][2] = (posX - 1) * grid_cell_size + 10;
    erasedWall[s_erasedWall++][3] = (Cell->posY) * grid_cell_size + 10 - 1;
  }

  // SDL_Delay(30);
}

void adjacency(cell *Cell, cell *cellNeighbour) {
  int cellPos = (Cell->posX - 1) * grid_height + (Cell->posY - 1);
  int neighbourPos =
      (cellNeighbour->posX - 1) * grid_height + (cellNeighbour->posY - 1);
  adjacencyMatrix[cellPos][neighbourPos] = SDL_TRUE;
  adjacencyMatrix[neighbourPos][cellPos] = SDL_TRUE;
}

/***** GLOBAL *****/
void init_Generater() {
  // DFS
  initMaze();
  Cell = Malloc(cell);
  Cell->posX = 1;
  Cell->posY = 1;
  visited[Cell->posX][Cell->posY] = SDL_TRUE;
  push(stack, Cell);
}
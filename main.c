#include <conio.h>
#include <stdio.h>
#include <unistd.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

void clearScreen() {
  const char* CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
void colorGreen() { printf("\033[1;92m"); }
void colorCyan() { printf("\033[1;36m"); }
void colorReset() { printf("\033[0m"); }
void printTitle(char* title) {
  colorGreen();
  printf("%s\n", title);
  colorReset();
}
void printSelect(char* selects[], int length, int selected) {
  printf("----------------");
  printf("SELECT");
  printf("----------------\n");
  for (int i = 0; i < length; i++) {
    if (i == selected) {
      colorCyan();
      printf("> %s\n", selects[i]);
      colorReset();
      continue;
    }
    printf("- %s\n", selects[i]);
  }
  printf("--------------------------------------\n");
}
int detactArrowKey() {
  int nSelect = 0;
  while (1) {
    if (kbhit()) {
      nSelect = getch();
      if (nSelect == 224) {
        nSelect = getch();
        switch (nSelect) {
          case KEY_UP:
            return 1;
            break;
          case KEY_DOWN:
            return 2;
            break;
          case KEY_LEFT:
            return 3;
            break;
          case KEY_RIGHT:
            return 4;
            break;
          default:
            return -1;
            break;
        }
      } else if (nSelect == KEY_ENTER) {
        return 0;
      }
    }
  }
}
int selectMenu(char* selects[], int selectsLen) {
  int selected = 0;
  int arrow = 1;
  selects[0] = "Maze Generate";
  while (arrow) {
    clearScreen();
    printTitle("WELCOME TO THE MAZE ALGORITHMS MUSEUM");
    printSelect(selects, selectsLen, selected);
    arrow = detactArrowKey();
    if (arrow == 1)
      selected--;
    else if (arrow == 2)
      selected++;

    if (selected < 0)
      selected = 0;
    else if (selected > selectsLen - 1)
      selected = selectsLen - 1;
  }
  return selected;
}

int main() {
  char* selects[2] = {"Maze Generate", "sdfs"};
  int selected = selectMenu(selects, 2);
  printf("%d", selected);
  return 0;
}
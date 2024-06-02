void printHelp() {
    printfflush(
        "[──]	In Below Menu, You can use Arrow Key to move cursor and Enter "
        "Key to select.\n");
    printfflush("[──]	https://github.com/pgmrDohan/SDL2_MazeRunner\n\n");
}

void printTitle() {
#ifdef _WIN32
    system("chcp 65001");
    clearScreen();
#endif
    colorGreen();
    printfflush(
        "███╗   ███╗ █████╗ ███████╗███████╗\n"
        "████╗ ████║██╔══██╗╚══███╔╝██╔════╝\n"
        "██╔████╔██║███████║  ███╔╝ █████╗\n"
        "██║╚██╔╝██║██╔══██║ ███╔╝  ██╔══╝\n"
        "██║ ╚═╝ ██║██║  ██║███████╗███████╗\n"
        "╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝\n"
        " █████╗ ██╗      ██████╗  ██████╗ ██████╗ ██╗████████╗██╗  ██╗███╗   "
        "███╗███████╗\n"
        "██╔══██╗██║     ██╔════╝ ██╔═══██╗██╔══██╗██║╚══██╔══╝██║  ██║████╗ "
        "████║██╔════╝\n"
        "███████║██║     ██║  ███╗██║   ██║██████╔╝██║   ██║   "
        "███████║██╔████╔██║███████╗\n"
        "██╔══██║██║     ██║   ██║██║   ██║██╔══██╗██║   ██║   "
        "██╔══██║██║╚██╔╝██║╚════██║\n"
        "██║  ██║███████╗╚██████╔╝╚██████╔╝██║  ██║██║   ██║   ██║  ██║██║ ╚═╝ "
        "██║███████║\n"
        "╚═╝  ╚═╝╚══════╝ ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝     "
        "╚═╝╚══════╝\n"
        "███╗   ███╗██╗   ██╗███████╗███████╗██╗   ██╗███╗   ███╗\n"
        "████╗ ████║██║   ██║██╔════╝██╔════╝██║   ██║████╗ ████║\n"
        "██╔████╔██║██║   ██║███████╗█████╗  ██║   ██║██╔████╔██║\n"
        "██║╚██╔╝██║██║   ██║╚════██║██╔══╝  ██║   ██║██║╚██╔╝██║\n"
        "██║ ╚═╝ ██║╚██████╔╝███████║███████╗╚██████╔╝██║ ╚═╝ ██║\n"
        "╚═╝     ╚═╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝     ╚═╝\n\n");
    colorReset();
}

void printSelect(const char* selects[], int length, int selected,
                 const char* discription) {
    printfflush("───── ");
    printfflush("%s", discription);
    printfflush(" ────────────────────────────────\n");
    for (int i = 0; i < length; i++) {
        if (i == selected) {
            colorCyan();
            printfflush("> %s\n", selects[i]);
            colorReset();
            continue;
        }
        printfflush("- %s\n", selects[i]);
    }
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
            } else {
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
            }
        }
    }
}

int selectMenu(const char* selects[], int selectsLen, const char* discription) {
    int selected = 0;
    int arrow = 1;
    while (arrow) {
        clearScreen();
        printTitle();
        printHelp();
        printSelect(selects, selectsLen, selected, discription);
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

int* selectSize() {
    int select = selectMenu(SEL_WINDOW_SIZE, LEN_WINDOW_SIZE, DISC_WINDOW_SIZE);
    static int size[2];
    size[0] = select == 0 ? 500 : 1000;
    size[1] = select == 0 ? 300 : 600;
    return size;
}
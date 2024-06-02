#define SEL_FIRST ((char const* [2]){"Generate new maze", "Exit"})
#define LEN_FIRST 2
#define DISC_FIRST ((char*)"Select and start")

#define SEL_WINDOW_SIZE ((char const* [2]){"500*300", "1000*600"})
#define LEN_WINDOW_SIZE 2
#define DISC_WINDOW_SIZE ((char*)"Select maze size (w*h)")

#define SEL_GENRERATE_OPT                                            \
    ((char const* [4]){"Depth First Search", "Breadth First Search", \
                       "Prim's algorithm", "Kruskal's algorithm"})
#define LEN_GENRERATE_OPT 4
#define DISC_GENRERATE_OPT ((char*)"Select maze generating algorithm")

#define SEL_TO_DO \
    ((char const* [3]){"Generate new maze", "Solve the maze", "Exit"})
#define LEN_TO_DO 3
#define DISC_TO_DO ((char*)"Select what to do")

#define SEL_SOLVE_OPT                                                \
    ((char const* [6]){"Depth First Search", "Breadth First Search", \
                       "Dijkstra's algorithm", "A* algorithm",       \
                       "Left-hand rule", "Right-hand rule"})
#define LEN_SOLVE_OPT 6
#define DISC_SOLVE_OPT ((char*)"Select maze solving algorithm")
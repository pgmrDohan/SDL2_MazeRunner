all: main.c run

main.c:
	gcc src/main.c -I/opt/homebrew/include -D_THREAD_SAFE -L/opt/homebrew/lib -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -o"build/MazeRunner"

run:
	./build/MazeRunner

clean:
	rm -f "build/MazeRunner"
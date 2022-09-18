#include"raylib.h"
#include"random"
const int Size = 200;
int xy[Size][Size];
int swapbufferxy[Size][Size];
int livingneighbourcells = 0;
int main(void) {
	
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(0, 1);

	InitWindow(1000, 1000, "Conways game of life");
	SetTargetFPS(10);//Set updates per second
	
	for (int x = 0; x < Size; x++) {
		for (int y = 0; y < Size; y++) {
			xy[x][y] = distr(eng);
		}
	}
	///////////////////Creats blinker and set all cells at beginning to 0,change: xy[x][y] = distr(eng); in line 19 to xy[x][y] = 0;
	/*
	for (int x = 100; x < 103; x++) {
		for (int y = 100; y < 101; y++) {
			xy[x][y] = 1;
		}
	}
	*/
	///////////////////////////////////////////////////////////
	while (!WindowShouldClose()) {
		
		ClearBackground(WHITE);
		
		BeginDrawing();
		for (int x = 0; x < Size; x++) {
			for (int y = 0; y < Size; y++) {
				if (xy[x][y] == 1) {
					DrawRectangle(x * 5, y * 5, 5, 5, BLACK);
				}
			}
		}
		EndDrawing();

		for (int x1 = 0; x1 < Size; x1++) {
			for (int y1 = 0; y1 < Size; y1++) {
				livingneighbourcells = 0;
				int xn;
				int yn;
				//////////////////////////////////////////////////////////////// check all neighbour cells [
				// wert von aktuellen block abchecken geht (sonst w�rd es ja nicht malen aber eins weiter abchecken geht nicht (komisch))...
				if ((x1 >= 1) && (y1 >= 1)) {

					xn = x1 - 1;
					yn = y1;
					if (xy[xn][yn] == 1) {
						livingneighbourcells += 1;
					}

					xn = x1;
					yn = y1 - 1;
					if (xy[xn][yn] == 1) {
						livingneighbourcells += 1;
					}

					xn = x1 + 1;
					yn = y1;
					if (xy[xn][yn] == 1) {
						livingneighbourcells += 1;
					}

					xn = x1;
					yn = y1 + 1;
					if (xy[xn][yn] == 1) {
						livingneighbourcells += 1;
					}

					xn = x1 - 1;
					yn = y1 - 1;
					if (xy[xn][yn] == 1) {
						livingneighbourcells += 1;
					}

					xn = x1 + 1;
					yn = y1 + 1;
					if (xy[xn][yn] == 1) {
						livingneighbourcells += 1;
					}

					xn = x1 - 1;
					yn = y1 + 1;
					if (xy[xn][yn] == 1) {
						livingneighbourcells += 1;
					}

					xn = x1 + 1;
					yn = y1 - 1;
					if (xy[xn][yn] == 1) {
						livingneighbourcells += 1;
					}
				}
				//////////////////////////////////////////////////////////////// check all neighbour cells ]
				//////////////////////////////////////////////////////////////// rules [
				if (xy[x1][y1] == 1 && (livingneighbourcells == 3||livingneighbourcells == 2)) {
					swapbufferxy[x1][y1] = 1;
				}
				if (livingneighbourcells == 3 && xy[x1][y1] == 0) {
					swapbufferxy[x1][y1] = 1;
				}
				if (livingneighbourcells < 2 && xy[x1][y1] == 1) {
					swapbufferxy[x1][y1] = 0;
				}
				if (livingneighbourcells > 3) { 
					swapbufferxy[x1][y1] = 0;
				}
				//////////////////////////////////////////////////////////////// rules ]
			}
		 
		}
		memcpy(xy, swapbufferxy, sizeof(xy));
	}
	
	CloseWindow();
	return 0;
}

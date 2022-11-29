
#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFPhysics.h>
//#include <vector>

using namespace std;
//using namespace sf;
//using namespace sfp;

//void LoadTex(Texture& tex, string filename) {
	//if (!tex.loadFromFile(filename)) {
		//cout << "Could not load " << filename << endl;
	//}
//}

//int main() {
	//RenderWindow window(VideoMode(800, 600), "Balloon Buster");
	//World world(Vector2f(0, 0));
	
	//PhysicsSprite verticalGrid;
	//verticalGrid.setSize(Vector2f(10, 800));
	//verticalGrid.setCenter(Vector2f(400, 5));
	//};
	//window.display();
//}



// change row and column
const int row = 5;
const int col = 4;
// create row boundary
int row_line() {
	cout << endl;
	for (int i = 0; i < col; i++) {
		cout << " -----";
	}
	cout << endl;
}
// return count of alive neighbors
int countLiveNeighborCell(int a[row][col], int r, int c) {
	int i, j, count = 0;
	for (i = r - 1; i <= r + 1; i++) {
		for (j = c - 1; j <= c + 1; j++) {
			if ((i == r && j == c) || (i < 0 || j < 0) || (i >= row || j >= col)) {
				continue;
			}
			if (a[i][j] == 1) {
				count++;
			}
		}
	}
	return count;
}

int main() {
	int a[row][col], b[row][col];
	int i, j;
	int neighborLiveCell;
	// generate canvas with random alive & dead cells
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			a[i][j] = rand() % 2;
		}
	}
	// draw array
	cout << "Initial Stage:";
	row_line();
	for (i = 0; i < row; i++) {
		cout << ":";
		for (j = 0; j < col; j++) {
			cout << "  " << a[i][j] << "  :";
		}
		row_line();
	}
	// next generation (based on live cell count)
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
			neighborLiveCell = countLiveNeighborCell(a, i, j);
		if (a[i][j] == 1 && (neighborLiveCell == 2 || neighborLiveCell == 3)) {
			b[i][j] = 1;
		}
		else if (a[i][j] == 0 && neighborLiveCell == 3) {
			b[i][j] = 1;
		}
		else {
			b[i][j] = 0;
		}
	}
	// print next generation
	cout << "\nNext Generation:";
	row_line();
	for (i = 0; i < row; i++) {
		cout << ":";
		for (j = 0; j < col; j++) {
			cout << "  " << b[i][j] << "  :";
		}
		row_line();
	}
	return 0;
}

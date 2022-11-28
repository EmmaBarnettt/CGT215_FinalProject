
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include <vector>

using namespace std;
using namespace sf;
using namespace sfp;

const float KB_SPEED = 0.2;

void LoadTex(Texture& tex, string filename) {
	if (!tex.loadFromFile(filename)) {
		cout << "Could not load " << filename << endl;
	}
}

int main() {
	RenderWindow window(VideoMode(800, 600), "Balloon Buster");
	World world(Vector2f(0, 0));
	
	PhysicsSprite verticalGrid;
	verticalGrid.setSize(Vector2f(10, 800));
	verticalGrid.setCenter(Vector2f(400, 5));
	};
	window.display();
}
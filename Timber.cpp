#include "SFML\Graphics.hpp"

using namespace sf;

int main() {
	// Create a video mode object
	VideoMode vm(1680, 1050);
	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);
	while (window.isOpen())	{ 
		/*
		**************************************** Handle the players input
		****************************************
		*/
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}
		/*
		**************************************** Update the scene
		****************************************
		*/
		/***************************************** Draw the scene
		****************************************
		*/
		// Clear everything from the last frame 
		window.clear();
		// Draw our game scene here
		window.draw(spriteBackground);
		// Show everything we just drew 
		window.display();
	}
	return 0;
}
#include <sstream>
#include "SFML\Graphics.hpp"

using namespace sf;

int main() {
	// Create a video mode object
	VideoMode vm(1920, 1080);
	// Create and open a window for the game
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	// Make a tree sprite
	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	// Prepare the bee
	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	// Is the bee currently moving?
	bool beeActive = false;
	// How fast can the bee fly
	float beeSpeed = 0.0f;

	// make 3 cloud sprites from 1 texture
	Texture textureCloud;
	// Load 1 new texture
	textureCloud.loadFromFile("graphics/cloud.png");
	// 3 New sprites with the same texture
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	// Position the clouds on the left of the screen
	// at different heights
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 250);
	spriteCloud3.setPosition(0, 500);
	// Are the clouds currently on screen?
	bool cloud1Active = false;
	bool cloud2Active = false;
	bool cloud3Active = false;
	// How fast is each cloud?
	float cloud1Speed = 0.0f;
	float cloud2Speed = 0.0f;
	float cloud3Speed = 0.0f;
	
	// Variables to control time itself
	Clock clock;

	// Track whether the game is running
	bool paused = true;

	// Draw some text
	int score = 0;
	Text messageText;
	Text scoreText;
	// We need to choose a font
	Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");
	// Set the font to our message
	messageText.setFont(font);
	scoreText.setFont(font);
	// Assign the actual message
	messageText.setString("Press enter to start!");
	scoreText.setString("Score = 0");
	// Make it really big
	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);
	//Choose a color
	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);
	// Position the text
	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width / 2.0f, 
						  textRect.top + textRect.height / 2.0f);
	messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
	scoreText.setPosition(20, 20);


	while (window.isOpen())	{ 
		/***************************************** 
		Handle the players input
		*****************************************/

		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// Start the game
		if (Keyboard::isKeyPressed(Keyboard::Return)) {
			paused = false;
		}

		/***************************************** 
		Update the scene
		*****************************************/

		if (!paused) {
			//Measure Time
			Time dt = clock.restart();

			// Setup the bee
			if (!beeActive) {
				//How fast is the bee
				srand((int)time(0));
				beeSpeed = (rand() % 200) + 200;

				// How high is the bee
				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				beeActive = true;
			} else {
				// Move the bee
				float updown = (rand() % 100) + 1;
				if (updown <= 50) {
					spriteBee.setPosition(spriteBee.getPosition().x -
						(beeSpeed * dt.asSeconds()),
						spriteBee.getPosition().y -
						(beeSpeed * dt.asSeconds()) * 2);
				} else {
					spriteBee.setPosition(spriteBee.getPosition().x -
						(beeSpeed * dt.asSeconds()),
						spriteBee.getPosition().y +
						(beeSpeed * dt.asSeconds()) * 2);
				}
				// Has the bee reached the left-hand of the screen
				if (spriteBee.getPosition().x < -100) {
					// Set it up ready to be a whole new bee next frame
					beeActive = false;
				}
			}

			// Manage clouds
			if (!cloud1Active) {
				// How fast is the cloud
				srand((int)time(0) * 10);
				cloud1Speed = (rand() % 200);
				// How high is the cloud
				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				cloud1Active = true;
			} else {
				spriteCloud1.setPosition(spriteCloud1.getPosition().x +
					(cloud1Speed * dt.asSeconds()),
					spriteCloud1.getPosition().y);
				// Has the cloud reached the right hand side of the screen?
				if (spriteCloud1.getPosition().x > 1920) {
					// Set it up ready to be a whole new cloud next frame
					cloud1Active = false;
				}
			}
			if (!cloud2Active) {
				// How fast is the cloud
				srand((int)time(0) * 20);
				cloud2Speed = (rand() % 200);
				// How high is the cloud
				srand((int)time(0) * 20);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				cloud2Active = true;
			} else {
				spriteCloud2.setPosition(spriteCloud2.getPosition().x +
					(cloud2Speed * dt.asSeconds()),
					spriteCloud2.getPosition().y);
				// Has the cloud reached the right hand side of the screen?
				if (spriteCloud2.getPosition().x > 1920) {
					// Set it up ready to be a whole new cloud next frame
					cloud2Active = false;
				}
			}
			if (!cloud3Active) {
				// How fast is the cloud
				srand((int)time(0) * 30);
				cloud3Speed = (rand() % 200);
				// How high is the cloud
				srand((int)time(0) * 30);
				float height = (rand() % 450) - 150;
				spriteCloud3.setPosition(-200, height);
				cloud3Active = true;
			} else {
				spriteCloud3.setPosition(spriteCloud3.getPosition().x +
					(cloud3Speed * dt.asSeconds()),
					spriteCloud3.getPosition().y);
				// Has the cloud reached the right hand side of the screen?
				if (spriteCloud3.getPosition().x > 1920) {
					// Set it up ready to be a whole new cloud next frame
					cloud3Active = false;
				}
			}
		}

		/***************************************** 
		Draw the scene
		*****************************************/
		// Clear everything from the last frame 
		window.clear();
		// Draw our game scene here
		window.draw(spriteBackground);

		// Draw the clouds
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);
		// Draw the tree
		window.draw(spriteTree);
		// Draw the insect
		window.draw(spriteBee);

		// Show everything we just drew 
		window.display();
	}
	return 0;
}




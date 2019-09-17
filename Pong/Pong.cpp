// Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

int main()
{
	std::cout << "Game Started!\n";

	//Creating window for the game
	sf::RenderWindow window(sf::VideoMode(800, 600), "Pong");

	//Setting frame limit to 60 fps for a smooth game
	window.setFramerateLimit(60);

	window.setKeyRepeatEnabled(false);

	//bool play = true;

    

	//Loading font file
	sf::Font font;
	if (font.loadFromFile("Data/GS.ttf") == false)
	{
		std::cout << "Loading failed";
		return 1;
	}
	else if (font.loadFromFile("Data/GS.ttf") == true)
	{
		std::cout << "Font Loaded Successfully \n";
	}
	sf::Text score;
	score.setFont(font);
	score.setCharacterSize(30);
	//score.setColor(sf::Color::Red);
	score.setPosition(350, 10);
	score.setString("0 : 0");


	sf::Event event;
	//Images
	sf::Texture texPad;
	sf::Texture texBall;
	sf::Texture texBackground;
	if (texPad.loadFromFile("Data/paddle.png") == false)
	{
		std::cout << "Paddle not loaded";
		return -1;
	}
	else if (texPad.loadFromFile("Data/paddle.png") == true)
	{
		std::cout << "Paddle Loaded Successfully \n";
	}


	if (texBall.loadFromFile("Data/ball.png") == false)
	{
		std::cout << "Ball not loaded";
		return -1;
	}
	else if (texBall.loadFromFile("Data/ball.png") == true)
	{
		std::cout << "Ball Loaded Successfully \n";
	}

	if (texBackground.loadFromFile("Data/rgb.jpg") == false)
	{
		std::cout << "Background not loaded";
		return -1;
	}
	else if (texBackground.loadFromFile("Data/rgb.jpg") == true)
	{
		std::cout << "Background Loaded Successfully \n";
	}

	//Sounds
	sf::SoundBuffer buffHit;
	sf::Sound hit;
	hit.setBuffer(buffHit);

	if (buffHit.loadFromFile("Data/oof.ogg") == false)
	{
		std::cout << "Sound oof not loaded";
		return -1;
	}
	else if (buffHit.loadFromFile("Data/oof.ogg") == true)
	{
		std::cout << "Sound oof loaded successfully\n";
		//return -1;
	}

	//States
	bool upKey = false;
	bool downKey = false;

	//Variables
	int yPad1Velocity = 0;
	int xBallVelocity = -4;
	int yBallVelocity = -4;
	int yPad2Vel = 0;
	int pad1score = 0;
	int pad2score = 0;

	//Shapes

	//background shape
	sf::RectangleShape background;
	background.setSize(sf::Vector2f(800, 600));
	background.setPosition(0, 0);
	background.setTexture(&texBackground);

	//Pad1
	sf::RectangleShape pad1;
	pad1.setSize(sf::Vector2f(50, 100));
	pad1.setPosition(50, 200);
	pad1.setTexture(&texPad);

	//Pad2
	sf::RectangleShape pad2;
	pad2.setSize(sf::Vector2f(50, 100));
	pad2.setPosition(700, 200);
	pad2.setTexture(&texPad);

	//Ball
	sf::RectangleShape ball;
	ball.setSize(sf::Vector2f(50, 50));
	ball.setPosition(400, 200);
	ball.setTexture(&texBall);



	while (window.isOpen())
	{
		//sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
			{
				upKey = true;
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
			{
				downKey = true;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::W)
			{
				upKey = false;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S)
			{
				downKey = false;
			}

		}

		//Logic Handling Here

		//pad1 up / down logic
		if (upKey == true)
		{
			yPad1Velocity = -5;
		}

		if (downKey == true)
		{
			yPad1Velocity = 5;
		}

		if (downKey == true && upKey == true)
		{
			yPad1Velocity = 0;
		}

		if (upKey == false && downKey == false)
		{
			yPad1Velocity = 0;
		}

		pad1.move(0, yPad1Velocity);
		
		//Out of bounds check
		if (pad1.getPosition().y < 0)
		{
			pad1.setPosition(50, 0);
		}

		if (pad1.getPosition().y > 500)
		{
			pad1.setPosition(50, 500);
		}

		//Pad2 Logic
		if (ball.getPosition().y < pad2.getPosition().y)
		{
			yPad2Vel = -5;
		}

		if (ball.getPosition().y > pad2.getPosition().y)
		{
			yPad2Vel = 5;
		}

		pad2.move(0, yPad2Vel);


		//Ball Logic
		//Only has to move around and has to bound away when out of bounds
		//needs collisionh w/ paddles
		ball.move(xBallVelocity, yBallVelocity);

		// Out of bounds check
		if (ball.getPosition().y < 0)
		{
			yBallVelocity = -yBallVelocity;
		}

		if (ball.getPosition().y > 500)
		{
			yBallVelocity = -yBallVelocity;
		}

		//checking l / r
		if (ball.getPosition().x < -50)
		{
			pad2score++;
			ball.setPosition(300, 200);
		}

		if (ball.getPosition().x > 800)
		{
			pad1score++;
			ball.setPosition(300, 200);
		}

		//Pad1Collision Check
		if (ball.getGlobalBounds().intersects(pad1.getGlobalBounds()) == true)
		{
			hit.play();
			xBallVelocity = -xBallVelocity;
			
		}

		//pad2collision check
		if (ball.getGlobalBounds().intersects(pad2.getGlobalBounds()) == true)
		{
			hit.play();
			xBallVelocity = -xBallVelocity;
			
		}

		//Rendering part here
		window.clear();
		window.draw(background);

		window.draw(pad1);
		window.draw(pad2);
		window.draw(ball);

		//score
		std::stringstream textScore;
		textScore << pad1score << " : " << pad2score;
		score.setString(textScore.str());
		window.draw(score);

		//Drawing objects here
		window.display();


	}


}



#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

#include "TetrisApp.h"
#include "TextComponent.h"
#include "GameEntity.h"
#include "EntityComponentManager.h"
#include "AudioComponent.h"

constexpr auto M = 20;
constexpr auto N = 10;

TetrisApp* app;
TextComponent* txt;
AudioComponent* gamemusic;
AudioComponent* brickfall;
AudioComponent* brickbreak;
AudioComponent* shapechange;

std::shared_ptr<GameEntity> tile;
std::shared_ptr<GameEntity> background;
std::shared_ptr<GameEntity> frame;

// to keep track off occupied spaces for breaking
int field[M][N] = { 0 };

struct Point
{
	int x, y;
} a[4], b[4];


int figures[7][4] =
{
	1,3,5,7, // I
	2,4,5,7, // Z
	3,5,4,6, // S
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};

//
int direction = 0;
bool rotate = 0;
int colorNum = 1;

float timer = 0, delay = 0.3, sounddelay = 1.0f;


void checkandbreak()
{
	int k = M - 1;
	for (int i = M - 1; i > 0; i--)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (field[i][j]) count++;
			field[k][j] = field[i][j];
		}
		if (count < N) { k--; }
		else { brickbreak->PlaySound(); }
	}

}

bool check()
{
	for (int i = 0; i < 4; i++)
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
		else if (field[a[i].y][a[i].x]) return 0;

	return 1;
};

void moveleftright()
{
	for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += direction; }
	if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
}

void rotatebrick()
{
	if (rotate)
	{
		shapechange->PlaySound();
		Point p = a[1]; //center of rotation
		for (int i = 0; i < 4; i++)
		{
			int x = a[i].y - p.y;
			int y = a[i].x - p.x;
			a[i].x = p.x - x;
			a[i].y = p.y + y;
		}
		if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
	}
}

void fallingmotion()
{
	
	if (timer > delay)
	{
		 
		for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }
		brickfall->PlaySound();

		if (!check())
		{
			
			for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;

			colorNum = 1 + rand() % 7;
			int n = rand() % 7;
			for (int i = 0; i < 4; i++)
			{
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
		}

		timer = 0;

		
		brickbreak->StopSound();
		shapechange->StopSound();
		//brickfall->StopSound();

	}
	
}



void HandleEvents()
{
	sf::Event e;
	while (app->GetRenderWindow()->pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
		{
			app->GetRenderWindow()->close();
			exit(EXIT_SUCCESS);
		}


		if (e.type == sf::Event::KeyPressed)
			if (e.key.code == sf::Keyboard::Up) { rotate = true; }
			else if (e.key.code == sf::Keyboard::Left) direction = -1;
			else if (e.key.code == sf::Keyboard::Right) direction = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) delay = 0.05;

}

void HandleUpdate()
{
	
	//// <- Move -> ///
	moveleftright();

	//////Rotate//////
	rotatebrick();

	///////Tick////////
	fallingmotion();

	///////check lines//////////
	checkandbreak();
	
	

	direction = 0;
	rotate = 0;

}

void HandleRendering()
{
	/////////draw//////////
	app->GetRenderWindow()->clear(sf::Color::White);
	background->Render(*app->GetRenderWindow());
	//app->GetRenderWindow().draw(background);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (field[i][j] == 0) continue;
			for (auto it : tile->GetComponents())
			{
				it->setTextureRect(sf::IntRect(field[i][j] * 18, 0, 18, 18));
				it->setPosition(j * 18, i * 18);
				it->move(sf::Vector2f(28, 31)); //offset
			}
			tile->Render(*app->GetRenderWindow());
		}
	}

	for (int i = 0; i < 4; i++)
	{
		//s.setTextureRect(sf::IntRect(colorNum * 18, 0, 18, 18));
		for (auto it : tile->GetComponents())
		{
			it->setTextureRect(sf::IntRect(colorNum * 18, 0, 18, 18));
			it->setPosition(a[i].x * 18, a[i].y * 18);
			it->move(sf::Vector2f(28, 31)); //offset
		}
		tile->Render(*app->GetRenderWindow());
	}

	frame->Render(*app->GetRenderWindow());

	app->GetRenderWindow()->display();
	
}

int main()
{
	srand(time(0));

	// Setup the App
	app = new TetrisApp(sf::VideoMode(320, 480), "Tetris Game!!!!");


	txt = new TextComponent("./assets/fonts/8bitOperatorPlus8-Regular.ttf");
	txt->setPosition(40.0f, 10.0f);

	//AudioComponent* audio;

	// Create any objects in our scene
	tile = EntityComponentManager::Instance().CreateEntity("tiles");
	tile->AddSpriteComponent("assets/images/tiles.png");

	background = EntityComponentManager::Instance().CreateEntity("background");
	background->AddSpriteComponent("assets/images/background.png");

	frame = EntityComponentManager::Instance().CreateEntity("frame");
	frame->AddSpriteComponent("assets/images/frame.png");


	// Setup our sounds
	gamemusic = new AudioComponent("assets/audio/Tetris_music.ogg", true, 25.0f, 1.2f);
	brickbreak = new AudioComponent("assets/audio/brick_breaking.ogg", false, 100.0f, 1.2f);
	brickfall = new AudioComponent("assets/audio/brick_falling.ogg", true, 100.0f, 1.2f);
	brickfall->SetAudioOffset(1000.0f);
	shapechange = new AudioComponent("assets/audio/shape_change.ogg", false, 100.0f, 1.2f);



	// Set callback functions
	app->SetEventCallback(HandleEvents);
	app->SetUpdateCallback(HandleUpdate);
	app->SetRenderCallback(HandleRendering);


	// Game Looooooop
	gamemusic->PlaySound();
	app->RunLoop();
	gamemusic->StopSound();




	// Clean Up Application resources
	delete app;
	delete txt;
	delete brickfall;
	delete brickbreak;
	delete shapechange;
	delete gamemusic;

	return EXIT_SUCCESS;
}
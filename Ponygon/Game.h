#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "SceneManager.h"
#include "Scene.h"

#include "Mother.h"
#include "Other.h"

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	sf::RenderWindow mWindow;
	SceneManager mSceneManager;
};

#endif
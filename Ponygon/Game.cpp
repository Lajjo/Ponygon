#include "Game.h"


Game::Game()
{
	srand(time(0));

	mWindow.create(sf::VideoMode(1920, 1080), "Ponygon", sf::Style::Fullscreen, sf::ContextSettings(0, 0, 4, 2, 0));
	mWindow.setFramerateLimit(60);
	
	Scene* s = new Scene;
	
	Mother* mother = new Mother;
	mother->init(mWindow);
	s->addEntity(mother);

	for(int i = 0; i < 30; i++)
	{
		Other* other = new Other;
		other->init(mWindow);
		s->addEntity(other);
	}

	mSceneManager.add(s);
}


Game::~Game()
{

}

void Game::run()
{
	while(mWindow.isOpen())
	{
		sf::Event event;
		while(mWindow.pollEvent(event))
		{
			if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				mWindow.close();
		}

		mSceneManager.update();

		mWindow.clear(sf::Color(212, 202, 182));
		mSceneManager.draw(mWindow);
		mWindow.display();
	}
}
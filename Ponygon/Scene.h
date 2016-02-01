#ifndef SCENE_H
#define SCENE_H

#include "EntityManager.h"
#include <SFML/Graphics.hpp>

class Scene
{
public:
	Scene();
	~Scene();

	void addEntity(Entity* e);
	void removeEntity(Entity* e);

	void update();

	void draw(sf::RenderWindow& window);
private:
	EntityManager mEntityManager;
};

#endif
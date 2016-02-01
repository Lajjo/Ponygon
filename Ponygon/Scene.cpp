#include "Scene.h"

Scene::Scene(){}
Scene::~Scene(){}

void Scene::addEntity(Entity* e)
{
	mEntityManager.add(e);
}

void Scene::removeEntity(Entity* e)
{
	mEntityManager.remove(e);
}

void Scene::update()
{
	mEntityManager.update();
}

void Scene::draw(sf::RenderWindow& window)
{
	mEntityManager.drawBack(window);
	mEntityManager.drawMiddle(window);
	mEntityManager.drawFront(window);
}
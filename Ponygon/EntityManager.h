#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Entity;

class EntityManager
{
public:
	typedef std::vector<Entity*> EntityVector;
	enum Layer{BACK, MIDDLE, FRONT};

	EntityManager();
	~EntityManager();

	void add(Entity* e);
	void remove(Entity* e);
	
	void update();

	void drawBack(sf::RenderWindow& window);
	void drawMiddle(sf::RenderWindow& window);
	void drawFront(sf::RenderWindow& window);

	int getEntityCount();
	int getEntityCount(const std::string& tag);
	EntityVector getEntitiesByTag(std::string& tag);
private:
	EntityVector mEntities, mEntitiesToAdd, mEntitiesToRemove;
};

#endif
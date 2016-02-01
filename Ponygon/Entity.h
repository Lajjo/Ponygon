#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <SFML/Graphics.hpp>

class EntityManager;

class Entity
{
public:
	enum Layer{BACK, MIDDLE, FRONT};

	virtual ~Entity();
	virtual void init(sf::RenderWindow& window)=0;
	virtual void update(EntityManager& manager)=0;
	virtual void draw(sf::RenderWindow& window)=0;

	virtual Layer getLayer() const=0;
	virtual std::string getTag() const=0;
protected:
	Entity();
};

#endif
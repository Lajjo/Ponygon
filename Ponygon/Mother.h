#ifndef MOTHER_H
#define MOTHER_H

#include "Entity.h"

class Mother : public Entity
{
public:
	Mother();
	virtual ~Mother();
	virtual void init(sf::RenderWindow& window);
	virtual void update(EntityManager& manager);
	virtual void draw(sf::RenderWindow& window);

	virtual Layer getLayer() const;
	virtual std::string getTag() const;
private:
	sf::CircleShape mShape;
};

#endif
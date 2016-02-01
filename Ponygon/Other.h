#ifndef OTHER_H
#define OTHER_H

#include "Entity.h"

class Other : public Entity
{
public:
	Other();
	virtual ~Other();
	virtual void init(sf::RenderWindow& window);
	virtual void update(EntityManager& manager);
	virtual void draw(sf::RenderWindow& window);

	virtual Layer getLayer() const;
	virtual std::string getTag() const;
private:
	sf::ConvexShape mShape;
	sf::Vector2f mDelta;
	sf::Vector2u mTarget;
	sf::Vector2u mWindowSize;
	float mRotation;
	int mLayer;
};

#endif
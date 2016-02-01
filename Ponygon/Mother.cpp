#include "Mother.h"
#include "EntityManager.h"

Mother::Mother(){}
Mother::~Mother(){}


void Mother::init(sf::RenderWindow& window)
{
	mShape.setRadius(40);
	mShape.setFillColor(sf::Color(80, 140, 80));
	mShape.setPosition(window.getSize().x/2.f, window.getSize().y/2.f);
	mShape.setOrigin(mShape.getRadius(), mShape.getRadius());
}

void Mother::update(EntityManager& manager)
{
	//if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	if(manager.getEntityCount("other") < 10)
	mShape.scale(1.001f, 1.001f);
}

void Mother::draw(sf::RenderWindow& window)
{
	window.draw(mShape);
}

Entity::Layer Mother::getLayer() const
{
	return MIDDLE;
}

std::string Mother::getTag() const
{
	return "mother";
}
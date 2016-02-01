#include "Other.h"
#include "EntityManager.h"
#include "Helper.h"
#include <math.h>
#include <iostream>

Other::Other(){}
Other::~Other(){}

void Other::init(sf::RenderWindow& window)
{
	mLayer = Helper::random(-1, 1);
	int radius = 50;
	int diameter = radius*2;
	int vertex_count = 3 + (rand()%5);
	mShape.setPointCount(vertex_count);
	float slice = (2*3.14)/vertex_count;
	for(int i = 0; i < vertex_count; i++)
	{
		float angle = slice*i;
		mShape.setPoint(i, sf::Vector2f(cos(angle)*radius, sin(angle)*radius)); 
	}

	mShape.setScale(1 + Helper::random(0, 10)/100, 1 + Helper::random(0, 10)/100);

	mShape.setRotation(Helper::random(0, 360));
	mRotation = Helper::random(-1, 1)/10.f;
	
	mWindowSize = window.getSize();
	sf::Vector2f pos(mWindowSize.x/2, mWindowSize.y/2);
	
	while(pos.x > ((mWindowSize.x/2) - diameter) && pos.x < ((mWindowSize.x/2) + diameter) && pos.y > ((mWindowSize.y/2) - diameter) && pos.y < ((mWindowSize.y/2) + diameter))
		pos = sf::Vector2f(mWindowSize.x/2 + Helper::random(-diameter*2, diameter*2), mWindowSize.y/2 + Helper::random(-diameter*2, diameter*2));
	mShape.setPosition(pos);
	
	mTarget = sf::Vector2u(window.getSize().x/2, window.getSize().y/2);

	switch(rand()%6)
	{
	case 0:
		mShape.setFillColor(sf::Color(140, 85, 85));
		break;
	case 1:
		mShape.setFillColor(sf::Color(120, 85, 140));
		break;
	case 2:
		mShape.setFillColor(sf::Color(85, 130, 140));
		break;
	case 3:
		mShape.setFillColor(sf::Color(140, 140, 85));
		break;
	case 4:
		mShape.setFillColor(sf::Color(140, 110, 85));
		break;
	case 5:
		mShape.setFillColor(sf::Color(140, 85, 130));
		break;
	}
}

void Other::update(EntityManager& manager)
{
	sf::Vector2f pos = mShape.getPosition();
	if(pos.x < -100 || pos.x > mWindowSize.x + 100 || pos.y < -100 || pos.y > mWindowSize.y + 100)
		manager.remove(this);
	sf::Color c = mShape.getFillColor();
	if(c.a > 0)
		c.a--;
	//mShape.setFillColor(c);
	mDelta.x = -(mTarget.x - mShape.getPosition().x)/500.f;
	mDelta.y = -(mTarget.y - mShape.getPosition().y)/500.f;
	mShape.move(mDelta);

	mShape.scale(1+(mLayer/1500.f), 1+(mLayer/1500.f));
	mShape.rotate(mRotation);

}

void Other::draw(sf::RenderWindow& window)
{
	window.draw(mShape);
}

Entity::Layer Other::getLayer() const
{
	if(mLayer == -1)
		return BACK;
	else if(mLayer == 1)
		return FRONT;
	
	return MIDDLE;
}

std::string Other::getTag() const
{
	return "other";
}
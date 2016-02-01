#include "EntityManager.h"
#include "Entity.h"
#include <iostream>

EntityManager::EntityManager(){}
EntityManager::~EntityManager()
{
	while(!mEntities.empty())
	{
		delete mEntities.back();
		mEntities.pop_back();
	}
}

void EntityManager::add(Entity* e)
{
	mEntitiesToAdd.push_back(e);
}

void EntityManager::remove(Entity* e)
{
	mEntitiesToRemove.push_back(e);
}

void EntityManager::update()
{
	for(EntityVector::size_type i = 0; i < mEntities.size(); i++)
	{
		for(EntityVector::size_type j = 0; j < mEntitiesToRemove.size(); j++)
		{
			if(mEntities[i] == mEntitiesToRemove[j])
			{
				delete mEntities[i];
				mEntities.erase(mEntities.begin()+i);
			}
		}
	}
	mEntitiesToRemove.clear();

	for(EntityVector::iterator i = mEntitiesToAdd.begin(); i != mEntitiesToAdd.end(); i++)
		mEntities.push_back(*i);
	mEntitiesToAdd.clear();

	for(EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
		(*i)->update(*this);
}

void EntityManager::drawBack(sf::RenderWindow& window)
{
	for(EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		if((*i)->getLayer() == BACK)
			(*i)->draw(window);
	}
}

void EntityManager::drawMiddle(sf::RenderWindow& window)
{
	for(EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		if((*i)->getLayer() == MIDDLE)
			(*i)->draw(window);
	}
}

void EntityManager::drawFront(sf::RenderWindow& window)
{
	for(EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		if((*i)->getLayer() == FRONT)
			(*i)->draw(window);
	}
}

int EntityManager::getEntityCount()
{
	return mEntities.size();
}

int EntityManager::getEntityCount(const std::string& tag)
{
	int count = 0;

	for(EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		if((*i)->getTag() == tag)
			count++;
	}

	return count;
}
EntityManager::EntityVector EntityManager::getEntitiesByTag(std::string& tag)
{
	EntityVector entities;
	for(EntityVector::iterator i = mEntities.begin(); i != mEntities.end(); i++)
	{
		if((*i)->getTag() == tag)
			entities.push_back(*i);
	}

	return entities;
}
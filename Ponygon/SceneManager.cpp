#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager(){}
SceneManager::~SceneManager(){}


void SceneManager::add(Scene* scene)
{
	mScenes.push_back(scene);
}

void SceneManager::remove(Scene* scene)
{
	SceneVector scenes;
	for(SceneVector::iterator i = mScenes.begin(); i != mScenes.end(); i++)
	{
		if((*i) != scene)
			scenes.push_back(*i);
	}

	mScenes = scenes;
}

void SceneManager::update()
{
	for(SceneVector::iterator i = mScenes.begin(); i != mScenes.end(); i++)
		(*i)->update();
}

void SceneManager::draw(sf::RenderWindow& window)
{
	for(SceneVector::iterator i = mScenes.begin(); i != mScenes.end(); i++)
		(*i)->draw(window);
}
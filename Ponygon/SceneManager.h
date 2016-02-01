#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>
#include <SFML/Graphics.hpp>

class Scene;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void add(Scene* scene);
	void remove(Scene* scene);

	void update();

	void draw(sf::RenderWindow& window);
private:
	typedef std::vector<Scene*> SceneVector;
	SceneVector mScenes;
};

#endif
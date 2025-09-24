#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

enum class SceneID
{
	MainMenu,
	Gameplay
};

class Scene
{
protected:	
	SceneID nextSceneID;
	sf::RenderWindow& window;
	bool wantsChange;

public:
	Scene(sf::RenderWindow& window);
	virtual ~Scene() = 0; 

	virtual void Input() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;

	virtual void HandleEvents(const sf::Event& event) = 0;

	virtual bool GetWantsChange();
	virtual void SetWantsChange(bool value);

	virtual SceneID GetNextSceneID();

};
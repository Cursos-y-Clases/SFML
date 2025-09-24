#pragma once
#include "Scene.h"
#include "Player.h"
#include "ResourceManager.h"
#include "PauseManager.h"

class Gameplay : public Scene
{
private:
	Player& player;
	PauseManager& pauseManager;
	

public:
	Gameplay(Player& player, ResourceManager& resources, sf::RenderWindow& window, 
		PauseManager& pauseManager);
	~Gameplay() override;

	void Input() override;
	void Update(float deltaTime) override;
	void Draw() override;

	void HandleEvents(const sf::Event& event) override;
};
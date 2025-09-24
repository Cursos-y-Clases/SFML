#include "Gameplay.h"

Gameplay::Gameplay(Player& player, ResourceManager& resources, sf::RenderWindow& window, PauseManager& pauseManager) 
	: Scene(window), player(player), pauseManager(pauseManager) {}

Gameplay::~Gameplay()
{
}

void Gameplay::Input()
{
	pauseManager.Input();
	if (pauseManager.GetGamePaused()) return;

	player.Input();
}

void Gameplay::Update(float deltaTime)
{
	if (pauseManager.GetGamePaused()) return;

	player.Update(deltaTime);
}

void Gameplay::Draw()
{
	player.Draw(window);
	pauseManager.Draw();	
}

void Gameplay::HandleEvents(const sf::Event& event)
{
	pauseManager.HandleEvents(event);

	if (pauseManager.GetGamePaused()) return;

	player.HandleEvents(event);	
}
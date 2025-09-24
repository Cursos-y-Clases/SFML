#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"
#include "ResourceManager.h"

class MainMenu : public Scene
{
private:

	sf::Music music;

	sf::Text* buttonText;
	sf::Text text;

	sf::Sprite* background;

	sf::Sprite* startButton;


public:
	MainMenu(ResourceManager& resources, sf::RenderWindow& window);
	~MainMenu() override;

	void Input() override;
	void Update(float deltaTime) override;
	void Draw() override;

	void HandleEvents(const sf::Event& event) override;
};
#pragma once

#include "ResourceManager.h"

#include "SFML/Graphics.hpp"
#include "Scene.h"
#include "MainMenu.h"

class PauseManager
{
	private:

		Scene*& currentScene;
		MainMenu*& mainMenu;
		sf::RenderWindow& window;

		sf::Sprite* pauseBackground;
		sf::Sprite* continueButton;
		sf::Sprite* mainMenuButton;

		bool gamePaused;

	public:
		PauseManager(ResourceManager& resources, sf::RenderWindow& window, Scene*& currentScene,
			MainMenu*& mainMenu);
		~PauseManager();

		void Input();
		void Draw();

		void HandleEvents(const sf::Event& event);

		bool GetGamePaused();

		void PauseGame();
		void UnpauseGame();

};
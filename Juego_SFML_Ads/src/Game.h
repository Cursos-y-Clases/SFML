#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Scene.h"
#include "ResourceManager.h"
#include "MainMenu.h"
#include "Gameplay.h"


class Game
{
	private:

		std::map<SceneID, Scene*> scenes;
		Scene* currentScene;

		MainMenu* mainMenu;
		Gameplay* gameplay;

		sf::RenderWindow* window;
		sf::Clock clock;

		ResourceManager resources;

		PauseManager* pauseManager;

		sf::RectangleShape testButton;
		sf::CircleShape testCollision;

		Player *player;		

		void Initialize();
		void Gameloop();
		void DeInitialize();

		void Input();
		void Update();
		void Draw();

		void HandleEvents();

		void CreateWindow();
		void DestroyWindow();

		void CreatePlayer();
		void DestroyPlayer();

		void CreateButton();
		void CreateTestCollision();


	public:

		Game();
		void Play();
};
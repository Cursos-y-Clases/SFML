#pragma once
#include <SFML/Graphics.hpp>
#include "VectorUtilities.h"
#include "Weapon.h"


class Player
{
	private:		
		sf::Sprite *sprite;
		sf::Texture texture;
		
		float speed;
		sf::Vector2f direction;

		Weapon *weapon;
		bool canShoot;

		int currentXValue;
		float animationTimer;

						
	public:		
		Player(std::string imageFilePath, sf::Vector2i spriteSheetSize);
		~Player();

		void Input();
		void Update(float deltaTime);
		void MovementInput();
		void Movement(float deltaTime);
		void Animation(float deltaTime);

		void Draw(sf::RenderWindow& window);

		sf::FloatRect GetBounds();
		
		void FireWeapon();

		void HandleEvents(const sf::Event& event);
				

};
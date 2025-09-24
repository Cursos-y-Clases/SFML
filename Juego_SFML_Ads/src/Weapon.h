#pragma once

#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


class Weapon
{
	private:

		sf::SoundBuffer buffer;
		sf::Sound* shootSound;

		bool canShoot;

		float shootTimer;
		float shootDelay;

	public:

		Weapon();
		~Weapon();

		void Update(float deltaTime);

		void Shoot(sf::Vector2f shootPosition);
};
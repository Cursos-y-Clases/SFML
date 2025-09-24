#include "Weapon.h"

Weapon::Weapon()
{
	std::string path = "../audio/sfx/shot.mp3";

	buffer.loadFromFile(path);
	shootSound = new sf::Sound(buffer);

	canShoot = true;
	shootDelay = 0.0f;
	shootTimer = shootDelay;
}

Weapon::~Weapon(){}

void Weapon::Update(float deltaTime)
{
	if (shootTimer < shootDelay)
	{
		shootTimer += deltaTime;
	}

	canShoot = shootTimer >= shootDelay;
}

void Weapon::Shoot(sf::Vector2f shootPosition)
{
	if (!canShoot) return;

	shootSound->setVolume(100);
	shootSound->play();

	std::cout << "Disparo" << std::endl;

	shootTimer = 0;
	canShoot = false;
}

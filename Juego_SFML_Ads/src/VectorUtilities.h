#pragma once
#include "SFML/Graphics.hpp"


class VectorUtilities
{
	public:
		VectorUtilities();
		virtual ~VectorUtilities() = 0;
		static sf::Vector2f NormalizeVector(sf::Vector2f vector);
};

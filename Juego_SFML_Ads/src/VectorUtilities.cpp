#include "VectorUtilities.h"

VectorUtilities::VectorUtilities() {}


sf::Vector2f VectorUtilities::NormalizeVector(sf::Vector2f vector)
{
	sf::Vector2f normalized;

	float lenght = sqrt(vector.x * vector.x + vector.y * vector.y);
	normalized = lenght > 0 ? vector / lenght : sf::Vector2f(0, 0);

	return normalized;
}


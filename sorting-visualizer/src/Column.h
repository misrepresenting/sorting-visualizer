#pragma once

#include <SFML/Graphics.hpp>

struct column : public sf::RectangleShape {
	float m_value; // not const bc we have to edit it

	column();
	// init column with value
	void init(float value);
};
#include "Column.h"
#include "constants.h"

column::column() : m_value(0), sf::RectangleShape() {};

void column::init(float value) {
	m_value = value;
	setSize(sf::Vector2f(constants::column_size, value));
}

#pragma once

#include <SFML/Graphics.hpp>


class Player {

public:

	Player();

	inline sf::RectangleShape shape() const { return m_shape; }

private:

	sf::RectangleShape m_shape;
	sf::Vector2f m_position;

};
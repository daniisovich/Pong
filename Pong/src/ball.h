#pragma once

#include <SFML/Graphics.hpp>


class Ball {

public:

	Ball();

	inline sf::CircleShape shape() const { return m_shape; }

private:
	
	sf::CircleShape m_shape;

};
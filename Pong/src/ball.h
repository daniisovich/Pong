#pragma once

#include <SFML/Graphics.hpp>


class Ball {

public:

	Ball(float x, float y, float size);

	void reset();

	inline void advance() { m_position += m_speed * m_direction; m_shape.setPosition(m_position); }
	inline sf::CircleShape shape() const { return m_shape; }
	inline sf::Vector2f position() const { return m_position; }
	
	inline void invertDirectionX() { m_direction.x = -m_direction.x; }
	inline void invertDirectionY() { m_direction.y = -m_direction.y; }

private:
	
	sf::CircleShape m_shape;
	sf::Vector2f m_position;
	sf::Vector2f m_direction{ 1.0f, 1.0f };
	float m_speed{ 1.0f };

};
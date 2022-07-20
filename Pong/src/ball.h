#pragma once

#include <SFML/Graphics.hpp>


class Ball {

public:

	Ball(uint32_t width, uint32_t height, float scale);

	void reset(uint32_t width, uint32_t height);

	inline void advance(float frametime) { m_position += m_speed * frametime * m_direction; m_shape.setPosition(m_position); }

	inline void invertDirectionX() { m_direction.x = -m_direction.x; }
	inline void invertDirectionY() { m_direction.y = -m_direction.y; }

	inline float radius() const { return m_radius; }
	inline sf::CircleShape shape() const { return m_shape; }
	inline sf::Vector2f position() const { return m_position; }

private:
	
	const float m_speed{ 0.2f };

	float m_radius;
	sf::CircleShape m_shape;

	sf::Vector2f m_position;
	sf::Vector2f m_direction;
	

};
#pragma once

#include <SFML/Graphics.hpp>


// y is inverted
enum class Direction {
	up = -1,
	down = 1,
};

struct Scale {
	float x;
	float y;
};


class Player {

public:

	Player(uint32_t width, uint32_t height, const Scale& scale);

	void move(float frametime, Direction direction, float boundary_height);
	void reset(uint32_t height);

	inline sf::RectangleShape shape() const { return m_shape; }
	inline sf::Vector2f position() const { return m_position; }

private:

	sf::Vector2f m_size;
	sf::RectangleShape m_shape;
	
	sf::Vector2f m_position;

	float m_speed{ 1.0f };

};
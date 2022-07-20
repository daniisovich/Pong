#include "ball.h"

#include <random>


float random();
sf::Vector2f randomDirection();
sf::Vector2f normalize(const sf::Vector2f& vector);


Ball::Ball(uint32_t width, uint32_t height, float scale) : 
	m_radius{ scale / 2.0f * std::min(width, height) }, 
	m_shape{m_radius}, 
	m_position{width / 2.0f, height / 2.0f},
	m_direction{ randomDirection() }
{
	m_shape.setOrigin(m_radius, m_radius);
	m_shape.setPosition(m_position);
	m_shape.setFillColor(sf::Color::White);
}

void Ball::reset(uint32_t width, uint32_t height) {

	m_position = { width / 2.0f, height / 2.0f };
	m_shape.setPosition(m_position);

	m_direction = randomDirection();

}


float random() {

	static std::mt19937 generator(std::random_device{}());
	static std::uniform_real_distribution<float> distribution{ -1.0f, 1.0f };

	return distribution(generator);

}

sf::Vector2f randomDirection() {
	sf::Vector2f random_direction{ random(), random() };
	return normalize(random_direction);
}

sf::Vector2f normalize(const sf::Vector2f& vector) {
	float length = sqrtf(vector.x * vector.x + vector.y * vector.y);
	return { vector.x / length, vector.y / length };
}
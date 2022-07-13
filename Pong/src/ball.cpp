#include "ball.h"


Ball::Ball(float x, float y, float size) : m_shape{ size }, m_position{ x, y } {
	m_shape.setPosition(m_position);
	m_shape.setFillColor(sf::Color::White);
}

void Ball::reset() {

}
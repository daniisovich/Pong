#include "player.h"


Player::Player(uint32_t width, uint32_t height, const Scale& scale) : m_size{ scale.x * width, scale.y * height }, m_shape { m_size }, m_position{ width - m_size.x, height / 2.0f } {
	m_shape.setOrigin({ m_size.x / 2.0f, m_size.y / 2.0f });
	m_shape.setPosition(m_position);
	m_shape.setFillColor(sf::Color::White);
}

void Player::move(float frametime, Direction direction, float boundary_height) {
	m_position.y += m_speed * frametime * static_cast<float>(direction); 
	m_position.y = std::max(m_size.y / 2.0f, std::min(boundary_height - m_size.y / 2.0f, m_position.y));
	m_shape.setPosition(m_position);
}

void Player::reset(uint32_t height) {
	m_position.y = height / 2.0f;
	m_shape.setPosition(m_position);
}
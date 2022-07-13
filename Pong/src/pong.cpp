#include "pong.h"

#include <string>


Pong::Pong(uint32_t width, uint32_t height) : 
	m_window{ sf::VideoMode(width, height), "Simply Pong" }, 
	m_ball{ width / 2.0f, height / 2.0f, 5.0f }, 
	m_width{ float(width) }, 
	m_height{ float(height) } 
{

}

void Pong::run() {

	while (m_window.isOpen()) {
		
		pollEvents();

		m_window.clear();
		m_window.draw(m_ball.shape());
		m_window.display();

		sf::Vector2f ball_position{ m_ball.position() };
		if (ball_position.x <= 0.0f || ball_position.x >= m_width) {
			// add point
			//resetGameState();
			//continue;
			m_ball.invertDirectionX();
		}

		if (ball_position.y <= 0.0f || ball_position.y >= m_height) {
			m_ball.invertDirectionY();
		}

		m_ball.advance();

	}

}

void Pong::resetGameState() {

	m_ball.reset();

}

void Pong::pollEvents() {
	
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			m_window.close();
	}

}
#include "pong.h"

#include <string>


Pong::Pong(uint32_t width, uint32_t height) : m_window{ sf::VideoMode(width, height), "Simply Pong" }, m_ball{} {

}

void Pong::run() {

	while (m_window.isOpen()) {
		
		pollEvents();

		m_window.clear();
		m_window.draw(m_ball.shape());
		m_window.display();

	}

}

void Pong::pollEvents() {
	
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			m_window.close();
	}

}
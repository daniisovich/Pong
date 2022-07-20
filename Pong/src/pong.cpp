#include "pong.h"

#include <string>
#include <chrono>


float getFrametime();


Pong::Pong(uint32_t width, uint32_t height) : 
	m_window{ sf::VideoMode(width, height), "Simply Pong" }, 
	m_bounds{ float(width), float(height) },
	m_ball{ width, height, 0.05f }, 
	m_player{ width, height, {0.03f, 0.2f} }
{

}

void Pong::run() {

	const float ball_size{ m_ball.radius() };
	while (m_window.isOpen()) {

		m_frametime = getFrametime();

		pollEvents();
		
		sf::Vector2f ball_position{ m_ball.position() };
		if (ball_position.x - ball_size <= 0.0f) {
			m_ball.invertDirectionX();
		}

		if (ball_position.x + ball_size >= m_bounds.width) {
			enemy_points++;
			resetGameState();
		}

		if (ball_position.y - ball_size <= 0.0f || ball_position.y + ball_size >= m_bounds.height) {
			m_ball.invertDirectionY();
		}
		m_ball.advance(m_frametime);

		m_window.clear();
		m_window.draw(m_ball.shape());
		m_window.draw(m_player.shape());
		m_window.display();

	}

}

void Pong::resetGameState() {

	m_ball.reset(m_bounds.width, m_bounds.height);
	m_player.reset(m_bounds.height);


}

void Pong::pollEvents() {
	
	sf::Event event;
	while (m_window.pollEvent(event)) {
		switch (event.type)
		{
		case sf::Event::KeyPressed: processInput(event); break;
		case sf::Event::Closed: m_window.close(); break;
		default:
			break;
		}	
	}

}

void Pong::processInput(const sf::Event& event) {

	if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
		m_player.move(m_frametime, Direction::up, m_bounds.height);
	}
	else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
		m_player.move(m_frametime, Direction::down, m_bounds.height);
	}

}

float getFrametime() {

	using time_point = std::chrono::high_resolution_clock::time_point;
	static time_point last_time{ std::chrono::high_resolution_clock::now() };
	time_point current_time{ std::chrono::high_resolution_clock::now() };

	auto delta = std::chrono::duration_cast<std::chrono::duration<double>>(current_time - last_time);
	double frametime = delta.count();

	last_time = std::chrono::high_resolution_clock::now();
	return static_cast<float>(frametime * 1000.0);

}
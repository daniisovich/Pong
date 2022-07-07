#pragma once

#include <SFML/Graphics.hpp>

#include "ball.h"


class Pong {

public:

	Pong(uint32_t width, uint32_t height);

	void run();

private:
	
	void pollEvents();

	sf::RenderWindow m_window;
	Ball m_ball;

};
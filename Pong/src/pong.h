#pragma once

#include <SFML/Graphics.hpp>

#include "ball.h"
#include "player.h"


struct Bounds {
	float width;
	float height;
};
class Pong {

public:

	Pong(uint32_t width, uint32_t height);

	void run();

private:
	
	void resetGameState();
	void pollEvents();
	void processInput(const sf::Event& event);

	sf::RenderWindow m_window;
	Bounds m_bounds;

	Ball m_ball;
	Player m_player;

	float m_frametime;

	uint32_t enemy_points{ 0 };

};
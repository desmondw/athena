#ifndef _TEXTURES_H
#define _TEXTURES_H

#include <SFML/Graphics.hpp>
#include <sstream>

class Textures
{
	private:

	public:
		const static int NUM_FRAMES = 2;
		std::vector<sf::Image> playerNormal, playerMoving, playerDrilling, playerMovingDrilling;
		sf::Image bullet, cursor;

		Textures(void);
		~Textures(void);
};

#endif
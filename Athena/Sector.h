#ifndef _SECTOR_H
#define _SECTOR_H

#include <SFML/Graphics.hpp>

#include "Math.h"

#include "Physics.h"
#include "Tile.h"

class Sector
{
	private:

	public:
		std::vector<std::vector<int>> tile;
		std::vector<int> pos;
		sf::Image texture;
		sf::Sprite sprite;

		Sector(void);
		~Sector(void);
		void createSectorTexture(Physics& physics, std::vector<Tile> blockList); //TODO: broken, only displays white image
};

#endif
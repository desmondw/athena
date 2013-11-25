#ifndef _TILE_H
#define _TILE_H

#include <SFML/Graphics.hpp>

class Tile
{
	private:

	public:
		sf::Image texture;
		sf::Sprite sprite;
		const sf::Uint8* texturePixels;
		bool passable, drillable;

		Tile(void);
		~Tile(void);
		void setImageRigid();
		void fillSprite();
};

#endif
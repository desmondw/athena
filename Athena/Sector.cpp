#include "Sector.h"

Sector::Sector(void)
{
	pos.resize(2);
}

Sector::~Sector(void)
{
}

void Sector::createSectorTexture(Physics& physics, std::vector<Tile> blockList) //TODO: broken, only displays white image
{
	std::vector<sf::Uint8> pixels(physics.SECTOR_SIZE * physics.TILE_SIZE * physics.SECTOR_SIZE * physics.TILE_SIZE * 4);
	
	for (int i=0; i<tile.size(); i++)
	{
		for (int j=0; j<tile[i].size(); j++)
		{
			pixels.push_back(*blockList[tile[i][j]].texture.GetPixelsPtr());
		}
	}

	texture.LoadFromPixels(physics.SECTOR_SIZE * physics.TILE_SIZE, physics.SECTOR_SIZE * physics.TILE_SIZE, &pixels[0]);

	texture.SetSmooth(false);
	sprite.SetImage(texture);
}
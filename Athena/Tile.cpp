#include "Tile.h"

Tile::Tile(void)
{
	
}

Tile::~Tile(void)
{
}

void Tile::setImageRigid()
{
	texture.SetSmooth(false);
}

void Tile::fillSprite()
{
	sprite.SetImage(texture);
}
#include "Physics.h"

Physics::Physics(void)
{
	PLAYER_SIZE = 64;
	ENEMY_SIZE = 32, BULLET_SIZE = 16, CURSOR_SIZE = 32;
	PLAYER_SPEED = 200, BULLET_SPEED = 1000, BULLET_SPACING = .1, ENEMY_SPEED = 100;
	ENEMY_SPAWN_RATE = 1;
	TILE_SIZE = 32, SECTOR_SIZE = 32;
	
	playerRotation = 0;
}

Physics::~Physics(void)
{
}
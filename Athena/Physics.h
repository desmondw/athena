#ifndef _PHYSICS_H
#define _PHYSICS_H

#include <SFML/Graphics.hpp>

class Physics
{
	private:

	public:
		int PLAYER_SIZE;
		int ENEMY_SIZE, BULLET_SIZE, CURSOR_SIZE;
		float PLAYER_SPEED, BULLET_SPEED, BULLET_SPACING, ENEMY_SPEED;
		float ENEMY_SPAWN_RATE;
		int TILE_SIZE, SECTOR_SIZE;

		float playerRotation;

		Physics(void);
		~Physics(void);
};

#endif
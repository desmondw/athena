#ifndef _CALCULATIONS_H
#define _CALCULATIONS_H

#include "DataStore.h"
#include "Audio.h"

#include <math.h>

class Calculations
{
	private:

	public:
		float frameTime;
		sf::Clock animationTimer;
		sf::Clock bulletTimer;
		sf::Clock enemyTimer;

		Calculations(void);
		~Calculations(void);
		void nextFrame(sf::RenderWindow& mainWindow, DataStore& data);
		void playerMovement(DataStore& data);
		void playerDrilling(DataStore& data);
		void playerCollision(DataStore& data);
		void playerTileCollision(DataStore& data, float x, float y);
		void playerRotation(DataStore& data);
		void bulletMovement(DataStore& data);
		void bulletFiring(DataStore& data);
};

#endif
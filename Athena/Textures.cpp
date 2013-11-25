#include "Textures.h"

Textures::Textures(void)
{
	std::string filePath = "bin/gfx/";

	playerNormal.resize(NUM_FRAMES);
	for (int i=0; i<NUM_FRAMES; i++)
	{
		std::ostringstream sstream;
		sstream << i;
		playerNormal[i].LoadFromFile(filePath + "PlayerNormal" + sstream.str() + ".png");
		playerNormal[i].SetSmooth(false);
		sstream.end;
	}
	
	playerMoving.resize(NUM_FRAMES);
	for (int i=0; i<NUM_FRAMES; i++)
	{
		std::ostringstream sstream;
		sstream << i;
		playerMoving[i].LoadFromFile(filePath + "PlayerMoving" + sstream.str() + ".png");
		playerMoving[i].SetSmooth(false);
		sstream.end;
	}
	
	playerDrilling.resize(NUM_FRAMES);
	for (int i=0; i<NUM_FRAMES; i++)
	{
		std::ostringstream sstream;
		sstream << i;
		playerDrilling[i].LoadFromFile(filePath + "PlayerDrilling" + sstream.str() + ".png");
		playerDrilling[i].SetSmooth(false);
		sstream.end;
	}
	
	playerMovingDrilling.resize(NUM_FRAMES);
	for (int i=0; i<NUM_FRAMES; i++)
	{
		std::ostringstream sstream;
		sstream << i;
		playerMovingDrilling[i].LoadFromFile(filePath + "PlayerMovingDrilling" + sstream.str() + ".png");
		playerMovingDrilling[i].SetSmooth(false);
		sstream.end;
	}

	bullet.LoadFromFile(filePath + "Bullet.png");
	bullet.SetSmooth(false);

	cursor.LoadFromFile(filePath + "Cursor.png");
	cursor.SetSmooth(false);
}

Textures::~Textures(void)
{
}
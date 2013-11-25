#include "DataStore.h"

DataStore::DataStore(void)
{
	settings = Settings();
	physics = Physics();
	textures = Textures();

	blockList.resize(Block::Count);
	fillBlockList();

	mousePos.resize(2);
	mousePos[0] = 0;
	mousePos[1] = 0;
}

DataStore::~DataStore(void)
{
}

void DataStore::newGame(sf::RenderWindow& mainWindow)
{
	playerPos.resize(2);
	playerPos[0] = settings.WIN_WIDTH / 2;
	playerPos[1] = settings.WIN_HEIGHT / 2;
	playerPosLast.resize(2);
	playerPosLast[0] = playerPos[0];
	playerPosLast[1] = playerPos[1];
	playerMoving = false;
	playerMovement.resize(2, 0);
	playerSector.resize(2, 0);

	sectorOrigin.resize(2, 0);

	cursorPos.resize(2);
	cameraOrigin.resize(2, 0);
	updateCamera();

	bulletList.resize(0);
	enemyList.resize(0);
	sfxQueue.resize(0);

	animationFrame = 0;

	generateGrid();
}

void DataStore::fillBlockList()
{
	std::string filePath = "bin/gfx/blocks/";
	
	blockList[Block::Empty].texture.LoadFromFile(filePath + "empty.png");
	blockList[Block::Empty].passable = true;
	blockList[Block::Empty].drillable = false;
		
	blockList[Block::Restricted].texture.LoadFromFile(filePath + "restricted.png");
	blockList[Block::Restricted].passable = false;
	blockList[Block::Restricted].drillable = false;
	
	blockList[Block::Dirt].texture.LoadFromFile(filePath + "dirt.png");
	blockList[Block::Dirt].passable = false;
	blockList[Block::Dirt].drillable = true;
	
	blockList[Block::Stone].texture.LoadFromFile(filePath + "stone.png");
	blockList[Block::Stone].passable = false;
	blockList[Block::Stone].drillable = true;

	//make images rigid and attach to sprites
	for (int i=0; i<blockList.size(); i++)
	{
		blockList[i].setImageRigid();
		blockList[i].fillSprite();
	}
}

void DataStore::generateGrid()
{
	grid.resize(3, std::vector<Sector>(3));
	sectorOrigin[0] = 1;
	sectorOrigin[1] = 1;

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			grid[i][j] = generateSector(i, j);
		}
	}
}

Sector DataStore::generateSector(int sectorIDx, int sectorIDy)
{
	Sector sector;
	sector.pos[0] = (sectorIDx - sectorOrigin[0]) * physics.SECTOR_SIZE * physics.TILE_SIZE;
	sector.pos[1] = (sectorIDy - sectorOrigin[1]) * physics.SECTOR_SIZE * physics.TILE_SIZE;

	sector.tile.resize(physics.SECTOR_SIZE, std::vector<int>(physics.SECTOR_SIZE));

	for (int i=0; i<sector.tile.size(); i++)
	{
		for (int j=0; j<sector.tile[i].size(); j++)
		{
			if (i == 0 || j == 0 || i == physics.SECTOR_SIZE-1 || j == physics.SECTOR_SIZE-1)
			{
				if (rand()%2 == 0)
					sector.tile[i][j] = Block::Stone;
				else
					sector.tile[i][j] = Block::Dirt;
			}
			else
				sector.tile[i][j] = Block::Empty;
		}
	}

	//sector.createSectorTexture(physics, blockList);

	return sector;
}

void DataStore::addBullet(float x, float y, float xSpeed, float ySpeed)
{
	std::vector<float> bullet;
	bullet.resize(4);
	bullet[0] = x;
	bullet[1] = y;
	bullet[2] = xSpeed;
	bullet[3] = ySpeed;

	bulletList.push_back(bullet);
}

void DataStore::addEnemy(float x, float y)
{
	std::vector<float> enemy;
	enemy.resize(3);
	enemy[0] = x;
	enemy[1] = y;
	enemy[2] = physics.ENEMY_SPEED;

	enemyList.push_back(enemy);
}

void DataStore::queueSound(int soundID)
{
	sfxQueue.push_back(soundID);
}

void DataStore::updateCamera()
{
	cameraOrigin[0] = playerPos[0] - (settings.WIN_WIDTH / 2);
	cameraOrigin[1] = playerPos[1] - (settings.WIN_HEIGHT / 2);
	
	camera.SetFromRect(sf::FloatRect(cameraOrigin[0], cameraOrigin[1], cameraOrigin[0] + settings.WIN_WIDTH, cameraOrigin[1] + settings.WIN_HEIGHT));

	updateCursor();
}

void DataStore::updateCursor()
{
	cursorPos[0] = mousePos[0] + cameraOrigin[0];
	cursorPos[1] = mousePos[1] + cameraOrigin[1];
}

std::vector<int> DataStore::getSector(float x, float y)
{
	std::vector<int> sector(2);
	sector[0] = x / (physics.SECTOR_SIZE * physics.TILE_SIZE);
	sector[1] = y / (physics.SECTOR_SIZE * physics.TILE_SIZE);

	if (x < 0)
		sector[0]--;
	if (y < 0)
		sector[1]--;
	
	return sector;
}

std::vector<int> DataStore::getTileID(float x, float y)
{
	std::vector<int> tileID(4);

	std::vector<int> sector = getSector(x, y);
	tileID[0] = sector[0] + sectorOrigin[0];
	tileID[1] = sector[1] + sectorOrigin[1];

	tileID[2] = (x - sector[0] * physics.SECTOR_SIZE * physics.TILE_SIZE) / physics.TILE_SIZE;
	tileID[3] = (y - sector[1] * physics.SECTOR_SIZE * physics.TILE_SIZE) / physics.TILE_SIZE;

	return tileID;
}

int DataStore::getTileType(float x, float y)
{
	std::vector<int> tileID = getTileID(x, y);
	return grid[tileID[0]][tileID[1]].tile[tileID[2]][tileID[3]];
}

void DataStore::destroyTile(std::vector<int> tileID)
{
	grid[tileID[0]][tileID[1]].tile[tileID[2]][tileID[3]] = Block::Empty;
}

void DataStore::nextAnimationFrame()
{
	if (animationFrame >= textures.NUM_FRAMES - 1)
		animationFrame = 0;
	else
		animationFrame++;
}
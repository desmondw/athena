#include "Video.h"

Video::Video(void)
{
	font.LoadFromFile("bin/arial.ttf", 30);
}

Video::~Video(void)
{
}

void Video::drawGraphics(sf::RenderWindow& mainWindow, DataStore& data)
{
	mainWindow.Clear(); //clear screen
	
	//draw world
	drawGrid(mainWindow, data);
	drawBullets(mainWindow, data);
	drawEnemies(mainWindow, data);
	drawPlayer(mainWindow, data);

	//draw gui
	drawCursor(mainWindow, data);
	if (data.settings.debugOn)
		drawDebug(mainWindow, data);

    mainWindow.Display(); //draw screen
}

void Video::drawGrid(sf::RenderWindow& mainWindow, DataStore& data)
{
	//bool withinRangeX, withinRangeY;

	//for (int i=0; i<data.grid[0][0].size(); i++)
	//{
	//	for (int j=0; j<data.grid[0][0][0].size(); j++)
	//	{
	//		withinRangeX = i * data.physics.TILE_SIZE + data.physics.TILE_SIZE > data.cameraOrigin[0] && i * data.physics.TILE_SIZE < data.cameraOrigin[0] + data.settings.WIN_WIDTH;
	//		withinRangeY = j * data.physics.TILE_SIZE + data.physics.TILE_SIZE > data.cameraOrigin[1] && j * data.physics.TILE_SIZE < data.cameraOrigin[1] + data.settings.WIN_HEIGHT;

	//		if (withinRangeX && withinRangeY) //on screen
	//		{
	//			sf::Sprite& sprite = data.blockList[data.grid[0][0][i][j]].sprite;

	//			sprite.SetX(i * data.physics.TILE_SIZE);
	//			sprite.SetY(j * data.physics.TILE_SIZE);

	//			mainWindow.Draw(sprite);
	//		}
	//	}
	//}



	//draw sector player is in and surrounding 9
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			drawSector(mainWindow, data, i, j);
		}
	}



	////draw sector player is in and surrounding 9

	//sf::Sprite& sprite = data.grid[0][0].sprite;
	////sprite.SetX(i * data.physics.SECTOR_SIZE);
	////sprite.SetY(j * data.physics.SECTOR_SIZE);

	//mainWindow.Draw(sprite);
}

void Video::drawSector(sf::RenderWindow& mainWindow, DataStore& data, int x, int y)
{
	for (int i=0; i<data.physics.SECTOR_SIZE; i++)
	{
		for (int j=0; j<data.physics.SECTOR_SIZE; j++)
		{
			sf::Sprite& sprite = data.blockList[data.grid[x][y].tile[i][j]].sprite;

			sprite.SetX(data.grid[x][y].pos[0] + i * data.physics.TILE_SIZE);
			sprite.SetY(data.grid[x][y].pos[1] + j * data.physics.TILE_SIZE);

			mainWindow.Draw(sprite);
		}
	}
}

void Video::drawPlayer(sf::RenderWindow& mainWindow, DataStore& data)
{
	float playerSize = data.physics.PLAYER_SIZE / 2;

	sf::Sprite player;
	if (data.playerMoving)
	{
		if (data.playerDrilling)
			player.SetImage(data.textures.playerMovingDrilling[data.animationFrame]);
		else
			player.SetImage(data.textures.playerMoving[data.animationFrame]);
	}
	else
	{
		if (data.playerDrilling)
			player.SetImage(data.textures.playerDrilling[data.animationFrame]);
		else
			player.SetImage(data.textures.playerNormal[data.animationFrame]);
	}
	player.SetCenter(playerSize, playerSize);
	player.SetPosition(data.playerPos[0], data.playerPos[1]);
	player.SetRotation(data.physics.playerRotation);

	mainWindow.Draw(player);
}

void Video::drawBullets(sf::RenderWindow& mainWindow, DataStore& data)
{
	float bulletSize = data.physics.BULLET_SIZE / 2;

	sf::Sprite bullet;
	bullet.SetImage(data.textures.bullet);
	bullet.SetCenter(bulletSize, bulletSize);

	for(int i=0; i<data.bulletList.size(); i++)
	{
		bullet.SetPosition(data.bulletList[i][0], data.bulletList[i][1]);
		mainWindow.Draw(bullet);
	}
}

void Video::drawEnemies(sf::RenderWindow& mainWindow, DataStore& data)
{
	//float enemySize = data.physics.ENEMY_SIZE / 2;
	//sf::Shape enemy;

	//for(int i=0; i<data.enemyList.size(); i++)
	//{
	//	enemy = sf::Shape::Rectangle((data.enemyList[i][0] - enemySize), (data.enemyList[i][1] - enemySize), (data.enemyList[i][0] + enemySize), (data.enemyList[i][1] + enemySize), data.physics.ENEMY_COLOR);
	//	mainWindow.Draw(enemy);
	//}
}

void Video::drawCursor(sf::RenderWindow& mainWindow, DataStore& data)
{
	float cursorSize = data.physics.CURSOR_SIZE / 2;

	sf::Sprite cursor;
	cursor.SetImage(data.textures.cursor);
	cursor.SetCenter(cursorSize, cursorSize);
	cursor.SetPosition(data.cursorPos[0], data.cursorPos[1]);

	mainWindow.Draw(cursor);
}

void Video::drawDebug(sf::RenderWindow& mainWindow, DataStore& data)
{
	sf::Shape box = sf::Shape::Rectangle(data.cameraOrigin[0] + 5, data.cameraOrigin[1] + 5, data.cameraOrigin[0] + 305, data.cameraOrigin[1] + 205, sf::Color(200, 200, 200, 230), 5, sf::Color(50, 50, 50, 230));
	mainWindow.Draw(box);

	std::ostringstream sstream;
	sf::String text("", font, 15);
	text.SetPosition(data.cameraOrigin[0] + 10, data.cameraOrigin[1] + 10);

	sstream << "FPS: ";
	sstream << static_cast<int>(1 / mainWindow.GetFrameTime());
	sstream << "\nRotation: ";
	sstream << data.physics.playerRotation;
	sstream << "\nPlayer Pos: ";
	sstream << data.playerPos[0];
	sstream << ", ";
	sstream << data.playerPos[1];

	std::vector<int> sector = data.getSector(data.playerPos[0], data.playerPos[1]);
	sstream << "\nSector: ";
	sstream << sector[0];
	sstream << ", ";
	sstream << sector[1];

	std::vector<int> tile = data.getTileID(data.playerPos[0], data.playerPos[1]);
	sstream << "\nSector Tile: ";
	sstream << tile[2];
	sstream << ", ";
	sstream << tile[3];

	text.SetText(sstream.str());
	sstream.end;
	
	text.SetColor(sf::Color::Black);
	mainWindow.Draw(text);
}
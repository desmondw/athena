#ifndef _DATASTORE_H
#define _DATASTORE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "Settings.h"
#include "Physics.h"
#include "Textures.h"
#include "Tile.h"
#include "Sector.h"

namespace Block
{
	enum Code
	{
		Empty,
		Restricted,
		Dirt,
		Stone,

		Count //number of blocks
	}; 
}

class DataStore
{
	private:

	public:
		struct Key
		{
			Key(): A(false), B(false), C(false), D(false), E(false), F(false), G(false), H(false), I(false), J(false), K(false), L(false), M(false), N(false), O(false), P(false), Q(false), R(false), S(false), T(false), U(false), V(false), W(false), X(false), Y(false), Z(false), Num0(false), Num1(false), Num2(false), Num3(false), Num4(false), Num5(false), Num6(false), Num7(false), Num8(false), Num9(false),
			Escape(false), LControl(false), LShift(false), LAlt(false), LSystem(false), RControl(false), RShift(false), RAlt(false), RSystem(false), Menu(false), LBracket(false), RBracket(false), SemiColon(false), Comma(false), Period(false), Quote(false), Slash(false),
			BackSlash(false), Tilde(false), Equal(false), Dash(false), Space(false), Return(false), Back(false), Tab(false), PageUp(false), PageDown(false), End(false), Home(false), Insert(false), Delete(false), Add(false), Subtract(false), Multiply(false), Divide(false), Left(false),
			Right(false), Up(false), Down(false), Numpad0(false), Numpad1(false), Numpad2(false), Numpad3(false), Numpad4(false), Numpad5(false), Numpad6(false), Numpad7(false), Numpad8(false), Numpad9(false), F1(false), F2(false), F3(false), F4(false), F5(false), F6(false), F7(false), F8(false), F9(false), F10(false),
			F11(false), F12(false), F13(false), F14(false), F15(false), Pause(false){}

			bool A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, Num0, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
			Escape, LControl, LShift, LAlt, LSystem, RControl, RShift, RAlt, RSystem, Menu, LBracket, RBracket, SemiColon, Comma, Period, Quote, Slash,
			BackSlash, Tilde, Equal, Dash, Space, Return, Back, Tab, PageUp, PageDown, End, Home, Insert, Delete, Add, Subtract, Multiply, Divide, Left,
			Right, Up, Down, Numpad0, Numpad1, Numpad2, Numpad3, Numpad4, Numpad5, Numpad6, Numpad7, Numpad8, Numpad9, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10,
			F11, F12, F13, F14, F15, Pause;
		} Key;

		struct Mouse
		{
			Mouse(): Left(false), Right(false), Middle(false), XButton1(false), XButton2(false){}

			bool Left, Right, Middle, XButton1, XButton2;
		} Mouse;

		Settings settings;
		Physics physics;
		Textures textures;

		std::vector<Tile> blockList;
		std::vector<std::vector<Sector>> grid;
		sf::View camera;
		std::vector<float> cameraOrigin;
		std::vector<float> playerPos, playerPosLast, mousePos, cursorPos; //mousePos = relative to window, cursorPos = relative to world
		bool playerMoving, playerDrilling;
		std::vector<float> playerMovement; // (x, y) ... 1=positive, -1=negative, 0=not moving
		std::vector<int> playerSector, sectorOrigin;
		std::vector<std::vector<float>> bulletList, enemyList;
		std::vector<int> sfxQueue;
		int animationFrame;

		DataStore(void);
		~DataStore(void);
		void newGame(sf::RenderWindow& mainWindow);
		void fillBlockList();
		void generateGrid();
		Sector generateSector(int sectorIDx, int sectorIDy);
		void addBullet(float x, float y, float xSpeed, float ySpeed);
		void addEnemy(float x, float y);
		void addAmmo(float x, float y, float xSpeed, float ySpeed);
		void queueSound(int soundID);
		void updateCamera();
		void updateCursor();
		std::vector<int> getSector(float x, float y);
		std::vector<int> getTileID(float x, float y);
		int getTileType(float x, float y);
		void destroyTile(std::vector<int> tileID);
		void nextAnimationFrame();
};

#endif
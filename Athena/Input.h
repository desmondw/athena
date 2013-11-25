#ifndef _INPUT_H
#define _INPUT_H

#include <SFML/Graphics.hpp>
#include "DataStore.h"
#include "Audio.h"
#include "Video.h"

class Input
{
	private:
		
	public:
		Input(void);
		~Input(void);
		void handleInput(sf::RenderWindow& mainWindow, DataStore& data);
		void keyPress(sf::Event& input, sf::RenderWindow& mainWindow, DataStore& data);
		void keyRelease(sf::Event& input, sf::RenderWindow& mainWindow, DataStore& data);
		void mousePress(sf::Event& input, sf::RenderWindow& mainWindow, DataStore& data);
		void mouseRelease(sf::Event& input, sf::RenderWindow& mainWindow, DataStore& data);
};

#endif
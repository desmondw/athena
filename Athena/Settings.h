#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <SFML/Graphics.hpp>

class Settings
{
	private:

	public:
		int WIN_WIDTH, WIN_HEIGHT;
		bool fullscreenOn, vsyncOn;
		bool debugOn;

		Settings(void);
		~Settings(void);
};

#endif
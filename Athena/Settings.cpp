#include "Settings.h"

Settings::Settings(void)
{
	fullscreenOn = false;
	vsyncOn = false;
	debugOn = true;

	WIN_WIDTH = 1440;
	WIN_HEIGHT = 900;
}

Settings::~Settings(void)
{
}
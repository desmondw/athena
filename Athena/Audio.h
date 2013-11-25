#ifndef _AUDIO_H
#define _AUDIO_H

#include <SFML/Audio.hpp>

#include "DataStore.h"

namespace Sound
{
	enum Code
	{
		Shoot,
		Drill,

		Count //number of blocks
	}; 
}

class Audio
{
	private:

	public:
		std::vector<sf::SoundBuffer> bufferList;
		std::vector<sf::Sound> soundList;

		Audio(void);
		~Audio(void);
		void fillBufferSoundLists();
		void playMusic(DataStore& data);
		void playSoundQueue(DataStore& data);
};

#endif
#include "Audio.h"

Audio::Audio(void)
{
	bufferList.resize(Sound::Count);
	soundList.resize(Sound::Count);
	fillBufferSoundLists();
}

Audio::~Audio(void)
{
}

void Audio::fillBufferSoundLists()
{
	std::string filePath = "bin/sfx/";
	
	bufferList[Sound::Shoot].LoadFromFile(filePath + "shoot.wav");
	bufferList[Sound::Drill].LoadFromFile(filePath + "drill.wav");

	soundList[Sound::Shoot].SetBuffer(bufferList[Sound::Shoot]);
	soundList[Sound::Drill].SetBuffer(bufferList[Sound::Drill]);
}

void Audio::playMusic(DataStore& data)
{

}

void Audio::playSoundQueue(DataStore& data)
{
	for (int i=0; i<data.sfxQueue.size(); i++)
	{
		soundList[data.sfxQueue[i]].Play();
	}

	data.sfxQueue.resize(0);
}
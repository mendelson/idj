/*
 * Sound.h
 *
 *  Created on: 11/05/2015
 *      Author: Vitor
 */

#ifndef SRC_SOUND_H_
#define SRC_SOUND_H_
#include <iostream>
#include "SDL_mixer.h"

class Sound{
public:
	Sound();
	Sound(std::string file);
	void Play(int times);
	void Stop();
	void Open(std::string file);
	bool IsOpen();
private:
	Mix_Chunk* chunk;
	int channel;
};


#endif /* SRC_SOUND_H_ */

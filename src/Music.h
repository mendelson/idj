#ifndef SRC_MUSIC_H_
#define SRC_MUSIC_H_

#include <SDL_mixer.h>
#include <string>

class Music{
public:
	Music();
	Music(std::string file, bool chunk = true);
	void Play(int times);
	void Stop();
	void Open(std::string file, bool chunk = true);
	bool IsOpen();
private:
	Mix_Music* musicMusic;
	Mix_Chunk* music;
	bool chunk;
};



#endif /* SRC_MUSIC_H_ */

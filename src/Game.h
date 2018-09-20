#ifndef SRC_GAME_H_
#define SRC_GAME_H_

#include <iostream>
#include <stdlib.h>
#include "SDL.h"
#include "SDL_image.h"
#include "State.h"
#include "StageState.h"
#include "TitleState.h"
#include "Camera.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <math.h>
#include <stack>

using std::cout;
using std::string;
using std::endl;

class Game{
public:
	Game(string title, int width, int height);
	~Game();
	void Run();
	SDL_Renderer* GetRenderer();
	State& GetCurrentState();
	static Game& GetInstance();
	int getWidth();
	int getHeight();
	float GetDeltaTime();
	Camera getCamera();
	void Push(State* state);
private:
	static Game* instance;
	SDL_Window* window;
	SDL_Renderer* renderer;
	State* storedState;
	int width;
	int height;
	int frameStart;
	float dt;
	void CalculateDeltaTime();
	std::stack<std::unique_ptr<State>> stateStack;
};

#endif /* SRC_GAME_H_ */

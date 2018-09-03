#ifndef SRC_STAGESTATE_H_
#define SRC_STAGESTATE_H_

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include "Music.h"
#include "Sprite.h"
#include "State.h"
#include "Timer.h"
#include "UI.h"
#include "Plataforma.h"
#include "Planet.h"
#include "Planta.h"
#include "Enemy3.h"
#include "PlanetaFundo.h"
#include "Cometa.h"
#include "Energia.h"
#include "Laser.h"
#include "EnemyTank.h"
#include "Nave.h"

class Weapon;

using std::string;

class StageState: public State {
public:
	enum SimpleWeaponName {
		BROOM, SWORD, GUN
	};

	StageState();
	~StageState();
	void Update(float deltaTime);
	void Render();
	void Pause();
	void Resume();
	static SimpleWeaponName GetWeapon();
private:
	Sprite background;
	Music music;
	UI userInterface;
	float backgroundSize;
	Weapon *activeWeapon;
	Timer musicTime;
	static SimpleWeaponName weaponNumber;
};

#endif

/*****************************************************
	* File: WeaponGun.cpp
	* Purpose: declaration of class WeaponGun
******************************************************/

#ifndef SRC_WEAPONGUN_H_
#define SRC_WEAPONGUN_H_
#include "GameObject.h"
#include "Weapon.h"
#include "Timer.h"
#include "StillAnimation.h"
#include "Player.h"
#include "Sound.h"
#include "EndState.h"
#include "StateData.h"

class WeaponGun : public Weapon{
public:
	WeaponGun(std::string file);
	~WeaponGun();
	void Update(float deltaTime);
	void Render();
	bool IsDead();
	Sprite getSprite();
	bool Is(string type);
	void NotifyCollision(GameObject&);
	Facing orientation;

private:
	bool atkFrame;
	Sprite sprite; 	//sprite is responsable to load images and textures for the game
};


#endif

/*****************************************************
 * File: WeaponGun.cpp
 * Purpose: Implementation of class WeaponGun
 ******************************************************/

#include "WeaponGun.h"

#include <SDL_keycode.h>
#include <string>

#include "Camera.h"
#include "InputManager.h"
#include "Point.h"

#define QUARTER_OF_A_TURN 90

WeaponGun::WeaponGun(std::string file) :
		sprite(file, 0.1, 2, 8) {

	// Set the weapon gun position on sprite and get position on the box

	isDead = false; //make sure the player is not dead
	sprite.SetScaleX(0.5);
	sprite.SetScaleY(0.5);
	box.setX(Player::player->box.x);
	box.setY(Player::player->box.y);
	box.setH(sprite.GetHeight());
	box.setW(sprite.GetWidth());

	atkFrame = false;

	/*
	 * Checking players orientation
	 * to turn weapon gun in he's direction
	 */
	orientation = Player::player->orientation;
	if (orientation == LEFT) {
		sprite.SetFlipH(true);
	}
}

WeaponGun::~WeaponGun() {

}

void WeaponGun::Update(float deltaTime) {

	// check if Player still have HP to update to sprite
	if (Player::player->GetHp() <= 0) {
		somaRotation = 0;
		int loopStart = 10;
		int loopEnd = 10;
		sprite.SetLoop(loopStart, loopEnd);
		sprite.Update(1);
		return;
	}

	deathCD.Update(deltaTime);
	// verify player status to adjust and to stop akt
	if (Player::player == NULL) {
		return;
	}

	box.setX(Player::player->box.x);
	box.setY(Player::player->box.y);
	orientation = Player::player->orientation;

	if (orientation == LEFT) {
		sprite.SetFlipH(true);
	} else {
		sprite.SetFlipH(false);
	}
	if (sprite.GetCurrentFrame() == 9){
		atkFrame = false;
	}

	// Use the keyboard to detect the attack and start sound atack
	// passing the initial and final Loop parameters to update the sprite
	if (InputManager::GetInstance().KeyPress(SDLK_a) || atkFrame) {
		Sound* sound = new Sound("audio/projetil.wav");
		sound->Play(0);
		delete (sound);
		atkFrame = true;
		int loopStart = 8;
		int loopEnd = 9;
		sprite.SetLoop(8,9);
	} else {
		if (Player::player->loopStart == 16 && Player::player->loopEnd == 17) {
			sprite.SetLoop(0, 0);
		} else {
			sprite.SetLoop(0, 7);
			if (Player::player->planet->somaRotation == 0){
				sprite.SetLoop(2, 2);
			}
		}
	}

	if (orientation == RIGHT)
		rotation += QUARTER_OF_A_TURN;
	else
		rotation -= QUARTER_OF_A_TURN;

	sprite.Update(deltaTime);

	if (InputManager::GetInstance().KeyPress(SDLK_d) && deathCD.Get() > 0.5) {
		isDead = true;
	}
}

void WeaponGun::Render() {
	int center = 0;

	if (orientation == RIGHT)
		center = -25;
	else
		center = 25;

	sprite.Render(box.getX() + Camera::pos.getX() + center,
			box.getY() + Camera::pos.getY());
}

bool WeaponGun::IsDead() {
	return ((Player::player == NULL) || isDead);
}

Sprite WeaponGun::getSprite() {
	return sprite;
}

bool WeaponGun::Is(string type) {
	return (type == "WeaponGun");
}

void WeaponGun::NotifyCollision(GameObject&) {

}

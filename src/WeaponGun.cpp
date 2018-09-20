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

WeaponGun::WeaponGun(std::string file) : sprite(file,0.1,2,8)
{
	isDead = false;
	sprite.SetScaleX(0.5);
	sprite.SetScaleY(0.5);
	box.setX(Player::player->box.x);
	box.setY(Player::player->box.y);
	box.setH(sprite.GetHeight());
	box.setW(sprite.GetWidth());

	atkFrame = false;

	/*
	 * Checking players orientation and if this orientation
	 * was in left direction flip is ocurred
	*/
	orientation = Player::player->orientation;
	if (orientation == LEFT) {
		sprite.SetFlipH(true);
	}
}

WeaponGun::~WeaponGun()
{

}

/*
 * update position, using position and time to realize ajust
 * with data a previous move
 * */
void WeaponGun::Update(float deltaTime)
{
	if (Player::player->GetHp() <= 0)
	{
		somaRotation = 0;
		sprite.SetLoop(10,10);
		sprite.Update(1);
		return;
	}

	deathCD.Update(deltaTime);

	if (Player::player == NULL)
		return;

	box.setX(Player::player->box.x);
	box.setY(Player::player->box.y);
	orientation = Player::player->orientation;

	if (orientation == LEFT)
		sprite.SetFlipH(true);
	else
		sprite.SetFlipH(false);

	if (sprite.GetCurrentFrame() == 9)
		atkFrame = false;

	if(InputManager::GetInstance().KeyPress(SDLK_a) || atkFrame)
	{
		Sound* sound = new Sound("audio/projetil.wav");
		sound->Play(0);
		delete(sound);
		atkFrame = true;
		sprite.SetLoop(8, 9);
	}
	else
	{
		if (Player::player->loopStart == 16 && Player::player->loopEnd == 17)
		{
			sprite.SetLoop(0,0);
		}
		else
		{
			sprite.SetLoop(0, 7);
			if (Player::player->planet->somaRotation == 0)
				sprite.SetLoop(2, 2);
		}
	}

	if (orientation == RIGHT)
		rotation += 90;
	else
		rotation -= 90;

	sprite.Update(deltaTime);

	if(InputManager::GetInstance().KeyPress(SDLK_d) && deathCD.Get() > 0.5)
	{
		isDead = true;
	}
}

void WeaponGun::Render()
{
	int c = 0;

	if (orientation == RIGHT)
		c = -25;
	else
		c = 25;

	sprite.Render(box.getX() +  Camera::pos.getX() + c,box.getY() +  Camera::pos.getY());
}

bool WeaponGun::IsDead()
{
	return ((Player::player == NULL) || isDead);
}

Sprite WeaponGun::getSprite()
{
	return sprite;
}

bool WeaponGun::Is(string type)
{
	return (type == "WeaponGun");
}

void WeaponGun::NotifyCollision(GameObject&)
{

}

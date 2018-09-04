/*
 * PontaLaser.cpp
 *
 *  Created on: 12/07/2015
 *      Author: Vitor
 *  Reviewed on: 03/09/2018
 *     Reviwer: Jacó Apolinário da Silva
 */

/* Tecnicas Usadas: T1,T4,T5 */

#include "PontaLaser.h"
#include "Camera.h"
#include "Game.h"
#include "InputManager.h"

PontaLaser::LaserTip(float x,float y,GameObject* planet, float rotation,float initialHeight,int d):sprite("img/laser.png",0,2,8) {
	this->planet = planet;

	box.x = x;
	box.setH(sprite.GetHeight());
	box.setW(sprite.GetWidth());
	this->rotation = rotation;
	this->initialHeight = initialHeight;
	float angle = rotation*3.1415/180;
	box.setX(planet->box.getCenterX() + ((planet->box.getW()/2 + planet->box.getCenterY() + initialHeight)*cos(angle)) - (box.getW()/2));
	box.setY(planet->box.getCenterY()  + ((planet->box.getH()/2 + planet->box.getCenterY() + initialHeight)*sin(angle)) - (box.getH()/2));
	sprite.SetFlipH(false);
	sprite.SetFrame(0);
	sprite.SetLoop(0,0);
	sprite.Update(0);
	this->d = d;

}

LaserTip::~LaserTip() {
	
	}

void LaserTip::Update(float deltaTime) {
	somaRotation = planet->somaRotation;
	rotation += somaRotation;

		float angle = rotation * 3.1415/180;
		box.setX(planet->box.getCenterX() + ((planet->box.getW() / 2 - 300 + initialHeight) * cos(angle)) - (box.getW()  / 2));
		box.setY(planet->box.getCenterY()  + ((planet->box.getH() / 2 - 300 + initialHeight) * sin(angle)) - (box.getH() / 2));
	}

void LaserTip::Render() {
	sprite.Render(box.getX() + Camera::pos.getX(),box.getY() +  Camera::pos.getY(),rotation + 90 + direcao);
	}

bool LaserTip::IsDead() {
	return false;
	}

Sprite LaserTip::GetSprite() {
	return sprite;
	}

void LaserTip::NotifyCollision(GameObject&) {

	}

bool LaserTip::Is(string type) {
	return (type == "LaserTip");
	}

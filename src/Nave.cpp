/*
 * Nave.cpp
 *
 *  Created on: 11/07/2015
 *      Author: Vitor
 *  Reviewed on: 02/09/2018
 * 		Reviewer: Vitor
 */

#include "Nave.h"
#include "Camera.h"
#include "Game.h"
#include "InputManager.h"
#define VERTICAL_TURN 90
#define SHIP "Nave"

const float ANGLE = 3.1415/180 /* Constant used in angle calculation */

Nave::Nave(float x,float y,GameObject* planet, float rotation,
		   	float initialHeight, string file):sp(file) {
	this->planet = planet;

	box.x = x;
	box.setH(sp.GetHeight());
	box.setW(sp.GetWidth());
	this->rotation = rotation;
	this->initialHeight = initialHeight;
	float arc = rotation * ANGLE;
	box.setX(planet->box.getCenterX() + ((planet->box.getW() / 2 +
			 planet->box.getCenterY() + initialHeight) * cos(arc)) - (box.getW() / 2));
	box.setY(planet->box.getCenterY() + ((planet->box.getH() / 2 + 
			 planet->box.getCenterY() + initialHeight) * sin(arc)) - (box.getH() / 2));
}

Nave::~Nave() {
	// TODO Auto-generated destructor stub
}

/* Update the ship position on the screen */
void Nave::Update(float deltaTimeCalculator){
	sumRotation = planet->sumRotation;
	rotation += sumRotation;

		float arc = rotation * ANGLE;
		box.setX(planet->box.getCenterX() + ((planet->box.getW() / 2 -
				 300 + initialHeight) * cos(arc)) - (box.getW() / 2));
		box.setY(planet->box.getCenterY() + ((planet->box.getH() / 2 -
				 300 + initialHeight) * sin(arc)) - (box.getH() / 2));
}

void Nave::Render(){
	sp.Render(box.getX() + Camera::pos.getX(),box.getY() +
			  Camera::pos.getY(),rotation + VERTICAL_TURN);
}

bool Nave::IsDead(){
	return false;
}

Sprite Nave::getSprite(){
	return sp;
}

void Nave::NotifyCollision(GameObject&){

}

bool Nave::Is(string type){
	return (type == SHIP);
}

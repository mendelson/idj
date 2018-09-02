/*
 * HorizontalLaser.cpp
 *
 *  Created on: 12/07/2015
 *      Author: Vitor
 * 	Reviewed on: 02/09/2018
 * 		Reviewer: Vitor
 */
#include "./HorizontalLaser.h"
#include "Camera.h"
#include "Game.h"
#include "InputManager.h"
#define ROTATION_ANGLE 180

const float ANGLE = 3.1415/180 /* Constant used in angle calculation */

HorizontalLaser::HorizontalLaser(float x,float y,GameObject* planet, float rotation,
						   float initialHeight,int frameI,int frameC)
						   :sp("img/laser.png",0,2,8),timer() {

	this->planet = planet;
	box.x = x;
	box.setH(sp.GetHeight());
	box.setW(sp.GetWidth());
	this->rotation = rotation;
	this->initialHeight = initialHeight;
	float arc = rotation * ANGLE;

	box.setX(planet->box.getCenterX() + ((planet->box.getW() / 2 + 
			 planet->box.getCenterY() + initialHeight) * cos(arc)) - 
			 (box.getW() / 2));
	box.setY(planet->box.getCenterY() + ((planet->box.getH() / 2 + 
			 planet->box.getCenterY() + initialHeight) * sin(arc)) - 
			 (box.getH() / 2));
	
	loadedFrame = frameC;
	frameInit = frameI;
	sp.SetFlipH(false);
	sp.SetFrame(frameInit - 1);
	sp.SetLoop(frameInit - 1,frameInit - 1);
	sp.Update(0);

}

HorizontalLaser::~HorizontalLaser() {
	// TODO Auto-generated destructor stub
}

/* Update the laser position on the screen */

void HorizontalLaser::Update(float dt){
	sumRotation = planet->sumRotation;
	rotation += sumRotation;

		float arc = rotation * ANGLE;
		box.setX(planet->box.getCenterX() + ((planet->box.getW() / 2 - 
				 300 + initialHeight) * cos(arc)) - (box.getW() / 2));
		box.setY(planet->box.getCenterY() + ((planet->box.getH() / 2 - 
				 300 + initialHeight) * sin(arc)) - (box.getH() / 2));
		timer.Update(dt);
		if(timer.Get() > 1){
			timer.Restart();
			if(sp.GetCurrentFrame() == frameInit - 1){
				sp.SetFrame(loadedFrame - 1);
				sp.SetLoop(loadedFrame - 1,loadedFrame - 1);
			}else{
				sp.SetFrame(frameInit - 1);
				sp.SetLoop(frameInit - 1,frameInit - 1);
			}
		}
		sp.Update(0);
}

void HorizontalLaser::Render(){
	sp.Render(box.getX() + Camera::pos.getX(),box.getY() + 
			  Camera::pos.getY(),rotation + ROTATION_ANGLE);
}

bool HorizontalLaser::IsDead(){
	return false;
}

Sprite HorizontalLaser::getSprite(){
	return sp;
}

void HorizontalLaser::NotifyCollision(GameObject&){

}

bool HorizontalLaser::Is(string type){
	return (type == "HorizontalLaser");
}

/*
 * LaserDeitado.cpp
 *
 *  Created on: 12/07/2015
 *      Author: Vitor
 */

#include "LaserDeitado.h"

#include "LaserDeitado.h"
#include "Camera.h"
#include "Game.h"
#include "InputManager.h"

LaserDeitado::LaserDeitado(float x,float y,GameObject* planet, float rotation,float alturaInicial,int frameI,int frameC):sp("img/laser.png",0,2,8),timer() {
	this->planet = planet;

	box.x = x;//int novox = x - (sp.GetFrameWidth() / 2);
	//int novoy = y - (sp.GetHeight() / 2);
	box.setH(sp.GetHeight());
	box.setW(sp.GetWidth());
	this->rotation = rotation;
	this->alturaInicial = alturaInicial;
	float arc = rotation*3.1415/180;
	box.setX(planet->box.getCenterX() + ((planet->box.getW()/2 + planet->box.getCenterY() + alturaInicial)*cos(arc)) - (box.getW()/2));
	box.setY(planet->box.getCenterY()  + ((planet->box.getH()/2 + planet->box.getCenterY() + alturaInicial)*sin(arc)) - (box.getH()/2));
	frameCarregado = frameC;
	frameInit = frameI;
	sp.SetFlipH(false);
	sp.SetFrame(frameInit-1);
	sp.SetLoop(frameInit-1,frameInit-1);
	sp.Update(0);

}

LaserDeitado::~LaserDeitado() {
	// TODO Auto-generated destructor stub
}

void LaserDeitado::Update(float dt){
	somaRotation = planet->somaRotation;
	rotation += somaRotation;

		float arc = rotation*3.1415/180;
		box.setX(planet->box.getCenterX() + ((planet->box.getW()/2 - 300 + alturaInicial)*cos(arc)) - (box.getW()/2));
		box.setY(planet->box.getCenterY()  + ((planet->box.getH()/2 - 300 + alturaInicial)*sin(arc)) - (box.getH()/2));
		timer.Update(dt);
		if(timer.Get() > 1){
			timer.Restart();
			if(sp.GetCurrentFrame() == frameInit-1){
				sp.SetFrame(frameCarregado-1);
				sp.SetLoop(frameCarregado-1,frameCarregado-1);
			}else{
				sp.SetFrame(frameInit-1);
				sp.SetLoop(frameInit-1,frameInit-1);
			}
		}
		sp.Update(0);
}

void LaserDeitado::Render(){
	sp.Render(box.getX() + Camera::pos.getX(),box.getY() +  Camera::pos.getY(),rotation+180);
}

bool LaserDeitado::IsDead(){
	return false;
}

Sprite LaserDeitado::getSprite(){
	return sp;
}

void LaserDeitado::NotifyCollision(GameObject&){

}

bool LaserDeitado::Is(string type){
	return (type == "LaserDeitado");
}

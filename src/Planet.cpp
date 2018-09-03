/*
 * Planet.cpp
 *
 *  Created on: 05/06/2015
 *      Author: Vitor
 */

#include "Planet.h"
#include "InputManager.h"
#include "Camera.h"

#define FULL_TURN FULL_TURN

Planet::Planet(float x, float y,string file,string planetMap,string mapUp,int planetNumber):sprite(file) {
	int newXPosition = x - (sprite.GetWidth()/2);
	int newYPosition = y;
	box.setX(newXPosition);
	box.setY(newYPosition);
	box.setH(sprite.GetHeight());
	box.setW(sprite.GetWidth());
	rotation = 0;
	FILE* fp;
	fp = fopen(planetMap.c_str(),"r");
	for(int i=0;i<=FULL_TURN;i++){
		fscanf(fp,"%d,",&offsetHeight[i]);
	}
	FILE* f;
	f = fopen(mapUp.c_str(),"r");
	for(int i=0;i<=FULL_TURN;i++){
		fscanf(f,"%d,",&mapUp[i]);
	}
	this->planetNumber = planetNumber;
	fclose(fp);
	fclose(f);
	free(fp);
	free(f);
}

Planet::~Planet() {
	// TODO Auto-generated destructor stub
}

void Planet::Update(float deltaTime){
		sumRotation = Player::player->sumRotation;
		rotation += sumRotation;
		while(rotation > FULL_TURN){
				rotation -= FULL_TURN;
		}
		while(rotation <0 ){
				rotation += FULL_TURN;
		}
}

void Planet::Render(){
	sprite.Render(box.getX() +  Camera::pos.getX(),box.getY() +  Camera::pos.getY(),rotation);
}


bool Planet::IsDead(){
	return false;
}

bool Planet::Is(string type){
	return type == "Planet";
}

Sprite Planet::getSprite(){
	return sprite;
}

void Planet::NotifyCollision(GameObject& object){

}

int Planet::getHeight(float rotation){
	while(rotation < 0) rotation += FULL_TURN;

	while (rotation > FULL_TURN) rotation  -= FULL_TURN;

	int auxRotation = ((int ) rotation) % FULL_TURN;
	return -offsetHeight[auxRotation] + Player::player->getSprite().GetHeight();
}

bool Planet::canMoveUp(float rotation){
	while(rotation < 0) rotation += FULL_TURN;

	while (rotation > FULL_TURN) rotation  -= FULL_TURN;
	int auxRotation = ((int ) rotation) % FULL_TURN;
	if(mapUp[auxRotation] == 1)
		return true;
	return false;

}

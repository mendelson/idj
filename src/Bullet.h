/*
 * Bullet.h
 *
 *  Created on: 16/04/2015
 *      Author: Vitor
 */

#ifndef SRC_BULLET_H_
#define SRC_BULLET_H_

#include "GameObject.h"
#include "Planet.h"
#include "Sprite.h"
#include "Point.h"
#include "Sound.h"
#include <iostream>
#include <math.h>

using std::string;
using std::cout;
using std::endl;

class Bullet : public GameObject{
public:
	Bullet(float x,float y,GameObject* planet, float angle, float alturaIncial, float speed,float maxDistance, string sprite,bool targetsPlay,int frameCount = 1);
	void Update(float dt);
	void Render();
	bool IsDead();
	Sprite getSprite();
	bool Is(string type);
	void NotifyCollision(GameObject&);
	bool targetsPlayer;
private:
	float alturaInicial;
	GameObject* planet;
	Sprite sp;
	Point speed;
	float distanceLeft;
	float angle;
	int frameCount;
};




#endif /* SRC_BULLET_H_ */

/*
 * Ship.h
 *
 *  Created on: 11/07/2015
 *      Author: Vitor
 */

#ifndef SRC_Ship_H_
#define SRC_Ship_H_
#include "GameObject.h"
#include "Timer.h"

class Ship : public GameObject{
public:
	Ship(float x,float y,GameObject* planet, float rotation,
		 float initialHeight, string file);
	~Ship();
	void Update(float deltaTimeCalculator);
	void Render();
	bool IsDead();
	Sprite getSprite();
	void NotifyCollision(GameObject&);
	virtual bool Is(string type);
private:
	Sprite sp;
	GameObject* planet;
	float initialHeight;

};

#endif /* SRC_Ship_H_ */

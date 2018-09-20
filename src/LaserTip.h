/*
 * LaserTip.h
 *
 *  Created on: 12/07/2015
 *      Author: Vitor
 */
/* Tecnicas Usadas: T1,T4,T5 */

#ifndef SRC_PONTALASER_H_
#define SRC_PONTALASER_H_

#include "GameObject.h"
#include "Timer.h"

class LaserTip : public GameObject{
public:
	LaserTip(float x,float y,GameObject* planet, float rotation,float initialHeight,int d);
	~LaserTip();
	void Update(float deltaTime);
	void Render();
	bool IsDead();
	Sprite getSprite();
	void NotifyCollision(GameObject&);
	bool Is(string type);
private:
	Sprite sprite;
	GameObject* planet;
	float initialHeight;
	int d;

};

#endif /* SRC_PONTALASER_H_ */

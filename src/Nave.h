/*
 * Nave.h
 *
 *  Created on: 11/07/2015
 *      Author: Vitor
 */

#ifndef SRC_NAVE_H_
#define SRC_NAVE_H_

#include "GameObject.h"
#include "Timer.h"


class Nave : public GameObject{
public:
	Nave(float x,float y,GameObject* planet, float rotation,float initialHeight, string file);
	~Nave();
	void Update(float dt);
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

#endif /* SRC_NAVE_H_ */

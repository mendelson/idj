/*
 * HorizontalLaser.h
 *
 *  Created on: 12/07/2015
 *      Author: Vitor
 *  Reviewed on: 02/09/2018
 * 		Reviewer: Vitor
 */

#ifndef SRC_HorizontalLaserDEITADO_H_
#define SRC_HorizontalLaserDEITADO_H_

#include "GameObject.h"
#include "Timer.h"

class HorizontalLaser : public GameObject{
public:
	HorizontalLaser(float x,float y,GameObject* planet, float rotation,
				 float alturaInicial,int frameI,int frameC);
	~HorizontalLaser();
	void Update(float dt);
	void Render();
	bool IsDead();
	Sprite getSprite();
	void NotifyCollision(GameObject&);
	bool Is(string type);
private:
	Sprite sp;
	GameObject* planet;
	float initialHeight;
	Timer timer;
	int loadedFrame;
	int frameInit;

};
#endif /* SRC_HorizontalLaserDEITADO_H_ */

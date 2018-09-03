/*
 * Energy.h
 *
 *  Created on: 28/06/2015
 *      Author: Vitor
 */

#ifndef SRC_Energy_H_
#define SRC_Energy_H_

#include "GameObject.h"

class Energy : public GameObject {
public:
		Energy(float x,float y,GameObject* planet, float rotation,float initialHeight, string file,int numberOfFrames);
		~Energy();
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
		bool dead;
		bool willDie;
};

#endif /* SRC_Energy_H_ */

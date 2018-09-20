/*
 * Planet.h
 *
 *  Created on: 05/06/2015
 *      Author: Vitor
 */

#ifndef SRC_PLANET_H_
#define SRC_PLANET_H_
#include "GameObject.h"
#include "Sprite.h"
#include "Player.h"
#include<iostream>
#include<stdio.h>

class Planet : public GameObject{
public:
		Planet(float x, float y,string file,string planetMap,string mapUp,int planetNumber);
		~Planet();
		void Update(float deltaTime);
		void Render();
		bool IsDead();
		Sprite getSprite();
		bool Is(string type);
		void NotifyCollision(GameObject&);
		int getHeight(float rotation);
		bool canMoveUp(float rotation);
private:
		Sprite sprite;
		int offsetHeight[361];
		int mapUp[361];
//	FILE* fp;
//	FILE* f;
};

#endif /* SRC_PLANET_H_ */

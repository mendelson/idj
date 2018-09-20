/*
 * Jellyfish.h
 *
 *  Created on: 29/05/2015
 *      Author: Lucas
 *  Reviewed on: 03/09/2018
 *     Reviwer: Jacó Apolinário da Silva
 */
/* Tecnicas Usadas: T1,T4,T5 */

#ifndef SRC_ENEMYJELLYFISH_H_
#define SRC_ENEMYJELLYFISH_H_
#include "Sprite.h"
#include "Point.h"
#include "GameObject.h"
#include "Timer.h"
#include "Camera.h"
#include "InputManager.h"
#include "Player.h"
#include "Planet.h"

class EnemyJellyfish : public GameObject{
public:
	EnemyJellyfish(GameObject* planet, float initialRotation, float initialHeight);
	~EnemyJellyfish();
	void Update(float deltaTime);
	void Render();
	bool IsDead();
	Sprite getSprite();
	bool Is(string type);
void NotifyCollision(GameObject&);
	void Shoot(Point pos);
private:
	Sprite sprite;
	Point speed;
	int hp;
	Timer shootcd;
	Facing orientation;
	float initialHeight;
	GameObject* planet;
};


#endif /* SRC_ENEMYJELLYFISH_H_ */

/* Tecnicas Usadas: T1,T4,T5 */

#include "EnemyJellyfish.h"
#include "Game.h"

EnemyJellyfish::EnemyJellyfish(GameObject* planet, float initialRotation, float initialHeight) : sprite("img/inimigo_01.png"),speed(),shootcd()
{
	this->planet = planet;
	sprite.SetScaleX(0.5);
	sprite.SetScaleY(0.5);
	box.setH(sprite.GetHeight());
	box.setW(sprite.GetWidth());
	rotation = initialRotation;
	float angle = rotation*3.1415/180;
	this->initialHeight = initialHeight;
	box.setX(planet->box.getCenterX() + ((planet->box.getW()  / 2 + planet->box.getCenterY() + initialHeight) * cos(angle)) - (box.getW() / 2));
	box.setY(planet->box.getCenterY()  + ((planet->box.getH() / 2 + planet->box.getCenterY() + initialHeight) * sin(angle)) - (box.getH() / 2));
	hp = 30;
	speed.x = 10;
	speed.y = 10;
	orientation = LEFT;
}

EnemyJellyfish::~EnemyJellyfish()
{

}

void EnemyJellyfish::Update(float deltaTimeCalc)
{
	Point* playerPos = new Point (Player::player->box.getCenterX(), Player::player->box.getCenterY());
	Point* currentPos = new Point (box.getCenterX(), box.getCenterY());

	shootcd.Update(deltaTime);

	if (currentPos->getDist( * playerPos) >= 300) {

		if (playerPos->x > currentPos->x) {
			orientation = RIGHT;
			sprite.SetFlipH(true);
			box.setX(box.getX() + speed.x);
		} else if (playerPos->x < currentPos->x) {
			orientation = LEFT;
			sprite.SetFlipH(false);
			box.setX(box.getX() - speed.x);
		}

		if ((playerPos->y > currentPos->y) && fabs(playerPos->y - currentPos->y) > 10) {
			box.setY(box.getY() + speed.y);
		} else if ((playerPos->y < currentPos->y) && fabs(playerPos->y - currentPos->y) > 10) {
			box.setY(box.getY() - speed.y);
		}

		} else {

		if (shootcd.Get() >= 0.5) {
			Shoot(*playerPos);
			shootcd.Restart();
		}

		if (playerPos->x > currentPos->x) {
			orientation = RIGHT;
			sprite.SetFlipH(true);
		} else if (playerPos->x < currentPos->x) {
			orientation = LEFT;
			sprite.SetFlipH(false);
		}
	}
}

void EnemyJellyfish::Render() {
	int c;
	if (orientation == RIGHT)
		c = -30;
	else
		c = 30;

	sprite.Render(box.getX() +  Camera::pos.getX() + c,box.getY() +  Camera::pos.getY());
}

bool EnemyJellyfish::IsDead() {
	return (hp <= 0);
}

Sprite EnemyJellyfish::getSprite() {
	return sprite;
}

bool EnemyJellyfish::Is(string type) {
	return (type == "EnemyJellyfish");
}

void EnemyJellyfish::NotifyCollision(GameObject&) {

}

void EnemyJellyfish::Shoot(Point pos) {
	Point* pspeed = new Point(box.getCenterX() - pos.getX(),box.getCenterY() - pos.getY());
	float angle = atan(pspeed->getY()/pspeed->getX());

	if(pspeed->getX() > 0) {
		angle += 3.141592653;
	}
	delete(pspeed);
	
}

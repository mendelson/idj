#include "Bullet.h"
#include "Camera.h"

#define PI 3.14159265359
#define HALF_TURN 180

#define NOISE "audio/projetil.wav"
#define BULLET "Bullet"
#define PLAYER "Player"

Bullet::Bullet(float x, float y, GameObject *planet, float angle,
			float initialHeight, float speed, float maxDistance,
			string Sprite, bool targetsPlay, int frameCount)
			:sprite(Sprite,0.1,1,frameCount) {

	this->planet = planet;
	this->initialHeight = initialHeight;
	box.setH(sprite.GetHeight());
	box.setW(sprite.GetWidth());
	float rotation = angle;
	float arc = rotation * PI / HALF_TURN;
	box.setX(planet->box.getCenterX() + ((planet->box.getW() / 2 +
			planet->box.getCenterY() + initialHeight) * cos(arc)));
	box.setY(planet->box.getCenterY() + ((planet->box.getH() / 2 +
			planet->box.getCenterY() + initialHeight) * sin(arc)));

	box.setX(x - sprite.GetWidth() / 2);
	box.setY(y - sprite.GetHeight() / 2);
	box.setH(sprite.GetHeight());
	box.setW(sprite.GetWidth());
	float coord = speed / sqrt(2);
	Point *aux = new Point(coord,coord);
	this->speed = *aux;
	distanceLeft = maxDistance;
	this->angle = angle;
	this->frameCount = frameCount;
	targetsPlayer = targetsPlay;
	sprite.SetLoop(0,(frameCount - 1));
	Sound *sound = new Sound(NOISE);
	sound->Play(0);
	delete(sound);
}

void Bullet::Update(float deltaTime) {
	if (sprite.GetCurrentFrame() == (frameCount - 1)) {
		sprite.SetLoop((frameCount - 1),(frameCount - 1));
	}

	box.setX(box.getX() + (deltaTime * speed.magVector() * cos(angle)));
	box.setY(box.getY() + (deltaTime * speed.magVector() * sin(angle)));
	distanceLeft -= speed.magVector() * deltaTime;
	sprite.Update(deltaTime);
}

void Bullet::Render() {
	float correctedAngle = angle * HALF_TURN / PI;
	sprite.Render(box.getX() + Camera::pos.getX(), box.getY() + Camera::pos.getY(),
				correctedAngle);
}

bool Bullet::IsDead() {
	if(distanceLeft <= 0){
		return true;
	}
	return false;
}

Sprite Bullet::getSprite() {
	return sprite;
}

bool Bullet::Is(string type) {
	return (type == BULLET);
}

void Bullet::NotifyCollision(GameObject &other) {
	if(other.Is(PLAYER)){
		distanceLeft = 0;
	}
}

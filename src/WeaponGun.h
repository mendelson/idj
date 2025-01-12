
#ifndef SRC_WEAPONGUN_H_
#define SRC_WEAPONGUN_H_
#include "GameObject.h"
#include "Weapon.h"
#include "Timer.h"
#include "StillAnimation.h"
#include "Player.h"
#include "Sound.h"
#include "EndState.h"
#include "StateData.h"

class WeaponGun : public Weapon{
public:
	WeaponGun(std::string file);
	~WeaponGun();
	void Update(float dt);
	void Render();
	bool IsDead();
	Sprite getSprite();
	bool Is(string type);
	void NotifyCollision(GameObject&);
	Facing orientation;

private:
	bool atkFrame;
	Sprite sp;
};


#endif /* SRC_WEAPONGUN_H_ */

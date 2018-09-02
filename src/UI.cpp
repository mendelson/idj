#include "UI.h"

#include <string>

#include "Player.h"
#include "StageState.h"

const float lifeX = 10;
const float lifeY = 5;
const float r = 43;
const float initAngle = 98;
const float displacementXpUnit = 6.5;

UI::UI(int requiredEnergy, int collectedEnergy) :
		requiredEnergy(requiredEnergy), /*textNewEnergy("font/Call me maybe.ttf",
		 40, Text::BLENDED, "Energia recolhida!", { 0, 0, 0 }, 350, 250),*/timer(), bgLife(
				"img/life.png", 0, 1, 11), bgXpBackground(
				"img/xp_background.png"), bgXpUnit("img/xp_unit.png"), bgSpecial(
				"img/special.png", 0, 1, 10), bgBroom("img/broom.png", 0, 1, 2), bgSword(
				"img/sword.png", 0, 1, 2), bgGun("img/gun.png", 0, 1, 2), bgEnergy(
				"img/energy_ui.png", 0, 1, 4) {
	this->bgLife.SetLoop(0, 10);
	this->bgSpecial.SetLoop(0, 9);
	this->bgEnergy.SetLoop(0, 3);
	this->bgBroom.SetLoop(0, 1);
	this->bgSword.SetLoop(0, 1);
	this->bgGun.SetLoop(0, 1);
	this->xp = 0;
	this->life = 0;
	this->special = 0;
	this->collectedEnergy = collectedEnergy;
	this->bgEnergy.SetFrame(this->collectedEnergy - 1);
	this->bgEnergy.Update(1);
	this->newEnergy = false;
	this->firstExecution = true;
	this->centerX = lifeX + (bgLife.GetFrameWidth() / 2);
	this->centerY = lifeY + (bgLife.GetHeight() / 2);
	this->xpUnitConstant = lifeX + bgLife.GetFrameWidth() + 28;
}

void UI::Update(float dt) {
	timer.Update(dt);

	if (Player::player != NULL) {
		//Life
		this->life = Player::player->GetHp();
		if (life > 100) {
			life = 100;
		} else if (life < 0) {
			life = 0;
		}

		if (this->life <= 0) {
			bgLife.SetFrame(9);
		} else if (this->life > 0 && this->life < 10) {
			bgLife.SetFrame(8);
		} else if (this->life >= 10 && this->life < 20) {
			bgLife.SetFrame(7);
		} else if (this->life >= 20 && this->life < 30) {
			bgLife.SetFrame(6);
		} else if (this->life >= 30 && this->life < 40) {
			bgLife.SetFrame(5);
		} else if (this->life >= 40 && this->life < 50) {
			bgLife.SetFrame(4);
		} else if (this->life >= 50 && this->life < 60) {
			bgLife.SetFrame(3);
		} else if (this->life >= 60 && this->life < 70) {
			bgLife.SetFrame(2);
		} else if (this->life >= 70 && this->life < 80) {
			bgLife.SetFrame(1);
		} else if (this->life >= 80 && this->life < 90) {
			bgLife.SetFrame(0);
		} else if (this->life >= 90) {
			bgLife.SetFrame(-1);
		}
		bgLife.Update(1);

		//Xp
		this->xp = Player::player->GetXp();
		if (xp > 100) {
			xp = 100;
		}

		//Weapons
		if (StageState::GetWeapon() == StageState::SimpleWeaponName::BROOM) {
			bgBroom.SetFrame(-1);
			bgSword.SetFrame(0);
			bgGun.SetFrame(0);
		} else if (StageState::GetWeapon()
				== StageState::SimpleWeaponName::SWORD) {
			bgBroom.SetFrame(0);
			bgSword.SetFrame(-1);
			bgGun.SetFrame(0);
		} else if (StageState::GetWeapon()
				== StageState::SimpleWeaponName::GUN) {
			bgBroom.SetFrame(0);
			bgSword.SetFrame(0);
			bgGun.SetFrame(-1);
		}
		bgBroom.Update(1);
		bgSword.Update(1);
		bgGun.Update(1);

		//Energy

		newEnergy = Player::player->GetEnergyUpdate();

		if (newEnergy) {
			Player::player->energyUpdate = false;
			collectedEnergy++;

			if (collectedEnergy > 3) {
				collectedEnergy = 3;
			}

			this->bgEnergy.SetFrame(collectedEnergy - 1);
			this->bgEnergy.Update(1);
			timer.Restart();
		}


		//Special
		this->special = Player::player->GetSpecial();
		if (special > 100) {
			special = 100;
		} else if (special < 0) {
			special = 0;
		}

		if (this->special >= 0 && this->special < 10) {
			bgSpecial.SetFrame(8);
		} else if (this->special >= 10 && this->special < 20) {
			bgSpecial.SetFrame(7);
		} else if (this->special >= 20 && this->special < 30) {
			bgSpecial.SetFrame(6);
		} else if (this->special >= 30 && this->special < 40) {
			bgSpecial.SetFrame(5);
		} else if (this->special >= 40 && this->special < 50) {
			bgSpecial.SetFrame(4);
		} else if (this->special >= 50 && this->special < 60) {
			bgSpecial.SetFrame(3);
		} else if (this->special >= 60 && this->special < 70) {
			bgSpecial.SetFrame(2);
		} else if (this->special >= 70 && this->special < 80) {
			bgSpecial.SetFrame(1);
		} else if (this->special >= 80 && this->special < 90) {
			bgSpecial.SetFrame(0);
		} else if (this->special >= 90) {
			bgSpecial.SetFrame(-1);
		}
		bgSpecial.Update(1);
	}
}

void UI::Render() {
	if (timer.Get() > 3) {
		firstExecution = false;
	}

	/*if ((newEnergy || timer.Get() <= 3) && !firstExecution) {
	 textNewEnergy.Render();
	 }*/

	//Life bar
	bgLife.Render(lifeX, lifeY, 0);

	//Xp bar
	int numberOfUnits = ((int) xp / 5) - 1;
	float y = lifeY + 57;
	for (int i = 0; i <= numberOfUnits; i++) {
		float x = xpUnitConstant + i * displacementXpUnit;

		bgXpUnit.Render(x, y, 0);
	}
	bgXpBackground.Render(lifeX + bgLife.GetFrameWidth() - 10, lifeY + 40, 0);

	//Weapons
	bgBroom.Render(lifeX + bgLife.GetFrameWidth() + 20, lifeY + 65, 0);
	bgSword.Render(lifeX + bgLife.GetFrameWidth() + 65, lifeY + 65, 0);
	bgGun.Render(lifeX + bgLife.GetFrameWidth() + 110, lifeY + 65, 0);

	//Energy
	bgEnergy.Render(lifeX + bgLife.GetFrameWidth() + 300, lifeY - 20, 0);
	/*cout << "collectedEnergy: " << collectedEnergy << " | "
			<< "current energy frame: " << bgEnergy.GetCurrentFrame() << endl;*/

	//Special bar
	bgSpecial.Render(lifeX + 850, lifeY, 0);
}

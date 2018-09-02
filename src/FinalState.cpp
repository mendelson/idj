#include "FinalState.h"

#include <SDL_keycode.h>
#include <ctime>

#include "Camera.h"
#include "Game.h"
#include "InputManager.h"
#include "Player.h"
#include "Point.h"
#include "Support.h"
#include "WeaponBroom.h"
#include "WeaponGun.h"
#include "WeaponSword.h"

FinalState::SimpleWeaponName FinalState::weapon;

FinalState::FinalState() :
		bg("img/BACKGROUND.png"), music("audio/fase2.ogg"), ui(3), changeWpCD() {
	quitRequested = false;
	srand((unsigned int) time(NULL));
	xBg = -1400;
	this->weapon = BROOM;

	GameObject* planet = new Planet(0, -150, "img/planetafase3.png",
			"map/mapLastPlaneta.txt", "map/mapLastSubida.txt", 3);

	GameObject* planeta1 = new PlanetaFundo(-2 * xBg, -200, planet, 0, 0,
			"img/planeta_rosa.png");
	objectArray.emplace_back(planeta1);

	GameObject* planeta2 = new PlanetaFundo(xBg, -200, planet, 0, 0,
			"img/planeta_amarelo.png");
	objectArray.emplace_back(planeta2);

	GameObject* cometa1 = new Cometa(-2 * xBg, -200, planet, 0, 0,
			"img/estrela_cadente_azul.png");
	objectArray.emplace_back(cometa1);

	GameObject* cometa2 = new Cometa(xBg, -200, planet, 0, 0,
			"img/estrela_cadente.png");
	objectArray.emplace_back(cometa2);

	objectArray.emplace_back(planet);

	GameObject* plataforma1 = new Plataforma(500, 100, planet, -60, 0,
			"img/platfase3/images/2Plataformas.png", 3);
	objectArray.emplace_back(plataforma1);

	GameObject* plataforma60 = new Plataforma(500, 100, planet, -55, 0,
			"img/platfase3/images/4Plataformas.png", 3);
	objectArray.emplace_back(plataforma60);

	GameObject* plataforma61 = new Plataforma(500, 100, planet, -50, 0,
			"img/platfase3/images/1Plataformas.png", 3);
	objectArray.emplace_back(plataforma61);

	GameObject* plataforma62 = new Plataforma(500, 100, planet, -42, 0,
			"img/platfase3/images/5Plataformas.png", 3);
	objectArray.emplace_back(plataforma62);

	GameObject* plataforma2 = new Plataforma(500, 100, planet, -53, 100,
			"img/platfase3/images/21Plataformas.png", 3);
	objectArray.emplace_back(plataforma2);

	GameObject* plataforma3 = new Plataforma(500, 100, planet, -47, 100,
			"img/platfase3/images/22Plataformas.png", 3);
	objectArray.emplace_back(plataforma3);

	GameObject* plataforma4 = new Plataforma(500, 100, planet, -43, 100,
			"img/platfase3/images/24Plataformas.png", 3);
	objectArray.emplace_back(plataforma4);

	GameObject* plataforma5 = new Plataforma(500, 100, planet, -23, 40,
			"img/platfase3/images/34Plataformas.png", 3);
	objectArray.emplace_back(plataforma5);

	GameObject* plataforma6 = new Plataforma(500, 100, planet, -18, 110,
			"img/platfase3/images/23Plataformas.png", 3);
	objectArray.emplace_back(plataforma6);

	GameObject* plataforma50 = new Plataforma(500, 100, planet, -3, 80,
			"img/platfase3/images/3Plataformas.png", 3);
	objectArray.emplace_back(plataforma50);

	GameObject* plataforma51 = new Plataforma(500, 100, planet, 0, 40,
			"img/platfase3/images/7Plataformas.png", 3);
	objectArray.emplace_back(plataforma51);

	GameObject* plataforma52 = new Plataforma(500, 100, planet, 0, 100,
			"img/platfase3/images/9Plataformas.png", 3);
	objectArray.emplace_back(plataforma52);

	GameObject* plataforma53 = new Plataforma(500, 100, planet, 3, 80,
			"img/platfase3/images/6Plataformas.png", 3);
	objectArray.emplace_back(plataforma53);

	GameObject* plataforma7 = new Plataforma(500, 100, planet, 35, 110,
			"img/platfase3/images/15Plataformas.png", 3);
	objectArray.emplace_back(plataforma7);

	GameObject* plataforma8 = new Plataforma(500, 100, planet, 40, 40,
			"img/platfase3/images/28Plataformas.png", 3);
	objectArray.emplace_back(plataforma8);

	GameObject* plataforma9 = new Plataforma(500, 100, planet, 50, 100,
			"img/platfase3/images/10Plataformas.png", 3);
	objectArray.emplace_back(plataforma9);

	GameObject* plataforma10 = new Plataforma(500, 100, planet, 62, 40,
			"img/platfase3/images/19Plataformas.png", 3);
	objectArray.emplace_back(plataforma10);

	GameObject* plataforma11 = new Plataforma(500, 100, planet, 67, 110,
			"img/platfase3/images/8Plataformas.png", 3);
	objectArray.emplace_back(plataforma11);

	GameObject* plataforma12 = new Plataforma(500, 100, planet, 90, 0,
			"img/platfase3/images/38Plataformas.png", 3);
	objectArray.emplace_back(plataforma12);

	GameObject* plataforma13 = new Plataforma(500, 100, planet, 95, 50,
			"img/platfase3/images/36Plataformas.png", 3);
	objectArray.emplace_back(plataforma13);

	GameObject* plataforma14 = new Plataforma(500, 100, planet, 100, 0,
			"img/platfase3/images/38Plataformas.png", 3);
	objectArray.emplace_back(plataforma14);

	GameObject* plataforma15 = new Plataforma(500, 100, planet, 110, 30,
			"img/platfase3/images/37Plataformas.png", 3);
	objectArray.emplace_back(plataforma15);

	GameObject* plataforma16 = new Plataforma(500, 100, planet, 115, 110,
			"img/platfase3/images/30Plataformas.png", 3);
	objectArray.emplace_back(plataforma16);

	GameObject* plataforma17 = new Plataforma(500, 100, planet, 120, 80,
			"img/platfase3/images/25Plataformas.png", 3);
	objectArray.emplace_back(plataforma17);

	GameObject* plataforma18 = new Plataforma(500, 100, planet, 123, 40,
			"img/platfase3/images/19Plataformas.png", 3);
	objectArray.emplace_back(plataforma18);

	GameObject* plataforma19 = new Plataforma(500, 100, planet, 123, 120,
			"img/platfase3/images/19Plataformas.png", 3);
	objectArray.emplace_back(plataforma19);

	GameObject* plataforma20 = new Plataforma(500, 100, planet, 126, 80,
			"img/platfase3/images/22Plataformas.png", 3);
	objectArray.emplace_back(plataforma20);

	GameObject* plataforma21 = new Plataforma(500, 100, planet, 141, 110,
			"img/platfase3/images/46Plataformas.png", 3);
	objectArray.emplace_back(plataforma21);

	GameObject* plataforma22 = new Plataforma(500, 100, planet, 156, 40,
			"img/platfase3/images/21Plataformas.png", 3);
	objectArray.emplace_back(plataforma22);

	GameObject* plataforma23 = new Plataforma(500, 100, planet, 161, 40,
			"img/platfase3/images/25Plataformas.png", 3);
	objectArray.emplace_back(plataforma23);

	GameObject* plataforma24 = new Plataforma(500, 100, planet, 185, 40,
			"img/platfase3/images/18Plataformas.png", 3);
	objectArray.emplace_back(plataforma24);

	GameObject* plataforma25 = new Plataforma(500, 100, planet, 190, 110,
			"img/platfase3/images/19Plataformas.png", 3);
	objectArray.emplace_back(plataforma25);

	GameObject* plataforma26 = new Plataforma(500, 100, planet, 195, 40,
			"img/platfase3/images/23Plataformas.png", 3);
	objectArray.emplace_back(plataforma26);

	GameObject* plataforma27 = new Plataforma(500, 100, planet, 197, 110,
			"img/platfase3/images/34Plataformas.png", 3);
	objectArray.emplace_back(plataforma27);

	GameObject* plataforma28 = new Plataforma(500, 100, planet, 240, 40,
			"img/platfase3/images/28Plataformas.png", 3);
	objectArray.emplace_back(plataforma28);

	GameObject* plataforma29 = new Plataforma(500, 100, planet, 250, 110,
			"img/platfase3/images/20Plataformas.png", 3);
	objectArray.emplace_back(plataforma29);

	GameObject* plataforma30 = new Plataforma(500, 100, planet, 260, 40,
			"img/platfase3/images/29Plataformas.png", 3);
	objectArray.emplace_back(plataforma30);

	GameObject* energia1 = new Energia(500, 0, planet, 135, 300,
			"img/energia_fase_3.png", 5);
	objectArray.emplace_back(energia1);

	GameObject* energia2 = new Energia(500, 0, planet, 197, 300,
			"img/energia_fase_3.png", 5);
	objectArray.emplace_back(energia2);

	GameObject* energia3 = new Energia(500, 0, planet, -15, 300,
			"img/energia_fase_3.png", 5);
	objectArray.emplace_back(energia3);

	GameObject* nave = new Nave(500, 0, planet, -89.5, 100,
			"img/nave-desligada.png");
	objectArray.emplace_back(nave);

	GameObject* laserEterno = new LaserDeitado(500, 0, planet, -50, 0, 3, 3);
	objectArray.emplace_back(laserEterno);

	GameObject* pontaLaser1 = new PontaLaser(500, 0, planet, -55, 0, -90);
	objectArray.emplace_back(pontaLaser1);

	GameObject* laserEterno2 = new LaserDeitado(500, 0, planet, -45, 0, 6, 6);
	objectArray.emplace_back(laserEterno2);

	GameObject* pontaLaser2 = new PontaLaser(500, 0, planet, -46, 0, -90);
	objectArray.emplace_back(pontaLaser2);

	GameObject* laserEterno3 = new LaserDeitado(500, 0, planet, -15, 40, 1, 3);
	objectArray.emplace_back(laserEterno3);

	GameObject* pontaLaser3 = new PontaLaser(500, 0, planet, -20, 40, -90);
	objectArray.emplace_back(pontaLaser3);

	GameObject* laser4 = new LaserDeitado(500, 0, planet, -20, 110, 1, 3);
	objectArray.emplace_back(laser4);

	GameObject* pontaLaser4 = new PontaLaser(500, 0, planet, -25, 110, -90);
	objectArray.emplace_back(pontaLaser4);

	GameObject* laser5 = new LaserDeitado(500, 0, planet, 0, 0, 6, 6);
	objectArray.emplace_back(laser5);

	GameObject* pontaLaser5 = new PontaLaser(500, 0, planet, -1, 0, -90);
	objectArray.emplace_back(pontaLaser5);

	GameObject* laser6 = new Laser(500, 0, planet, 10, 150, 1, 8);
	objectArray.emplace_back(laser6);

	GameObject* pontaLaser6 = new PontaLaser(500, 0, planet, 10, 500, 180);
	objectArray.emplace_back(pontaLaser6);
//
//	GameObject* laser = new Laser(500,0,planet,240,200,1,8);
//	objectArray.emplace_back(laser);

	GameObject* player = new Player(0, 0, planet);
	objectArray.emplace_back(player);
	Camera::Follow(player);

	GameObject* support = new Support(planet);
	objectArray.emplace_back(support);

	activeWeapon = new WeaponBroom("img/Sprites_Bracos_LUP.png");
	//GameObject* weapon = new WeaponSword("img/Sprites_Espada_LUP.png");
	objectArray.emplace_back(activeWeapon);

	GameObject* e1 = new Enemy3(500, 0, planet, -15, 0);
	objectArray.emplace_back(e1);
	GameObject* e2 = new Enemy3(500, 0, planet, 40, 0);
	objectArray.emplace_back(e2);
	GameObject* e3 = new Enemy3(500, 0, planet, 50, 0);
	objectArray.emplace_back(e3);
	GameObject* e4 = new Enemy3(500, 0, planet, 60, 0);
	objectArray.emplace_back(e4);
	GameObject* e5 = new Enemy3(500, 0, planet, 120, 0);
	objectArray.emplace_back(e5);
	GameObject* e6 = new Enemy3(500, 0, planet, 140, 0);
	objectArray.emplace_back(e6);
	GameObject* e7 = new Enemy3(500, 0, planet, 200, 0);
	objectArray.emplace_back(e7);
	GameObject* e8 = new Enemy3(500, 0, planet, 210, 0);
	objectArray.emplace_back(e8);
	GameObject* e9 = new Enemy3(500, 0, planet, 240, 0);
	objectArray.emplace_back(e9);
	GameObject* e10 = new Enemy3(500, 0, planet, 300, 0);
	objectArray.emplace_back(e10);

	//rotacaoPlaneta = 0;
	//raioPlaneta = 1000;

	//GameObject* alien = new Alien(512,300,5,(rand()%5) + 3);
	//objectArray.emplace_back(alien);
	//GameObject* alien2 = new Alien(300,512,5,(rand()%5) + 3);
	//objectArray.emplace_back(alien2);
	//GameObject* alien3 = new Alien(1000,1000,5,(rand()%5) + dd3);
	//objectArray.emplace_back(alien3);

	music.Play(-1);
}

void FinalState::Update(float dt) {
//	if(SDL_QuitRequested()){
//		quitRequested = true;
//	}

	changeWpCD.Update(dt);

	if (InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)) {
		std::cout
				<< InputManager::GetInstance().GetMouseX() - Camera::pos.getX()
				<< std::endl;
		std::cout
				<< InputManager::GetInstance().GetMouseY() - Camera::pos.getY()
				<< std::endl;

	}

	if (InputManager::GetInstance().KeyPress(SDLK_d)
			&& (changeWpCD.Get() > 0.5)) {
		changeWpCD.Restart();
		if (activeWeapon->Is("WeaponBroom")) {
			activeWeapon = new WeaponSword("img/Sprites_Espada_LUP.png");
			this->weapon = SWORD; //Sword
		} else if (activeWeapon->Is("WeaponSword")) {
			activeWeapon = new WeaponGun("img/Sprites_Gun_LUP.png");
			this->weapon = GUN; //Gun
		} else if (activeWeapon->Is("WeaponGun")) {
			activeWeapon = new WeaponBroom("img/Sprites_Bracos_LUP.png");
			this->weapon = BROOM; //Broom
		}
		objectArray.emplace_back(activeWeapon);
	}

	//float somaRotation = Player::player->somaRotation;
	//xBg += somaRotation;
	Camera::Update(dt);
	quitRequested = InputManager::GetInstance().QuitRequested();
	popRequested = InputManager::GetInstance().KeyPress(ESCAPE_KEY);
	UpdateArray(dt);
	ui.Update(dt);

	//verifica fim da fase
	if (Player::player->deveMudarDeFase) {
		popRequested = true;
		Player::player->deveMudarDeFase = false;
	}
}

void FinalState::Render() {
	if (Player::player->GetHp() <= 0
			&& Player::player->deathAnimation.Get() > 1.4) {
		Sprite* black = new Sprite("img/blank.png");
		black->Render(0, 0);
		delete black;
		return;
	}

	bg.Render(xBg, 0);
	RenderArray();
	ui.Render();
}

FinalState::~FinalState() {
	objectArray.clear();
}

void FinalState::Pause() {
	music.Stop();
	objectArray.clear();

	State* finalState = new FinalState();
	Game::GetInstance().Push(finalState);
}

void FinalState::Resume() {
	music.Play(-1);
}

FinalState::SimpleWeaponName FinalState::GetWeapon() {
	return weapon;
}

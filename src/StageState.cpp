#include "StageState.h"

#include <SDL_keycode.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Camera.h"
#include "Enemy3.h"
#include "InputManager.h"
#include "Planet.h"
#include "Planta.h"
#include "Plataforma.h"
#include "Player.h"
#include "Point.h"
#include "Support.h"
#include "WeaponBroom.h"
#include "WeaponGun.h"
#include "WeaponSword.h"

#define BACKGROUND_IMG "img/BACKGROUND.png"
#define PLANET_LEVEL1 "img/planetafase1.png"
#define PINK_PLANET "img/planeta_rosa.png"
#define YELLOW_PLANET "img/planeta_amarelo.png"
#define SHOOTING_STAR_BLUE "img/estrela_cadente_azul.png"
#define SHOOTING_STAR "img/estrela_cadente.png")
#define PLANT_IMG "img/plataformas/2200/planta.png"
#define ENERGY_IMG "img/ENERGIA_V1.png"
#define SHIP_SHUT_DOWN "img/nave-desligada.png"
#define LUPS_ARMS "img/Sprites_Bracos_LUP.png"
#define SWORD_IMG "img/Sprites_Espada_LUP.png"
#define GUN_IMG "img/Sprites_Gun_LUP.png"
#define BLANK_IMG "img/blank.png"

#define PLATFORM_2200_03 "img/plataformas/2200/plataformas2200_03.png"
#define PLATFORM_2200_05 "img/plataformas/2200/plataformas2200_05.png"
#define PLATFORM_2200_08 "img/plataformas/2200/plataformas2200_08.png"
#define PLATFORM_2200_10 "img/plataformas/2200/plataformas2200_10.png"
#define PLATFORM_2200_13 "img/plataformas/2200/plataformas2200_13.png"
#define PLATFORM_2200_15 "img/plataformas/2200/plataformas2200_15.png"
#define PLATFORM_2200_17 "img/plataformas/2200/plataformas2200_17.png"
#define PLATFORM_2200_19 "img/plataformas/2200/plataformas2200_19.png"
#define PLATFORM_2200_21 "img/plataformas/2200/plataformas2200_21.png"
#define PLATFORM_2200_23 "img/plataformas/2200/plataformas2200_23.png"
#define PLATFORM_2200_35 "img/plataformas/2200/plataformas2200_35.png"
#define PLATFORM_2200_37 "img/plataformas/2200/plataformas2200_37.png"
#define PLATFORM_2200_39 "img/plataformas/2200/plataformas2200_39.png"
#define PLATFORM_2200_41 "img/plataformas/2200/plataformas2200_41.png"
#define PLATFORM_2200_44 "img/plataformas/2200/plataformas2200_44.png"
#define PLATFORM_2200_47 "img/plataformas/2200/plataformas2200_47.png"
#define PLATFORM_2200_50 "img/plataformas/2200/plataformas2200_50.png"

#define MUSIC_AUDIO "audio/fase1.ogg"

#define PLANET_MAP "map/mapPlaneta.txt"
#define MAP_UP "map/mapSubida.txt"

#define WEAPON_BROOM "WeaponBroom"
#define WEAPON_GUN "WeaponGun"
#define WEAPON_SWORD "WeaponSword"

StageState::WeaponName_lazy StageState::weapon;

StageState::StageState() :bg(BACKGROUND_IMG), music(MUSIC_AUDIO), ui(3),
						  changeWpCD() {
	quitRequested = false;
	srand((unsigned int) time(NULL));
	xBg = -1400;
	this->weapon = BROOM;


	GameObject* planet = new Planet(0,-100, PLANET_LEVEL1, PLANET_MAP, MAP_UP,1);


	GameObject* planeta1 = new PlanetaFundo(-2*xBg,-200,planet,0,0,PINK_PLANET);
	objectArray.emplace_back(planeta1);

	GameObject* planeta2 = new PlanetaFundo(xBg,-200,planet,0,0, YELLOW_PLANET);
	objectArray.emplace_back(planeta2);

	GameObject* cometa1 = new Cometa(-2*xBg,-200,planet,0,0,SHOOTING_STAR_BLUE);
	objectArray.emplace_back(cometa1);

	GameObject* cometa2 = new Cometa(xBg,-200,planet,0,0,SHOOTING_STAR;
	objectArray.emplace_back(cometa2);

	objectArray.emplace_back(planet);

	GameObject* plataforma1 = new Plataforma(500,100,planet,-30,100,PLATFORM_2200_44);
	objectArray.emplace_back(plataforma1);

	GameObject* plataforma2 = new Plataforma(500,0,planet,-25,150,PLATFORM_2200_39);
	objectArray.emplace_back(plataforma2);

	GameObject* plataforma3 = new Plataforma(500,0,planet,-20,200,PLATFORM_2200_13);
	objectArray.emplace_back(plataforma3);

	GameObject* plataforma4 = new Plataforma(500,0,planet,-15,250,PLATFORM_2200_50);
	objectArray.emplace_back(plataforma4);

	GameObject* planta1 = new Planta(500,0,planet,-1,50, PLANT_IMG);
	objectArray.emplace_back(planta1);

	GameObject* planta2 = new Planta(500,0,planet,39,50, PLANT_IMG);
	objectArray.emplace_back(planta2);

	GameObject* plataforma5 = new Plataforma(500,0,planet,47,200,PLATFORM_2200_15);
	objectArray.emplace_back(plataforma5);

	GameObject* planta3 = new Planta(500,0,planet,53,50, PLANT_IMG);
	objectArray.emplace_back(planta3);

	GameObject* plataforma6 = new Plataforma(500,0,planet,75,150,PLATFORM_2200_03);
	objectArray.emplace_back(plataforma6);

	GameObject* plataforma7 = new Plataforma(500,0,planet,80,220, PLATFORM_2200_05);
	objectArray.emplace_back(plataforma7);

	GameObject* plataforma9 = new Plataforma(500,0,planet,85,280,PLATFORM_2200_17);
	objectArray.emplace_back(plataforma9);

	GameObject* plataforma10 = new Plataforma(500,0,planet,90,330,PLATFORM_2200_21);
	objectArray.emplace_back(plataforma10);

	GameObject* plataforma11 = new Plataforma(500,0,planet,95,330,PLATFORM_2200_19);
	objectArray.emplace_back(plataforma11);

	GameObject* plataforma12 = new Plataforma(500,0,planet,100,310, PLATFORM_2200_47);
	objectArray.emplace_back(plataforma12);

	GameObject* plataforma13 = new Plataforma(500,0,planet,105,250,PLATFORM_2200_10);
	objectArray.emplace_back(plataforma13);

	GameObject* plataforma14 = new Plataforma(500,0,planet,140,150,PLATFORM_2200_23);
	objectArray.emplace_back(plataforma14);

	GameObject* plataforma15 = new Plataforma(500,0,planet,150,150,PLATFORM_2200_08);
	objectArray.emplace_back(plataforma15);

	GameObject* plataforma16 = new Plataforma(500,0,planet,170,150, PLATFORM_2200_35);
	objectArray.emplace_back(plataforma16);

	GameObject* plataforma17 = new Plataforma(500,0,planet,175,150,PLATFORM_2200_19);
	objectArray.emplace_back(plataforma17);

	GameObject* plataforma18 = new Plataforma(500,0,planet,180,150, PLATFORM_2200_37);
	objectArray.emplace_back(plataforma18);

	GameObject* plataforma19 = new Plataforma(500,0,planet,218,150,PLATFORM_2200_15);
	objectArray.emplace_back(plataforma19);

	GameObject* planta4 = new Planta(500,0,planet,221.5,50,PLANT_IMG);
	objectArray.emplace_back(planta4);

	GameObject* plataforma20 = new Plataforma(500,0,planet,224,200, PLATFORM_2200_41);
	objectArray.emplace_back(plataforma20);

	GameObject* planta5 = new Planta(500,0,planet,226.5,50,PLANT_IMG);
	objectArray.emplace_back(planta5);

	GameObject* plataforma21 = new Plataforma(500,0,planet,230,150, PLATFORM_2200_41);
	objectArray.emplace_back(plataforma21);

	GameObject* plataforma22 = new Plataforma(500,0,planet,230,250, PLATFORM_2200_41);
	objectArray.emplace_back(plataforma22);

	GameObject* planta6 = new Planta(500,0,planet,231,50,PLANT_IMG);
	objectArray.emplace_back(planta6);

	GameObject* plataforma23 = new Plataforma(500,0,planet,236,200, PLATFORM_2200_41);
	objectArray.emplace_back(plataforma23);

	GameObject* planta7 = new Planta(500,0,planet,236,50,PLANT_IMG);
	objectArray.emplace_back(planta7);

	GameObject* plataforma24 = new Plataforma(500,0,planet,240,150,PLATFORM_2200_15);
	objectArray.emplace_back(plataforma24);

	GameObject* energia1 = new Energia(500,0,planet,90,400,ENERGY_IMG,4);
	objectArray.emplace_back(energia1);

	GameObject* energia2 = new Energia(500,0,planet,47,400,ENERGY_IMG,4);
	objectArray.emplace_back(energia2);

	GameObject* energia3 = new Energia(500,0,planet,230,400,ENERGY_IMG,4);
	objectArray.emplace_back(energia3);

	GameObject* nave = new Nave(500,0,planet,-89,150,SHIP_SHUT_DOWN);
	objectArray.emplace_back(nave);

//	GameObject* laserEterno = new Laser(500,0,planet,-90,200,8,8);
//	objectArray.emplace_back(laserEterno);
//
//	GameObject* laser = new Laser(500,0,planet,240,200,1,8);
//	objectArray.emplace_back(laser);

	GameObject* player = new Player(0,0,planet);
	objectArray.emplace_back(player);
	Camera::Follow(player);

	GameObject* support = new Support(planet);
	objectArray.emplace_back(support);

	activeWeapon = new WeaponBroom(LUPS_ARMS);
	//GameObject* weapon = new WeaponSword(SWORD_IMG);
	objectArray.emplace_back(activeWeapon);

	GameObject* tank1 = new EnemyTank(500, 0,planet,-50,50);
	objectArray.emplace_back(tank1);

	GameObject* tank2 = new EnemyTank(500, 0,planet,-40,50);
	objectArray.emplace_back(tank2);

	GameObject* tank3 = new EnemyTank(500, 0,planet,-30,50);
	objectArray.emplace_back(tank3);

	GameObject* tank4 = new EnemyTank(500, 0,planet,45,50);
	objectArray.emplace_back(tank4);

	GameObject* tank5 = new EnemyTank(500, 0,planet,140,50);
	objectArray.emplace_back(tank5);

	GameObject* tank6 = new EnemyTank(500, 0,planet,150,50);
	objectArray.emplace_back(tank6);

	GameObject* tank7 = new EnemyTank(500, 0,planet,160,50);
	objectArray.emplace_back(tank7);

	GameObject* tank8 = new EnemyTank(500, 0,planet,170,50);
	objectArray.emplace_back(tank8);

	GameObject* tank9 = new EnemyTank(500, 0,planet,180,50);
	objectArray.emplace_back(tank9);

	GameObject* tank10 = new EnemyTank(500, 0,planet,190,50);
	objectArray.emplace_back(tank10);



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

void StageState::Update(float dt) {
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

	if(InputManager::GetInstance().KeyPress(SDLK_d) && (changeWpCD.Get() > 0.5))
	{
		changeWpCD.Restart();
		if (activeWeapon->Is(WEAPON_BROOM))
		{
			activeWeapon = new WeaponSword(SWORD_IMG);
			this->weapon = SWORD; //Sword
		}
		else if (activeWeapon->Is(WEAPON_SWORD))
		{
			activeWeapon = new WeaponGun(GUN_IMG);
			this->weapon = GUN; //Gun
		}
		else if (activeWeapon->Is(WEAPON_GUN))
		{
			activeWeapon = new WeaponBroom(LUPS_ARMS);
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
	if(Player::player->deveMudarDeFase){
		popRequested = true;
		Player::player->deveMudarDeFase = false;
	}
}

void StageState::Render() {
	if(Player::player->GetHp() <= 0 && Player::player->deathAnimation.Get() > 1.4)
	{
		Sprite* black = new Sprite(BLANK_IMG);
		black->Render(0,0);
		delete black;
		return;
	}

	bg.Render(xBg, 0);
	RenderArray();
	ui.Render();
}

StageState::~StageState() {
	objectArray.clear();
}

void StageState::Pause() {
	music.Stop();
	objectArray.clear();

}

void StageState::Resume() {
	music.Play(-1);

}

StageState::WeaponName_lazy StageState::CheckWeapon()
{
	return weapon;
}

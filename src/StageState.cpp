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
#define SHOOTING_STAR "img/estrela_cadente.png"
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

#define MUSIC_LEVEL1 "audio/fase1.ogg"

#define PLANET_MAP "map/mapPlaneta.txt"
#define MAP_UP "map/mapSubida.txt"

#define WEAPON_BROOM "WeaponBroom"
#define WEAPON_GUN "WeaponGun"
#define WEAPON_SWORD "WeaponSword"

#define HALF_MUSIC_TIME 0.5
#define DEATH_TIME 1.4

#define MAX_POS_DISTANCE 500
#define MAX_NEG_DISTANCE - 200
#define HALF_POS_DISTANCE 250
#define CENTER 0
#define PLAT_INITIAL_HEIGHT 100
#define PLANT_HEIGHT 50
#define ENERGY_HEIGHT 400
#define ENERGY_FRAME 4
#define TANK_HEIGHT 50

StageState::SimpleWeaponName StageState::weaponNumber;

StageState::StageState() :background(BACKGROUND_IMG), music(MUSIC_LEVEL1),
						  userInterface(3), musicTime() {
	quitRequested = false;
	srand((unsigned int) time(NULL));
	this->weaponNumber = BROOM;

	GameObject *planet = new Planet(CENTER, -100, PLANET_LEVEL1, PLANET_MAP,
									MAP_UP,1);

	backgroundSize = -1400;

	GameObject *planet1 = new PlanetaFundo(-2 * backgroundSize, MAX_NEG_DISTANCE,
										   planet, 0, 0, PINK_PLANET);
	objectArray.emplace_back(planet1);

	GameObject *planet2 = new PlanetaFundo(backgroundSize, MAX_NEG_DISTANCE,
										   planet, 0, 0, YELLOW_PLANET);
	objectArray.emplace_back(planet2);

	GameObject *comet1 = new Cometa(-2 * backgroundSize, MAX_NEG_DISTANCE, planet,
									0, 0, SHOOTING_STAR_BLUE);
	objectArray.emplace_back(comet1);

	GameObject *comet2 = new Cometa(backgroundSize, MAX_NEG_DISTANCE, planet,
									0, 0, SHOOTING_STAR);
	objectArray.emplace_back(comet2);

	objectArray.emplace_back(planet);

	GameObject *platform1 = new Plataforma(MAX_POS_DISTANCE, 100, planet, -30,
										  PLAT_INITIAL_HEIGHT, PLATFORM_2200_44);
	objectArray.emplace_back(platform1);

	GameObject *platform2 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, -25,
										  PLAT_INITIAL_HEIGHT + 50, PLATFORM_2200_39);
	objectArray.emplace_back(platform2);

	GameObject *platform3 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, -20,
										   2 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_13);
	objectArray.emplace_back(platform3);

	GameObject *platform4 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, -15,
										   HALF_POS_DISTANCE, PLATFORM_2200_50);
	objectArray.emplace_back(platform4);

	GameObject *plant1 = new Planta(MAX_POS_DISTANCE, CENTER, planet, -1,
									PLANT_HEIGHT, PLANT_IMG);
	objectArray.emplace_back(plant1);

	GameObject *plant2 = new Planta(MAX_POS_DISTANCE, CENTER, planet, 39,
									PLANT_HEIGHT, PLANT_IMG);
	objectArray.emplace_back(plant2);

	GameObject *platform5 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 47,
										   2 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_15);
	objectArray.emplace_back(platform5);

	GameObject *plant3 = new Planta(MAX_POS_DISTANCE, CENTER, planet, 53,
									PLANT_HEIGHT, PLANT_IMG);
	objectArray.emplace_back(plant3);

	GameObject *platform6 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 75,
										   PLAT_INITIAL_HEIGHT + 50, PLATFORM_2200_03);
	objectArray.emplace_back(platform6);

	GameObject *platform7 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 80,
										   2.2 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_05);
	objectArray.emplace_back(platform7);

	GameObject *platform9 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 85,
										   2.8 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_17);
	objectArray.emplace_back(platform9);

	GameObject *platform10 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 90,
											3.3 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_21);
	objectArray.emplace_back(platform10);

	GameObject *platform11 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 95,
											3.3 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_19);
	objectArray.emplace_back(platform11);

	GameObject *platform12 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 100,
											3.1 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_47);
	objectArray.emplace_back(platform12);

	GameObject *platform13 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 105,
		 									HALF_POS_DISTANCE, PLATFORM_2200_10);
	objectArray.emplace_back(platform13);

	GameObject *platform14 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 140,
											1.5 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_23);
	objectArray.emplace_back(platform14);

	GameObject *platform15 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 150,
											1.5 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_08);
	objectArray.emplace_back(platform15);

	GameObject *platform16 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 170,
											1.5 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_35);
	objectArray.emplace_back(platform16);

	GameObject *platform17 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 175,
											1.5 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_19);
	objectArray.emplace_back(platform17);

	GameObject *platform18 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 180,
											1.5 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_37);
	objectArray.emplace_back(platform18);

	GameObject *platform19 = new Plataforma(MAX_POS_DISTANCE, CENTER, planet, 218,
											1.5 * PLAT_INITIAL_HEIGHT,PLATFORM_2200_15);
	objectArray.emplace_back(platform19);

	GameObject *plant4 = new Planta(MAX_POS_DISTANCE,CENTER, planet, 221.5,
									PLANT_HEIGHT, PLANT_IMG);
	objectArray.emplace_back(plant4);

	GameObject *platform20 = new Plataforma(MAX_POS_DISTANCE,CENTER, planet, 224,
											2 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_41);
	objectArray.emplace_back(platform20);

	GameObject *plant5 = new Planta(MAX_POS_DISTANCE,CENTER, planet, 226.5,
									PLANT_HEIGHT, PLANT_IMG);
	objectArray.emplace_back(plant5);

	GameObject *platform21 = new Plataforma(MAX_POS_DISTANCE,CENTER, planet, 230,
											1.5 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_41);
	objectArray.emplace_back(platform21);

	GameObject *platform22 = new Plataforma(MAX_POS_DISTANCE,CENTER, planet, 230,
											HALF_POS_DISTANCE, PLATFORM_2200_41);
	objectArray.emplace_back(platform22);

	GameObject *plant6 = new Planta(MAX_POS_DISTANCE,CENTER, planet, 231,
									PLANT_HEIGHT, PLANT_IMG);
	objectArray.emplace_back(plant6);

	GameObject *platform23 = new Plataforma(MAX_POS_DISTANCE,CENTER, planet, 236,
											2 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_41);
	objectArray.emplace_back(platform23);

	GameObject *plant7 = new Planta(MAX_POS_DISTANCE,CENTER, planet, 236,
									PLANT_HEIGHT, PLANT_IMG);
	objectArray.emplace_back(plant7);

	GameObject *platform = new Plataforma(MAX_POS_DISTANCE,CENTER, planet, 240,
										1.5 * PLAT_INITIAL_HEIGHT, PLATFORM_2200_15);
	objectArray.emplace_back(platform);

	GameObject *energy1 = new Energia(MAX_POS_DISTANCE,CENTER, planet, 90,
									  ENERGY_HEIGHT, ENERGY_IMG, ENERGY_FRAME);
	objectArray.emplace_back(energy1);

	GameObject *energy2 = new Energia(MAX_POS_DISTANCE,CENTER, planet, 47,
									  ENERGY_HEIGHT, ENERGY_IMG, ENERGY_FRAME);
	objectArray.emplace_back(energy2);

	GameObject *energy3 = new Energia(MAX_POS_DISTANCE,CENTER, planet, 230,
									  ENERGY_HEIGHT, ENERGY_IMG, ENERGY_FRAME);
	objectArray.emplace_back(energy3);

	GameObject *spaceShip = new Nave(MAX_POS_DISTANCE,CENTER, planet, -89, 150,
									 SHIP_SHUT_DOWN);
	objectArray.emplace_back(spaceShip);

	GameObject *player = new Player(CENTER,CENTER, planet);
	objectArray.emplace_back(player);
	Camera::Follow(player);

	GameObject *support = new Support(planet);
	objectArray.emplace_back(support);

	activeWeapon = new WeaponBroom(LUPS_ARMS);
	objectArray.emplace_back(activeWeapon);

	GameObject *tank1 = new EnemyTank(MAX_POS_DISTANCE, CENTER, planet, -50,
		 							  TANK_HEIGHT);
	objectArray.emplace_back(tank1);

	GameObject *tank2 = new EnemyTank(MAX_POS_DISTANCE, CENTER, planet, -40,
		 							  TANK_HEIGHT);
	objectArray.emplace_back(tank2);

	GameObject *tank3 = new EnemyTank(MAX_POS_DISTANCE, CENTER, planet, -30,
		 							  TANK_HEIGHT);
	objectArray.emplace_back(tank3);

	GameObject *tank4 = new EnemyTank(MAX_POS_DISTANCE, CENTER, planet, 45,
		 							  TANK_HEIGHT);
	objectArray.emplace_back(tank4);

	GameObject *tank5 = new EnemyTank(MAX_POS_DISTANCE, CENTER, planet, 140,
		 							  TANK_HEIGHT);
	objectArray.emplace_back(tank5);

	GameObject *tank6 = new EnemyTank(MAX_POS_DISTANCE, CENTER, planet, 150,
		 							  TANK_HEIGHT);
	objectArray.emplace_back(tank6);

	GameObject *tank7 = new EnemyTank(MAX_POS_DISTANCE, CENTER, planet, 160,
		 							  TANK_HEIGHT);
	objectArray.emplace_back(tank7);

	GameObject *tank8 = new EnemyTank(MAX_POS_DISTANCE, CENTER, planet, 170,
		 							  TANK_HEIGHT);
	objectArray.emplace_back(tank8);

	GameObject *tank9 = new EnemyTank(MAX_POS_DISTANCE, CENTER, planet, 180,
		 							  TANK_HEIGHT);
	objectArray.emplace_back(tank9);

	GameObject *tank10 = new EnemyTank(MAX_POS_DISTANCE, CENTER, planet, 190,
		 							  TANK_HEIGHT);
	objectArray.emplace_back(tank10);

	music.Play(-1);
}

void StageState::Update(float deltaTime) {
	musicTime.Update(deltaTime);

	if (InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)) {
		std::cout
				<< InputManager::GetInstance().GetMouseX() - Camera::pos.getX()
				<< std::endl;
		std::cout
				<< InputManager::GetInstance().GetMouseY() - Camera::pos.getY()
				<< std::endl;
	}

	if (InputManager::GetInstance().KeyPress(SDLK_d) &&
		(musicTime.Get() > HALF_MUSIC_TIME)) {

		musicTime.Restart();
		if (activeWeapon->Is(WEAPON_BROOM)) {
			activeWeapon = new WeaponSword(SWORD_IMG);
			this->weaponNumber = SWORD;
		} else if (activeWeapon->Is(WEAPON_SWORD)) {
			activeWeapon = new WeaponGun(GUN_IMG);
			this->weaponNumber = GUN;
		} else if (activeWeapon->Is(WEAPON_GUN)) {
			activeWeapon = new WeaponBroom(LUPS_ARMS);
			this->weaponNumber = BROOM;
		}
		objectArray.emplace_back(activeWeapon);
	}

	Camera::Update(deltaTime);
	quitRequested = InputManager::GetInstance().QuitRequested();
	popRequested = InputManager::GetInstance().KeyPress(ESCAPE_KEY);
	UpdateArray(deltaTime);
	userInterface.Update(deltaTime);

	//verifica fim da fase
	if (Player::player->deveMudarDeFase) {
		popRequested = true;
		Player::player->deveMudarDeFase = false;
	}
}

void StageState::Render() {
	if (Player::player->GetHp() <= 0 &&
		Player::player->deathAnimation.Get() > DEATH_TIME) {
		Sprite *black = new Sprite(BLANK_IMG);
		black->Render(0,0);
		delete black;
		return;
	}

	background.Render(backgroundSize, 0);
	RenderArray();
	userInterface.Render();
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

StageState::SimpleWeaponName StageState::GetWeapon() {
	return weaponNumber;
}

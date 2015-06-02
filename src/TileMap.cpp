#include "TileMap.h"
#include "Camera.h"
#include "InputManager.h"

TileMap::TileMap(string file, TileSet* tileSet) {
	Load(file);
	this->tileSet = tileSet;
}

void TileMap::Load(string file) {
	FILE* fp;
	fp = fopen(file.c_str(), "r");
	fscanf(fp, "%d,", &mapWidth);
	fscanf(fp, "%d,", &mapHeight);
	fscanf(fp, "%d,", &mapDepth);
	int aux;
	while (!feof(fp)) {
		fscanf(fp, "%d,", &aux);
		tileMatrix.emplace_back(aux - 1);
	}
}

void TileMap::SetTileSet(TileSet* tileSet) {
	this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z = 0) {
	if (x > mapWidth || y > mapHeight || z > mapDepth) {
		cout << "Indice errado!!" << endl;
		exit(1);
	}
	int aux = (z * (mapWidth * mapHeight)) + (y * mapWidth) + x;
	return tileMatrix[aux];
}

void TileMap::RenderLayer(int layer, int cameraX = 0, int cameraY = 0) {
	int raioPlaneta = 1000;
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth * 3; j++) {
			int aux = At(9, 1, layer);
			int tileAtualCam = -cameraX / tileSet->GetTileWidth();
			float angle = j - tileAtualCam;
			angle = angle / 18;
			//cout << angle << endl;
			float posX = raioPlaneta * cos(angle);
			float posy = raioPlaneta * sin(angle)
					+ i * tileSet->GetTileHeight();
			posX += 500;
			//posX = 1920 + posX + cameraX;
			posy = posy + cameraY + 100 + raioPlaneta;
			//posy = 100;
			//posX += mapWidth*tileSet->GetTileWidth()/6;
			int indexRender = 18;
			if (layer > 0) {
				posy -= 250;
				indexRender = 0;
				if (i > 0 || (j % 10) > 1) {
					aux = -1;
				}
			}
			if (aux >= 0) {
				//cout << "Imprimiu tile!" << cameraX << " - "  << posX  << " - "  << cameraY  << " - "  << posy << endl;
				angle += 3.1415 / 2;
				tileSet->Render(indexRender, posX, posy, angle * 180 / 3.1415);
			}
			if (InputManager::GetInstance().KeyPress(SDLK_p)) {
				cout << tileAtualCam << endl;
			}
		}
	}
}

void TileMap::Render(int cameraX, int cameraY) {
	for (int i = 1; i < mapDepth; i++) {
		RenderLayer(i, cameraX, cameraY);
	}
}

int TileMap::GetWidth() {
	return mapWidth;
}

int TileMap::GetHeight() {
	return mapHeight;
}

int TileMap::GetDepth() {
	return mapDepth;
}

float TileMap::GetFloorHeight(int x, int cameraX) {
	int raioPlaneta = 1000;
	int tileX = x / tileSet->GetTileWidth();
	int tileAtualCam = -cameraX / tileSet->GetTileWidth();
	while (tileX > 25) {
		tileX -= 25;
	}

	for (int j = 0; j < mapHeight; j++) {
		for (int i = mapDepth - 1; i >= 0; i--) {
			int aux = At(tileX, j, i);
			if (aux > 0) {
				float angle = tileX - tileAtualCam;
				angle = angle / 12;
				//250 � a altura inicial dos Tiles
				float varY = raioPlaneta * sin(angle)
						+ j * tileSet->GetTileHeight();
				return j * tileSet->GetTileHeight() + 250 + varY;
			}
		}
	}
	return 0;
}
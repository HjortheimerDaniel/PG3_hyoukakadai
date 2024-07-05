#include "PlayerBullet.h"
PlayerBullet::PlayerBullet() {

	bullet.size = 20;
	bullet.handle = Novice::LoadTexture("./Sprites/bulletsmall.png");
	for (int i = 0; i < 10; i++) {

		bullet.speed[i] = 8;
		bullet.pos[i].x = -100;
		bullet.pos[i].y = 200;
		bullet.isShot[i] = false;
	}

}

PlayerBullet::~PlayerBullet() {}

void PlayerBullet::InitializeBullet() {

	bullet.size = 10;
	for (int i = 0; i < 10; i++) {

		bullet.speed[i] = 8;
		bullet.pos[i].x = -100;
		bullet.pos[i].y = 200;
		bullet.isShot[i] = false;
	}

}

void PlayerBullet::Shot() {

	for (int i = 0; i < 10; i++) {

		if (bullet.isShot[i]) {
			bullet.pos[i].y -= bullet.speed[i];
		}

		if (bullet.pos[i].y <= -30) {
			bullet.isShot[i] = false;
		}
	}

}

void PlayerBullet::UpdateBullet() {

	Shot();

}

void PlayerBullet::DrawBullet() {

	for (int i = 0; i < 10; i++) {
		if (bullet.isShot[i]) {

			Novice::DrawSprite((int)bullet.pos[i].x, (int)bullet.pos[i].y, bullet.handle, 1, 1, 0.0f, WHITE);
		}
	}

}
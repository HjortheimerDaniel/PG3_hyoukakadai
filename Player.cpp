#include "Player.h"
#include "Novice.h"
#define _USE_MATH_DEFINES_
#include <math.h>


void Player::Initialize()
{
	player_.pos = { 
	{ 500.0f, 400.0f },
	{ 628.0f, 400.0f },
	{ 500.0f, 528.0f },
	{ 628.0f, 528.0f }
	};
	player_.size = { 128,128 };
	player_.speed.x = 5;
	player_.speed.y = 5;
	player_.handle = Novice::LoadTexture("./Sprites/player.png");
	player_.HP = 3;
	bullet_.size = 20;
	bullet_.handle = Novice::LoadTexture("./Sprites/bulletsmall.png");
	for (int i = 0; i < 10; i++) {

		bullet_.speed[i] = 8;
		bullet_.pos[i].x = -100;
		bullet_.pos[i].y = 200;
		bullet_.isShot[i] = false;
	}
}

Player::Player()
{
}

Player::~Player()
{
}

void Player::Update(char* keys, char* preKeys)
{
	Movement(keys, preKeys);
	Shoot(keys, preKeys);
	PlayerDamaged();
	HitBox();
}

void Player::Movement(char* keys, char* preKeys)
{
	player_.speed.x = 0.0f;
	player_.speed.y = 0.0f;

	if ((keys[DIK_D] || keys[DIK_RIGHT]) && (preKeys[DIK_D] || preKeys[DIK_RIGHT]) && player_.pos.UR.x <= 1140 && !keys[DIK_A] &&
		!preKeys[DIK_A]) {
		player_.speed.x = +5;
	}

	if ((keys[DIK_A] || keys[DIK_LEFT]) && (preKeys[DIK_A] || preKeys[DIK_LEFT]) && player_.pos.UL.x >= 0 && !keys[DIK_D] && !preKeys[DIK_D]) {
		player_.speed.x = -5;
	}

	if ((keys[DIK_S] || keys[DIK_DOWN]) && (preKeys[DIK_S] || preKeys[DIK_DOWN]) && player_.pos.LL.y <= 720 && !keys[DIK_S] && !preKeys[DIK_S]) {
		player_.speed.y = -5;
	}

	if ((keys[DIK_W] || keys[DIK_UP]) && (preKeys[DIK_W] || preKeys[DIK_UP]) && player_.pos.LL.y <= 720 && !keys[DIK_W] && !preKeys[DIK_W]) {
		player_.speed.y = -5;
	}
	

	float normalizeSpeed =
		sqrtf(player_.speed.x * player_.speed.x + player_.speed.y * player_.speed.y);
	if (normalizeSpeed != 0.0f) {
		player_.speed.x /= normalizeSpeed;
		player_.speed.y /= normalizeSpeed;
	}

	player_.pos.UL.x += player_.speed.x * 5;
	player_.pos.UR.x += player_.speed.x * 5;
	player_.pos.LL.x += player_.speed.x * 5;
	player_.pos.LR.x += player_.speed.x * 5;
	player_.pos.UL.y += player_.speed.y * 5;
	player_.pos.UR.y += player_.speed.y * 5;
	player_.pos.LL.y += player_.speed.y * 5;
	player_.pos.LR.y += player_.speed.y * 5;

}

void Player::PlayerDamaged()
{
	if (player_.isDamaged) {
		player_.damagedTimer++;
		player_.color = RED;
	}
	else {
		player_.color = WHITE;
	}

	if (player_.damagedTimer == 1) {
		player_.HP--;
	}

	if (player_.damagedTimer >= 60) {
		player_.damagedTimer = 0;
	}

	if (player_.HP <= 0) {
		player_.isDead = true;
	}
}

void Player::HitBox()
{
	player_.hitbox.UL.x = player_.pos.UL.x + adjustHitboxLeftX;
	player_.hitbox.UL.y = player_.pos.UL.y + adjustHitboxY;
	player_.hitbox.UR.x = player_.pos.UR.x - adjustHitboxRightX;
	player_.hitbox.UR.y = player_.pos.UR.y + adjustHitboxY;
	player_.hitbox.LL.x = player_.pos.LL.x + adjustHitboxLeftX;
	player_.hitbox.LL.y = player_.pos.LL.y - adjustHitboxY;
	player_.hitbox.LR.x = player_.pos.LR.x - adjustHitboxRightX;
	player_.hitbox.LR.y = player_.pos.LR.y - adjustHitboxY;
}

void Player::Shoot(char* keys, char* preKeys)
{
	for (int i = 0; i < 10; i++) {

		if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet_.isShot[i]) {
			bullet_.isShot[i] = true;
			bullet_.pos[i].x = (player_.pos.UL.x + 64);
			bullet_.pos[i].y = player_.pos.UL.y - 30;
			break;
		}
	}

	for (int i = 0; i < 10; i++) {

		if (bullet_.isShot[i]) {
			bullet_.pos[i].y -= bullet_.speed[i];
		}

		if (bullet_.pos[i].y <= -30) {
			bullet_.isShot[i] = false;
		}
	}
}

void Player::Draw()
{
	for (int i = 0; i < 10; i++) {
		if (bullet_.isShot[i]) {

			Novice::DrawSprite((int)bullet_.pos[i].x, (int)bullet_.pos[i].y, bullet_.handle, 1, 1, 0.0f, WHITE);
		}
	}
	Novice::DrawSprite((int)player_.pos.UL.x, (int)player_.pos.UL.y, player_.handle, 1, 1, 0.0f, player_.color);
}

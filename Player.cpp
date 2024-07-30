#include "Player.h"
#include "Novice.h"
#define _USE_MATH_DEFINES_
#include <math.h>
#include <algorithm>
#include <iostream>


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
	player_.damagedTimer = 0;
	player_.handle = Novice::LoadTexture("./Sprites/player.png");
	player_.isDamaged = false;
	player_.isDead = false;
	player_.HP = 3;
	bullet_.size = 20;
	bullet_.isShot.resize(10);
	bullet_.speed.resize(10);
	bullet_.pos.resize(10);
	size = 10;
	shootCD = 0;
	canShoot = true;
	bullet_.handle = Novice::LoadTexture("./Sprites/bulletsmall.png");
	for (int i = 0; i < size; i++) {

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

void Player::MoveRight()
{
	float normalizeSpeed =
		sqrtf(player_.speed.x * player_.speed.x);
	if (normalizeSpeed != 0.0f) {

		player_.speed.x /= normalizeSpeed;
	}


	this->player_.pos.UL.x += this->player_.speed.x * 5;
	this->player_.pos.UR.x += this->player_.speed.x * 5;
	this->player_.pos.LR.x += this->player_.speed.x * 5;
	this->player_.pos.LL.x += this->player_.speed.x * 5;


}

void Player::MoveLeft()
{
	float normalizeSpeed =
		sqrtf(player_.speed.x * player_.speed.x);
	if (normalizeSpeed != 0.0f) {

		player_.speed.x /= normalizeSpeed;
	}

	this->player_.pos.UL.x -= this->player_.speed.x * 5;
	this->player_.pos.UR.x -= this->player_.speed.x * 5;
	this->player_.pos.LR.x -= this->player_.speed.x * 5;
	this->player_.pos.LL.x -= this->player_.speed.x * 5;
}

void Player::MoveUp()
{
	float normalizeSpeed =
		sqrtf(player_.speed.y * player_.speed.y);
	if (normalizeSpeed != 0.0f) {

		player_.speed.y /= normalizeSpeed;
	}

	this->player_.pos.UL.y -= this->player_.speed.y * 5;
	this->player_.pos.UR.y -= this->player_.speed.y * 5;
	this->player_.pos.LR.y -= this->player_.speed.y * 5;
	this->player_.pos.LL.y -= this->player_.speed.y * 5;
}

void Player::MoveDown()
{
	float normalizeSpeed =
		sqrtf(player_.speed.y * player_.speed.y);
	if (normalizeSpeed != 0.0f) {
		
		player_.speed.y /= normalizeSpeed;
	}

	this->player_.pos.UL.y += this->player_.speed.y * 5;
	this->player_.pos.UR.y += this->player_.speed.y * 5;
	this->player_.pos.LR.y += this->player_.speed.y * 5;
	this->player_.pos.LL.y += this->player_.speed.y * 5;
}

void Player::MoveUpRight()
{
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
	player_.pos.UL.y -= player_.speed.y * 5;
	player_.pos.UR.y -= player_.speed.y * 5;
	player_.pos.LL.y -= player_.speed.y * 5;
	player_.pos.LR.y -= player_.speed.y * 5;
}

void Player::MoveUpLeft()
{
	float normalizeSpeed =
		sqrtf(player_.speed.x * player_.speed.x + player_.speed.y * player_.speed.y);
	if (normalizeSpeed != 0.0f) {
		player_.speed.x /= normalizeSpeed;
		player_.speed.y /= normalizeSpeed;
	}

	player_.pos.UL.x -= player_.speed.x * 5;
	player_.pos.UR.x -= player_.speed.x * 5;
	player_.pos.LL.x -= player_.speed.x * 5;
	player_.pos.LR.x -= player_.speed.x * 5;
	player_.pos.UL.y -= player_.speed.y * 5;
	player_.pos.UR.y -= player_.speed.y * 5;
	player_.pos.LL.y -= player_.speed.y * 5;
	player_.pos.LR.y -= player_.speed.y * 5;
}

void Player::MoveDownRight()
{
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

void Player::MoveDownLeft()
{
	float normalizeSpeed =
		sqrtf(player_.speed.x * player_.speed.x + player_.speed.y * player_.speed.y);
	if (normalizeSpeed != 0.0f) {
		player_.speed.x /= normalizeSpeed;
		player_.speed.y /= normalizeSpeed;
	}

	player_.pos.UL.x -= player_.speed.x * 5;
	player_.pos.UR.x -= player_.speed.x * 5;
	player_.pos.LL.x -= player_.speed.x * 5;
	player_.pos.LR.x -= player_.speed.x * 5;
	player_.pos.UL.y += player_.speed.y * 5;
	player_.pos.UR.y += player_.speed.y * 5;
	player_.pos.LL.y += player_.speed.y * 5;
	player_.pos.LR.y += player_.speed.y * 5;
}

void Player::Update()
{
	//Movement(keys, preKeys);
	//Shoot();
	PlayerDamaged();
	HitBox();
	UpdateBullet();
}

void Player::UpdateBullet()
{
	for (int i = 0; i < 10; i++) {

		if (bullet_.isShot[i]) {
			bullet_.pos[i].y -= bullet_.speed[i];
		}

		if (bullet_.pos[i].y <= -30) {
			bullet_.isShot[i] = false;
		}
	}
	if (!canShoot) 
	{
		shootCD++;
	}

	if (shootCD >= 10) 
	{
		canShoot = true;
		shootCD = 0;
	}
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
		player_.isDamaged = false;
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

void Player::Shoot()
{
	for (int i = 0; i < 10; i++) {

		if (!bullet_.isShot[i] && canShoot) {
			bullet_.isShot[i] = true;
			canShoot = false;
			bullet_.pos[i].x = (player_.pos.UL.x + 64);
			bullet_.pos[i].y = player_.pos.UL.y - 30;
			
			break;
		}
	}


	
}

void Player::Draw()
{
	for (int i = 0; i < size; i++) {
		if (bullet_.isShot[i]) {

			Novice::DrawSprite((int)bullet_.pos[i].x, (int)bullet_.pos[i].y, bullet_.handle, 1, 1, 0.0f, WHITE);
		}
	}
	Novice::DrawSprite((int)player_.pos.UL.x, (int)player_.pos.UL.y, player_.handle, 1, 1, 0.0f, player_.color);

}

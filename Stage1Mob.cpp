#include "Stage1Mob.h"

void Stage1Mob::Initialize(Quad pos, Vector2 speed, int HP)
{
	enemy_.HP = HP;
	enemy_.pos = pos;
	enemy_.speed = speed;
	enemy_.hitbox = {};
	enemy_.animation = 0;
	enemy_.frames = 0;
	enemy_.MAXAnimation = 2;
	enemy_.MAXFrames = 50;
	enemy_.isDead = false;
	enemy_.size = { 110, 100 };
	enemy_.theta = 0.0f;
	enemy_.amplitude = 350.0f;
	enemy_.isDamaged = false;
	enemy_.damagedTimer = 0;
	enemy_.color = WHITE;
	enemyBullet_.CD = 0;
	enemyBullet_.radius = 64;
	enemy_.handle = Novice::LoadTexture("./Sprites/enemy1.png");
	enemyBullet_.handle = Novice::LoadTexture("./Sprites/bulletBossmall.png");
	for (int i = 0; i < 4; i++) {

		enemyBullet_.speed[i] = 2;
		enemyBullet_.pos[i].x = -100;
		enemyBullet_.pos[i].y = 200;
		enemyBullet_.isShot[i] = false;

	}
}

Stage1Mob::Stage1Mob(/*Quad pos, Vector2 speed, int HP*/)
{
}

Stage1Mob::~Stage1Mob()
{
}

void Stage1Mob::Movement()
{
	enemy_.theta += float(M_PI) / 250.0f;

	enemy_.pos.UL.x = cosf(enemy_.theta) * enemy_.amplitude + 700;
	enemy_.pos.UR.x = cosf(enemy_.theta) * enemy_.amplitude + 828;
	enemy_.pos.LL.x = cosf(enemy_.theta) * enemy_.amplitude + 700;
	enemy_.pos.LR.x = cosf(enemy_.theta) * enemy_.amplitude + 828;

}

void Stage1Mob::Shoot()
{
	enemyBullet_.CD++;

	for (int i = 0; i < 4; i++) {

		if (enemyBullet_.isShot[i]) {
			enemyBullet_.pos[i].y += enemyBullet_.speed[i];
		}

		if (enemyBullet_.pos[i].y >= 1000) {
			enemyBullet_.isShot[i] = false;
		}
	}

	for (int i = 0; i < 4; i++) {

		if (!enemyBullet_.isShot[i] && enemyBullet_.CD == 200) {
			enemyBullet_.CD = 0;
			enemyBullet_.isShot[i] = true;
			enemyBullet_.pos[i].x = (enemy_.pos.UL.x + enemy_.pos.UR.x) / 2;
			enemyBullet_.pos[i].y = enemy_.pos.UL.y + 100;
			break;
		}
	}
}

void Stage1Mob::Update()
{
	if (!enemy_.isDead) {
		Animation(enemy_.animation, enemy_.frames, enemy_.MAXFrames, enemy_.MAXAnimation);
		Damaged(enemy_.HP, enemy_.isDamaged, enemy_.damagedTimer, enemy_.isDead, enemy_.color);
		Movement();
		Shoot();
	}
	else {
		EnemyDead();
	}
}

void Stage1Mob::EnemyDead()
{
	if (enemy_.isDead) {
		enemy_.pos.UL.x = -50;
		enemy_.pos.UR.x = -50;
		enemy_.pos.LL.x = -50;
		enemy_.pos.LR.x = -50;
	}
}

void Stage1Mob::DrawBullet()
{
	for (int i = 0; i < 4; i++) {
		if (enemyBullet_.isShot[i]) {

			Novice::DrawSprite(
				(int)enemyBullet_.pos[i].x, (int)enemyBullet_.pos[i].y, enemyBullet_.handle, 1, 1,
				0.0f, WHITE);
		}
	}
}

void Stage1Mob::Draw()
{
	if (!enemy_.isDead) {

		DrawBullet();
		Novice::DrawQuad(
			(int)enemy_.pos.UL.x, (int)enemy_.pos.UL.y, (int)enemy_.pos.UR.x, (int)enemy_.pos.UR.y,
			(int)enemy_.pos.LL.x, (int)enemy_.pos.LL.y, (int)enemy_.pos.LR.x, (int)enemy_.pos.LR.y,
			128 * enemy_.animation, 0, 128, 128, (int)enemy_.handle, enemy_.color);
	}
}

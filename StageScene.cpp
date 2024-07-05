#include "StageScene.h"
#include <Novice.h>
#include "Functions.h"


void StageScene::Init()
{
	enemy[0] = new Stage1Mob();

	enemy[0]->Initialize({
			{100, 200},
			{228, 200},
			{100, 328},
			{228, 328}
		},
		{ 4.0f, 4.0f }, 7);
	player = new Player();
	player->Initialize();
}

StageScene::~StageScene()
{
	delete player;
	for (int i = 0; i < MAXENEMIES; i++)
	{
		delete enemy[i];
	}
	
}

void StageScene::Update(char* keys, char* preKeys)
{

	player->Update(keys, preKeys);
	for (int i = 0; i < MAXENEMIES; i++) {

		enemy[i]->Update();
	}
	Restart(keys, preKeys);
	CollisionPlayerEnemy();
	CollisionBulletEnemy();
	CollisionEnemyBulletPlayer();
}

void StageScene::CollisionBulletEnemy()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < MAXENEMIES; j++) {

			if (CheckCollision(
				player->GetBulletPos()[i], { enemy[j]->GetPos().UL.x, enemy[j]->GetPos().UL.y },
				{ 10, 10 }, { enemy[j]->GetSize().x, enemy[j]->GetSize().y }) &&
				!enemy[j]->GetIsDead()) {
				enemy[j]->SetIsDamaged(true);
				player->SetBulletY(-40, i);
			}
		}
	}
}

void StageScene::CollisionPlayerEnemy()
{
	for (int i = 0; i < MAXENEMIES; i++) {
		if (CheckCollision(
			player->GetPos().UL, { enemy[i]->GetPos().UL.x, enemy[i]->GetPos().UL.y },
			player->GetSize(), { enemy[i]->GetSize().x, enemy[i]->GetSize().y }) &&
			playerDamageCooldown_ == 0 && !enemy[i]->GetIsDead()) {
			player->SetIsDamaged(true);
		}
		if (player->GetIsDamaged()) {
			playerIFrames = true;
		}
	}
	if (playerIFrames) {
		playerDamageCooldown_++;
	}

	if (playerDamageCooldown_ >= 60) {
		playerIFrames = false;
		playerDamageCooldown_ = 0;
		player->SetIsDamaged(false);
	}
}

void StageScene::CollisionEnemyBulletPlayer()
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < MAXENEMIES; j++) {

			if (CheckCollision(
				enemy[j]->GetBossBulletPos()[i], { player->GetPos().UL.x, player->GetPos().UL.y },
				{ 64, 64 }, { player->GetSize().x, player->GetSize().y })) {
				player->SetIsDamaged(true);
				enemy[j]->SetBulletY(1500, i);
			}

		}
	}
}

void StageScene::Restart(char* keys, char* preKeys)
{
	if (keys[DIK_R] && !preKeys[DIK_R]) {

		enemy[0]->Initialize(
			{
				{100, 200},
				{228, 200},
				{100, 328},
				{228, 328}
			},
			{ 4.0f, 4.0f }, 7);

	
		player->Initialize();
	}
}

void StageScene::Draw()
{
	player->Draw();
	for (int i = 0; i < MAXENEMIES; i++)
	{
		enemy[i]->Draw();

	}
	Novice::ScreenPrintf(0, 0, "A || < = LEFT");
	Novice::ScreenPrintf(0, 20, "D || > = RIGHT");
	Novice::ScreenPrintf(0, 40, "SPACE = SHOOT");
}

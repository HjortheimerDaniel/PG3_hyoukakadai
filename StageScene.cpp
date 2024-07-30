#include "StageScene.h"
#include <Novice.h>
#include "Functions.h"


void StageScene::Init()
{
	titleSprite = Novice::LoadTexture("./Sprites/gameBG.png");

	enemy[0] = new Stage1Mob();
	enemyHP = 7;

	enemy[0]->Initialize({
			{100, 200},
			{228, 200},
			{100, 328},
			{228, 328}
		},
		{ 4.0f, 4.0f }, enemyHP);
	player = new Player();
	inputHandler_->AssignMoveRightCommand2PressKeyD();
	inputHandler_->AssignMoveLeftCommand2PressKeyA();
	inputHandler_->AssignMoveUpCommand2PressKeyW();
	inputHandler_->AssignMoveDownCommand2PressKeyS();
	inputHandler_->AssignMoveDownLeftCommand2PressKeySA();
	inputHandler_->AssignMoveDownRightCommand2PressKeySD();
	inputHandler_->AssignMoveUpLeftCommand2PressKeyWA();
	inputHandler_->AssignMoveUpRightCommand2PressKeyWD();
	inputHandler_->AssignShotCommand2PressKeySpace();
	player->Initialize();
}

StageScene::~StageScene()
{
	delete player;
	for (int i = 0; i < MAXENEMIES; i++)
	{
		delete enemy[i];
	}
	delete iCommand_;
	delete iCommandShoot_;
	delete inputHandler_;
}

void StageScene::Update(char* keys, char* preKeys)
{
	iCommand_ = inputHandler_->HandleInput();
	iCommandShoot_ = inputHandler_->HandleShootInput();
	if (this->iCommand_)
	{
		iCommand_->Exec(*player);
	}

	if (this->iCommandShoot_) 
	{
		iCommandShoot_->Exec(*player);
	}

	player->Update();
	for (int i = 0; i < MAXENEMIES; i++) {

		enemy[i]->Update();
	}
	Restart(keys, preKeys);
	CollisionPlayerEnemy();
	CollisionBulletEnemy();
	CollisionEnemyBulletPlayer();
	//StageClear();
	ChangeScenes();


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
				enemyHP--;
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
	}
}

void StageScene::StageClear()
{
	sceneNo = CLEAR;
	Init();
}

void StageScene::StageFailed()
{
	sceneNo = TITLE;
	Init();
}

void StageScene::ChangeScenes()
{

	if (enemyHP <= 0) 
	{
		pfunc = &StageScene::StageClear;
		(this->*pfunc)();

	}

	if (player->GetPlayerIsDead())
	{
		pfunc = &StageScene::StageFailed;
		(this->*pfunc)();
		SetTimeout(700);

	}
}

void StageScene::SetTimeout(int second)
{
	Sleep(second); //how many seconds we wait
	
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
	Novice::DrawSprite(0, 0, titleSprite, 1, 1, 0.0f, WHITE);

	player->Draw();
	for (int i = 0; i < MAXENEMIES; i++)
	{
		enemy[i]->Draw();

	}
	//Novice::ScreenPrintf(0, 0, "A || < = LEFT");
	//Novice::ScreenPrintf(0, 20, "D || > = RIGHT");
	//Novice::ScreenPrintf(0, 40, "SPACE = SHOOT");
}

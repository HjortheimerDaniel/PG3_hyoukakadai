#pragma once
#include "IScene.h"
#include "Player.h"
#include "Stage1Mob.h"
#include <time.h>
#include <Windows.h>
#include "InputHandler.h"
#include "Command.h"


class StageScene : public IScene
{
public:

	typedef void(StageScene::* PFunc)();

	void Init() override;
	~StageScene();
	void Update(char* keys, char* preKeys) override;

	void CollisionBulletEnemy();

	void CollisionPlayerEnemy();

	void StageClear();

	void StageFailed();

	void ChangeScenes();

	void SetTimeout(int second);

	void CollisionEnemyBulletPlayer();

	void Restart(char* keys, char* preKeys);


	void Draw() override;

private:

	Player* player;
	Enemy* enemy[MAXENEMIES];
	int playerDamageCooldown_;
	int enemyHP;
	bool playerIFrames;
	PFunc pfunc = nullptr;
	InputHandler* inputHandler_ = new InputHandler();
	ICommand* iCommand_ = nullptr;
	ICommand* iCommandShoot_ = nullptr;
	int titleSprite;

};


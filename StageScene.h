#pragma once
#include "IScene.h"
#include "Player.h"
#include "Stage1Mob.h"


class StageScene : public IScene
{
public:

	void Init() override;
	~StageScene();
	void Update(char* keys, char* preKeys) override;

	void CollisionBulletEnemy();

	void CollisionPlayerEnemy();

	void CollisionEnemyBulletPlayer();

	void Restart(char* keys, char* preKeys);


	void Draw() override;

private:

	Player* player;
	Enemy* enemy[MAXENEMIES];
	int playerDamageCooldown_;
	bool playerIFrames;
};


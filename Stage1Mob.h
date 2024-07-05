#pragma once
#include "Enemy.h"

class Stage1Mob : public Enemy
{
public:

	void Initialize(Quad pos, Vector2 speed, int HP) override;

	Stage1Mob(/*Quad pos, Vector2 speed, int HP*/);

	~Stage1Mob() override;

	void Movement();

	void Shoot();

	void Update() override;

	void EnemyDead();

	void DrawBullet();

	void Draw() override;
};


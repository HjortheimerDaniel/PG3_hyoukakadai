#pragma once
#include <vector>

#define MAXENEMIES 1

struct Vector2 {
	float x, y;
};


struct Quad {
	Vector2 UL, UR, LL, LR;
};

struct PlayerStruct
{
	Quad pos;
	Quad hitbox;
	Vector2 speed, size;
	int handle, animation, frames, damagedTimer;
	bool isDead, isDamaged;
	int HP;
	int heartHandle[3];
	int color;

};

struct EnemyStruct {
	Quad pos;
	Quad hitbox;
	Vector2 speed, size;
	int handle, animation, frames, MAXAnimation, MAXFrames;
	bool isDead, isDamaged;
	int damagedTimer;
	float theta;
	float amplitude;
	int HP;
	int color;
};

struct Bullet
{
	//Vector2 pos[10];
	std::vector<Vector2> pos;
	int size;
	//bool isShot[10];
	std::vector<bool> isShot;
	//int speed[10];
	std::vector<int> speed;
	int handle;
	int CD;
};

struct EnemyBullet {
	Vector2 pos[4];
	int radius;
	bool isShot[4];
	int speed[4];
	int handle;
	int CD;
};

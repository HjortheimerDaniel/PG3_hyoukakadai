#pragma once
#include "struct.h"
#include "Novice.h"

class PlayerBullet
{
public:
	PlayerBullet();

	~PlayerBullet();

	void InitializeBullet();

	void Shot();

	void UpdateBullet();

	void SetBulletX(float x, int index) { bullet.pos[index].x = x; };

	void SetBulletY(float y, int index) { bullet.pos[index].y = y; };

	void SetIsShot(bool shot, int index) { bullet.isShot[index] = shot; };

	bool* GetIsShot() { return bullet.isShot; };

	void DrawBullet();

public:
	Bullet bullet;
};


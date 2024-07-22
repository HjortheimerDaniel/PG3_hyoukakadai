#pragma once
#include "Struct.h"

class Player
{
public:

	void Initialize();

	Player();

	~Player();

	void MoveRight();

	void MoveLeft();

	void MoveUp();

	void MoveDown();

	void MoveUpRight();

	void MoveUpLeft();

	void MoveDownRight();

	void MoveDownLeft();

	void Update();

	void UpdateBullet();

	void SetPos(Quad pos) { player_.pos = pos; };

	Quad GetPos() { return player_.hitbox; };

	Vector2 GetSize() { return player_.size; };

	void SetIsDamaged(bool damaged) { player_.isDamaged = damaged; };
	
	bool GetIsDamaged() { return player_.isDamaged; };

	void PlayerDamaged();

	int GetPlayerHP() { return player_.HP; };

	void HitBox();

	std::vector<Vector2> GetBulletPos() { return bullet_.pos; };

	int GetBulletSize() { return bullet_.size; };

	void SetBulletX(float x, int index) { bullet_.pos[index].x = x; };

	void SetBulletY(float y, int index) { bullet_.pos[index].y = y; };

	void SetIsShot(bool shot, int index) { bullet_.isShot[index] = shot; };

	std::vector<bool> GetIsShot() { return bullet_.isShot; };

	bool GetPlayerIsDead() { return player_.isDead; };

	void Shoot();

	void Draw();

protected:

	PlayerStruct player_;
	Bullet bullet_;
	const int adjustHitboxLeftX = 30;
	const int adjustHitboxRightX = 40;
	const int adjustHitboxY = 30;
	int size;
	int shootCD;
	bool canShoot;
};


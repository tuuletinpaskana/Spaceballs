#pragma once

#include "Animation.h"
#include "Vec2.h"
#include "RectF.h"
#include "BulletManager.h"

class BigEnemyShip
{
public:
	enum State
	{
		WaitState, AliveState, DyingState
	};
	BigEnemyShip(float X, const Surface& surface, BulletManager& BulletM, AnimationFrames& ExploAnim, Sound& ExploSound, AnimationFrames& bulletAnim);
	void Draw(Graphics& gfx);
	void Update(float dt);
	void Reset();
	RectF GetCollisionRect() const;
	int GetCollisionDmg() const;
	int GetBulletDmg() const;
	void HandleCollision(int dmg);
	void Attack(float dt);
	void Move(float dt);
	bool IsAlive() const;

private:
	Vec2 pos;
	Vec2 canon = Vec2(42.5f, 75.0f);
	Vec2 vel = Vec2(100.0f, 100.0f);
	static constexpr float width = 145.0f;
	static constexpr float height = 90.0f;
	float resetX;
	const Surface& shipSurface;
	State state = WaitState;
	BulletManager& bulletM;
	static constexpr int bulletHalfWidth = 30;
	static constexpr int bulletHalfHeight = 37;
	static constexpr int bulletRectSize = 15;
	static constexpr float bulletVel = -400.0f;
	static constexpr int bulletDmg = 50;
	static constexpr int collisionDmg = 75;
	int hp = 600;
	float bulletTimer = 0.0f;
	static constexpr float newBullet = 1.5f;
	Animation exploAnim;
	float shipTimer = 0.0f;
	static constexpr float waitOver = 15.0f;
	Sound& exploSound;
	static constexpr float bulletPitch = 0.3f;

	Animation bulletSprite;
};
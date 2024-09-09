#pragma once
#include "Shared.h"

class Bullet
{
public:

	void init();

	void update();

	void draw();

	RectF bulletHitBox[10];
	RectF damageHitBox[10];

private:

	enum User
	{
		player, enemy
	}user;

	Vec2 pos;
};

extern Bullet bullet;

#pragma once
#include "Shared.h"

class Bullet
{
public:

	void init();

	void update();

	void draw();

	enum User
	{
		player, enemy
	}user;

	void isShot(User user, int32 dir, Vec2 pos, int32 speed);

	static const int32 max = 10;

	RectF bulletHitBox[max];
	RectF damageHitBox[max];

private:

	void move();

	void collision();

	Array<TextureRegion> bulletImage;
	Array<TextureRegion> boomImage;

	int32 frameSpeed = 20;

	enum direction
	{
		up, down, left, right
	}dir;

	struct Number
	{
		User user;
		direction dir;
		Vec2 pos;
		int32 speed;
		bool active;
	}number[max];

	struct Boom
	{
		Vec2 pos;
		int32 volume;
		bool active;
		double frame;
	}boom[max];
};

extern Bullet bullet;

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
		enemy1, enemy2, enemy3, enemy4, player1
	}user;

	void isShot(User user, int32 dir, Vec2 pos, int32 speed);

	static const int32 max = 10;

	RectF bulletHitBox[max];
	RectF damageHitBox[max];

private:

	void move();

	void collision();

	void returnCount(User user);

	Array<TextureRegion> bulletImage;
	Array<TextureRegion> boomImage;

	int32 frameSpeed = 20;

	enum Direction
	{
		up, down, left, right
	}dir;

	struct Number
	{
		User user;
		Direction dir;
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

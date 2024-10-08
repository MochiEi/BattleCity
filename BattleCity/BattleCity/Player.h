﻿#pragma once
#include "Shared.h"

class Player
{
public:

	void init();

	void update();

	void draw();

	void debug_changeLv();

	RectF playerHitBox;

	int32 bulletCount = 0;

private:

	void status();

	void move();

	void shot();

	bool collision();

	enum Level
	{
		level1, level2, level3, level4
	}lv;

	enum Direction
	{
		up, down, left, right
	}dir;

	Vec2 playerPos{ 352, 800 };
	Array<TextureRegion> playerImage;
	Array<TextureRegion> playerSprites_Lv1;
	Array<TextureRegion> playerSprites_Lv2;
	Array<TextureRegion> playerSprites_Lv3;
	Array<TextureRegion> playerSprites_Lv4;
	double framePlayer;

	RectF collisionUp;
	RectF collisionDown;
	RectF collisionLeft;
	RectF collisionRight;

	Point gridPos{ 9,24 };
	Rect gridHitBox;
	Vec2 gridCount{ 0,0 };

	int32 moveSpeed = 150;
	int32 frameSpeed = 20;

	int32 bulletLimit;
	int32 bulletSpeed;

	enum BulletType
	{
		HE, AP
	}bulletType;
};

extern Player player;

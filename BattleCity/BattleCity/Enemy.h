#pragma once
#include "Shared.h"

class Enemy
{
public:

	void init();

	void update();

	void draw();

	static const int32 max = 4;

	RectF enemyHitBox[max];

private:

	void status();

	void collision();

	enum Type
	{
		light, armored, fast, heavy
	}type;

	enum Direction
	{
		up, down, left, right
	}dir;

	Array<TextureRegion> enemySprites_Light;
	Array<TextureRegion> enemySprites_Armored;
	Array<TextureRegion> enemySprites_Fast;
	Array<TextureRegion> enemySprites_Heavy;

	struct Number
	{
		bool isSurvive;
		int32 hp;

		Vec2 enemyPos{ 94, 64 };
		Array<TextureRegion> enemyImage;
		double frameEnemy;

		Type type;
		Direction dir;

		Point gridPos{ 0,2 };
		Rect gridHitBox;
		Vec2 gridCount{ 0,0 };

		int32 moveSpeed;
		int32 frameSpeed = 20;

		int32 bulletCount = 0;
		int32 bulletLimit = 1;
		int32 bulletSpeed;

	}number[max];
};

extern Enemy enemy;

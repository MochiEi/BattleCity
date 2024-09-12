#include "Enemy.h"

void Enemy::init()
{
	Texture enemySprites_01{ U"example/image/enemy_01.png", TextureDesc::Mipped };
	Texture enemySprites_02{ U"example/image/enemy_02.png", TextureDesc::Mipped };
	//Texture enemySprites_03{ U"example/image/enemy_03.png", TextureDesc::Mipped };
	//Texture enemySprites_04{ U"example/image/enemy_04.png", TextureDesc::Mipped };

	for (int i = 0; i < 8; i++)
	{
		enemySprites_Light << enemySprites_01(64 * i, 0, 64, 64);
		enemySprites_Armored << enemySprites_02(64 * i, 0, 64, 64);
		//enemySprites_Fast << enemySprites_03(64 * i, 0, 64, 64);
		//enemySprites_Heavy << enemySprites_04(64 * i, 0, 64, 64);
	}

	number[0].isSurvive = true;
	number[0].type = light;
	number[0].dir = down;
}

void Enemy::update()
{
	status();
	collision();
}

void Enemy::draw()
{
	for (auto num : number)
	{
		if (num.isSurvive)
		{
			if (num.enemyImage.size() == 8)
				num.enemyImage[(int)num.frameEnemy].draw(num.enemyPos);
		}
	}
}

void Enemy::status()
{
	for (auto& num : number)
	{
		num.enemyImage.clear();

		if (num.type == light)
		{
			for (auto sprites : enemySprites_Light)
				num.enemyImage << sprites;

			num.hp = 1;
			num.moveSpeed = 150;
			num.bulletSpeed = 600;
		}
		if (num.type == armored)
		{
			for (auto sprites : enemySprites_Armored)
				num.enemyImage << sprites;

			num.hp = 1;
			num.moveSpeed = 200;
			num.bulletSpeed = 600;
		}
		if (num.type == fast)
		{
			for (auto sprites : enemySprites_Fast)
				num.enemyImage << sprites;

			num.hp = 1;
			num.moveSpeed = 150;
			num.bulletSpeed = 1000;
		}
		if (num.type == heavy)
		{
			for (auto sprites : enemySprites_Heavy)
				num.enemyImage << sprites;

			num.hp = 4;
			num.moveSpeed = 150;
			num.bulletSpeed = 600;
		}
	}

	for (int i = 0; i < max; i++)
	{
		if (!number[i].isSurvive)
		{
			number[i].enemyPos = { -64,-64 };
			enemyHitBox[i] = { number[i].enemyPos,64,64 };
		}
	}
}

void Enemy::collision()
{
	for (int i = 0; i < max; i++)
		enemyHitBox[i] = { number[i].enemyPos,64,64 };

	for (int i = 0; i < max; i++)
	{
		if (number[i].isSurvive)
		{
			for (auto bulletHitBox : bullet.bulletHitBox)
			{
				if (enemyHitBox[i].intersects(bulletHitBox))
				{
					number[i].isSurvive = false;
				}
			}
		}
	}
}

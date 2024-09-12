#include "Player.h"

void Player::init()
{
	Texture playerSprites{ U"example/image/player.png", TextureDesc::Mipped };

	for (int i = 0; i < 8; i++)
	{
		playerImage << playerSprites(64 * i, 0, 64, 64);
		playerSprites_Lv1 << playerSprites(64 * i, 0, 64, 64);
		playerSprites_Lv2 << playerSprites(64 * i, 64, 64, 64);
		playerSprites_Lv3 << playerSprites(64 * i, 128, 64, 64);
		playerSprites_Lv4 << playerSprites(64 * i, 192, 64, 64);
	}

	lv = level1;

	playerHitBox = { playerPos.x + share.tolerance , playerPos.y + share.tolerance, 64 - share.tolerance * 2,64 - share.tolerance * 2};
}

void Player::update()
{
	status();
	move();
	shot();

	debug_changeLv();
}

void Player::draw()
{
	//playerHitBox.draw();
	//gridHitBox.draw();
	//collisionUp.draw(Color(Palette::Red));
	//collisionDown.draw(Color(Palette::Red));
	//collisionLeft.draw(Color(Palette::Red));
	//collisionRight.draw(Color(Palette::Red));

	if (playerImage.size() == 8)
		playerImage[(int)framePlayer].draw(playerPos);
}

void Player::status()
{
	playerImage.clear();

	if (lv == level1)
	{
		for (auto sprites : playerSprites_Lv1)
			playerImage << sprites;

		bulletLimit = 1;
		bulletSpeed = 600;
		bulletType = HE;
	}
	if (lv == level2)
	{
		for (auto sprites : playerSprites_Lv2)
			playerImage << sprites;

		bulletLimit = 1;
		bulletSpeed = 1000;
		bulletType = HE;
	}
	if (lv == level3)
	{
		for (auto sprites : playerSprites_Lv3)
			playerImage << sprites;

		bulletLimit = 2;
		bulletSpeed = 1000;
		bulletType = HE;
	}
	if (lv == level4)
	{
		for (auto sprites : playerSprites_Lv4)
			playerImage << sprites;

		bulletLimit = 2;
		bulletSpeed = 1000;
		bulletType = AP;
	}
}

void Player::move()
{
	//Print << gridCount;
	//Print << playerHitBox;

	if (pressedWASD(U"W"))
	{
		dir = up;

		framePlayer += frameSpeed * Scene::DeltaTime();
		if (framePlayer < 0 || framePlayer >= 2) framePlayer = 0;

		playerPos.x = gridHitBox.x;

		if (collision())
		{
			playerPos.y -= moveSpeed * Scene::DeltaTime();

			gridCount.x = 0;

			gridCount.y -= moveSpeed * Scene::DeltaTime();

			if (gridCount.y < -16)
			{
				gridCount.y += 32;
				gridPos.y--;
			}
		}
	}

	if (pressedWASD(U"S"))
	{
		dir = down;

		framePlayer += frameSpeed * Scene::DeltaTime();
		if (framePlayer < 2 || framePlayer >= 4) framePlayer = 2;

		playerPos.x = gridHitBox.x;

		if (collision())
		{
			playerPos.y += moveSpeed * Scene::DeltaTime();

			gridCount.x = 0;

			gridCount.y += moveSpeed * Scene::DeltaTime();

			if (gridCount.y > 16)
			{
				gridCount.y -= 32;

				gridPos.y++;
			}
		}
	}

	if (pressedWASD(U"A"))
	{
		dir = left;

		framePlayer += frameSpeed * Scene::DeltaTime();
		if (framePlayer < 4 || framePlayer >= 6) framePlayer = 4;

		playerPos.y = gridHitBox.y;

		if (collision())
		{
			playerPos.x -= moveSpeed * Scene::DeltaTime();

			gridCount.y = 0;

			gridCount.x -= moveSpeed * Scene::DeltaTime();

			if (gridCount.x < -16)
			{
				gridCount.x += 32;

				gridPos.x--;
			}
		}
	}

	if (pressedWASD(U"D"))
	{
		dir = right;

		framePlayer += frameSpeed * Scene::DeltaTime();
		if (framePlayer < 6 || framePlayer >= 8) framePlayer = 6;

		playerPos.y = gridHitBox.y;

		if (collision())
		{
			playerPos.x += moveSpeed * Scene::DeltaTime();

			gridCount.y = 0;

			gridCount.x += moveSpeed * Scene::DeltaTime();

			if (gridCount.x > 16)
			{
				gridCount.x -= 32;

				gridPos.x++;
			}
		}
	}

	gridHitBox = { map.gridMap[gridPos.x][gridPos.y],64,64 };
	playerHitBox = { playerPos.x + share.tolerance , playerPos.y + share.tolerance, 64 - share.tolerance * 2,64 - share.tolerance * 2 };
	collisionUp = { playerPos.x + 22, playerPos.y, 20, share.tolerance };
	collisionDown = { playerPos.x + 22, playerPos.y + 64, 20, share.tolerance };
	collisionLeft = { playerPos.x, playerPos.y + 22, share.tolerance,20 };
	collisionRight = { playerPos.x + 64, playerPos.y + 22, share.tolerance,20 };
}

void Player::shot()
{
	if (KeySpace.down())
	{
		if (bulletCount < bulletLimit)
		{
			bullet.isShot(bullet.player1, (int32)dir, playerPos, bulletSpeed);
			bulletCount++;
		}
	}
}

bool Player::collision()
{
	for (auto enemyHitBox : enemy.enemyHitBox)
	{
		if (dir == up)
		{
			RectF coll = collisionUp;

			if (!map.playArea.contains(coll))
				return false;

			if (enemyHitBox.intersects(coll))
				return false;
		}
		if (dir == down)
		{
			RectF coll = collisionDown;

			if (!map.playArea.contains(coll))
				return false;

			if (enemyHitBox.intersects(coll))
				return false;
		}
		if (dir == left)
		{
			RectF coll = collisionLeft;

			if (!map.playArea.contains(coll))
				return false;

			if (enemyHitBox.intersects(coll))
				return false;
		}
		if (dir == right)
		{
			RectF coll = collisionRight;

			if (!map.playArea.contains(coll))
				return false;

			if (enemyHitBox.intersects(coll))
				return false;
		}
	}

	return true;
}

void Player::debug_changeLv()
{
	if (Key1.down())
		lv = level1;
	if (Key2.down())
		lv = level2;
	if (Key3.down())
		lv = level3;
	if (Key4.down())
		lv = level4;
}

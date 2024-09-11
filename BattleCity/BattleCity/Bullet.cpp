#include "Bullet.h"

void Bullet::init()
{
	Texture bulletSprites{ U"example/image/bullet.png", TextureDesc::Mipped };

	for (int i = 0; i < 4; i++)
		bulletImage << bulletSprites(64 * i, 0, 64, 64);

	Texture boomSprites{ U"example/image/boom.png", TextureDesc::Mipped };

	for (int i = 0; i < 6; i++)
		boomImage << boomSprites(128 * i, 0, 128, 128);
}

void Bullet::update()
{
	move();
	collision();
}

void Bullet::draw()
{
	/// 当たり判定描画 ///
	//for (int i = 0; i < max; i++)
	//{
	//	if (number[i].active)
	//	{
	//		bulletHitBox[i].draw(Color(Palette::Orange));
	//		damageHitBox[i].draw(Color(Palette::Red));
	//	}
	//}

	for (auto num : number)
	{
		if (num.active)
		{
			bulletImage[(int)num.dir].draw(num.pos);
		}
	}

	for (auto& bomb : boom)
	{
		if (bomb.active)
		{
			boomImage[(int)bomb.frame].draw(bomb.pos);
			bomb.frame += frameSpeed * Scene::DeltaTime();

			if (bomb.frame > bomb.volume)
			{
				bomb.frame = 0;
				bomb.active = false;
			}
		}
	}
}

void Bullet::move()
{
	for (auto& num : number)
	{
		if (num.active)
		{
			if (num.dir == up)
				num.pos.y -= num.speed * Scene::DeltaTime();
			if (num.dir == down)
				num.pos.y += num.speed * Scene::DeltaTime();
			if (num.dir == left)
				num.pos.x -= num.speed * Scene::DeltaTime();
			if (num.dir == right)
				num.pos.x += num.speed * Scene::DeltaTime();
		}
	}

	for (int i = 0; i < max; i++)
	{
		if (number[i].dir == up)
		{
			bulletHitBox[i] = { number[i].pos.x,number[i].pos.y + 26,64,12 };
			damageHitBox[i] = { number[i].pos.x + 24,number[i].pos.y + 26,12,12 };
		}
		if (number[i].dir == down)
		{
			bulletHitBox[i] = { number[i].pos.x,number[i].pos.y + 26,64,12 };
			damageHitBox[i] = { number[i].pos.x + 24,number[i].pos.y + 26,12,12 };
		}
		if (number[i].dir == left)
		{
			bulletHitBox[i] = { number[i].pos.x + 26,number[i].pos.y,12,64 };
			damageHitBox[i] = { number[i].pos.x + 26,number[i].pos.y + 28,12,12 };
		}
		if (number[i].dir == right)
		{
			bulletHitBox[i] = { number[i].pos.x + 26,number[i].pos.y,12,64 };
			damageHitBox[i] = { number[i].pos.x + 26,number[i].pos.y + 28,12,12 };
		}
	}
}

void Bullet::collision()
{
	for (int i = 0; i < max; i++)
	{
		if (!map.playArea.contains(bulletHitBox[i]))
		{
			if (number[i].active)
			{
				number[i].active = false;

				/// 壁との爆発は3フレームまで /// ///戦車との爆発は6フレームまで///
				boom[i].volume = 3;
				boom[i].pos = { number[i].pos.x - 32, number[i].pos.y - 32 };
				boom[i].active = true;
			}
		}
	}
}

void Bullet::isShot(User user, int32 dir, Vec2 pos, int32 speed)
{
	for (auto& num : number)
	{
		if (!num.active)
		{
			num.user = user;
			num.dir = (Direction)dir;
			num.pos = pos;
			num.speed = speed;
			num.active = true;
			break;
		}
	}
}

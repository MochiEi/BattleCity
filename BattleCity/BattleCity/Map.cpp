#include "Map.h"

void Map::init()
{
	Texture frameSprites{ U"example/image/screen_game.png", TextureDesc::Mipped };

	for (int i = 0; i < 3; i++)
	{
		frame << frameSprites(1024 * i, 0, 1024, 896);
	}

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			gridMap[i][j] = { 64 + 32 * i, 32 + 32 * j };
		}
	}
}

void Map::update()
{

}

void Map::draw()
{
	frame[(int)frameNo].draw(0, 0);

	//プレイエリア範囲描画
	//playArea.draw(Color(Palette::Red));
}

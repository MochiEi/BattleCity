#include "Game.h"

GAME::GAME(const InitData& init) : IScene{ init }
{
	Texture frameSprites{ U"example/image/screen_game.png", TextureDesc::Mipped };

	for (int i = 0; i < 3; i++)
	{
		frame << frameSprites(1024 * i, 0, 1024, 896);
	}

	player.init();
}

GAME::~GAME()
{

}

void GAME::update()
{
	debug.game();
	player.update();
}

void GAME::draw() const
{
	frame[(int)frameNo].draw(0, 0);
	player.draw();
}

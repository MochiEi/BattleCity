#include "Game.h"

GAME::GAME(const InitData& init) : IScene{ init }
{
	map.init();
	player.init();
	bullet.init();
}

GAME::~GAME()
{

}

void GAME::update()
{
	debug.game();
	player.update();
	bullet.update();
}

void GAME::draw() const
{
	map.draw();
	player.draw();
	bullet.draw();
}

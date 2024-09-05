#include "Game.h"

GAME::GAME(const InitData& init) : IScene{ init }
{
	map.init();
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
	map.draw();
	player.draw();
}

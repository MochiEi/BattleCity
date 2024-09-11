#include "Game.h"

GAME::GAME(const InitData& init) : IScene{ init }
{
	map.init();
	player.init();
	enemy.init();
	bullet.init();
}

GAME::~GAME()
{

}

void GAME::update()
{
	debug.game();
	player.update();
	enemy.update();
	bullet.update();
}

void GAME::draw() const
{
	map.draw();
	player.draw();
	enemy.draw();
	bullet.draw();
}

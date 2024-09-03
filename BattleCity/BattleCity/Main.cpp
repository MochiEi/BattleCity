#include <Siv3D.hpp>
#include "Shared.h"

void Main()
{
	Window::Resize(1024, 896);
	Scene::SetResizeMode(ResizeMode::Keep);
	Scene::SetBackground(Palette::Black);

	App scene;

	scene.add<GAME>(U"Game");
	scene.init(U"Game", 0.1s);

	while (System::Update())
	{
		ClearPrint();
		deltaTime();

		if (not scene.update())
		{
			break;
		}
	}
}

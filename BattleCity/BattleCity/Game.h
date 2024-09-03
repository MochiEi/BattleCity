#pragma once
#include "Shared.h"

class GAME : public App::Scene
{
public:

	GAME(const InitData& init);

	~GAME();

	void update() override;

	void draw() const override;

private:

	Array<TextureRegion> frame;
	double frameNo = 2;
};

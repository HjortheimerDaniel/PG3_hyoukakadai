#pragma once
#include "IScene.h"

class TitleScene : public IScene
{
public:

	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void TitleAnimation();
	void Draw() override;

private:

	int titleWidth;
	int titleSprite;
	int timer;

};


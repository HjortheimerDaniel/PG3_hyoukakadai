#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Init()
{
	titleWidth = 0;
	titleSprite = Novice::LoadTexture("./Sprites/title.png");
	timer = 0;
}

void TitleScene::Update(char* keys, char* preKeys)
{
	if (!preKeys[DIK_RETURN] && keys[DIK_RETURN])
	{
		sceneNo = STAGE;
	}
	TitleAnimation();
}

void TitleScene::TitleAnimation()
{
	timer++;

	if (timer <= 30) 
	{
		titleWidth = 0;
	}
	else 
	{
		titleWidth = -1280;
	}

	if (timer >= 60) 
	{
		timer = 0;
	}
}

void TitleScene::Draw()
{
	Novice::DrawSprite(titleWidth, 0, titleSprite, 1, 1, 0.0f, WHITE);
}
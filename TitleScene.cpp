#include "TitleScene.h"
#include <Novice.h>

void TitleScene::Init()
{

}

void TitleScene::Update(char* keys, char* preKeys)
{
	if (!preKeys[DIK_RETURN] && keys[DIK_RETURN])
	{
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(600, 300, "TITLE");
	Novice::ScreenPrintf(527, 330, "'ENTER KEY' TO START");

}
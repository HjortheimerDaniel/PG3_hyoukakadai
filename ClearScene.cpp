#include "ClearScene.h"
#include "Novice.h"

void ClearScene::Init()
{
}

void ClearScene::Update(char* keys, char* preKeys)
{
	if (!preKeys[DIK_RETURN] && keys[DIK_RETURN])
	{
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(600, 300, "CLEAR");
	Novice::ScreenPrintf(467, 330, "'ENTER KEY' TO GO BACK TO TITLE");

}

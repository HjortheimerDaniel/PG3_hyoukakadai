#pragma once
#include <memory> //in order to use std::unique_ptr
#include "IScene.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include <Novice.h>



class GameManager
{
public:

	GameManager();

	~GameManager();

	int Run(char* keys, char* preKeys);

private:

	//keeps track of the scenes
	std::unique_ptr<IScene> sceneArr_[3];

	int currentSceneNo_;
	int prevSceneNo_;


};


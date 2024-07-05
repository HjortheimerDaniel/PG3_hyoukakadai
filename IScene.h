#pragma once

enum SCENE {
	TITLE,
	STAGE,
	CLEAR
};


class IScene
{
public:
	virtual void Init() = 0;

	virtual void Update(char* keys, char* preKeys) = 0;

	virtual void Draw() = 0;

	IScene();

	virtual ~IScene();

	int GetScene() { return sceneNo; };

protected:

	static int sceneNo;

	
};


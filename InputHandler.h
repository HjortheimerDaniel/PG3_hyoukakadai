#pragma once
#include "Command.h"
class InputHandler
{
public:

	ICommand* HandleInput();

	ICommand* HandleShootInput();

	void AssignMoveLeftCommand2PressKeyA();

	void AssignMoveRightCommand2PressKeyD();

	void AssignMoveUpCommand2PressKeyW();

	void AssignMoveDownCommand2PressKeyS();

	void AssignMoveUpRightCommand2PressKeyWD();

	void AssignMoveUpLeftCommand2PressKeyWA();

	void AssignMoveDownRightCommand2PressKeySD();

	void AssignMoveDownLeftCommand2PressKeySA();

	void AssignShotCommand2PressKeySpace();

private:
	ICommand* pressKeyD_;
	ICommand* pressKeyA_;
	ICommand* pressKeyW_;
	ICommand* pressKeyS_;
	ICommand* pressKeyWD_;
	ICommand* pressKeyWA_;
	ICommand* pressKeySD_;
	ICommand* pressKeySA_;
	ICommand* pressKeySpace_;
};


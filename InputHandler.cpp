#include "InputHandler.h"
#include "Novice.h"

ICommand* InputHandler::HandleInput()
{

    if (Novice::CheckHitKey(DIK_D))
    {
        return pressKeyD_;
    }
    if (Novice::CheckHitKey(DIK_A))
    {
        return pressKeyA_;
    }

    if (Novice::CheckHitKey(DIK_W))
    {
        return pressKeyW_;
    }
    if (Novice::CheckHitKey(DIK_S))
    {
        return pressKeyS_;
    }

    if (Novice::CheckHitKey(DIK_W) && Novice::CheckHitKey(DIK_D))
    {
        return pressKeyWD_;
    }
    if (Novice::CheckHitKey(DIK_W) && Novice::CheckHitKey(DIK_A))
    {
        return pressKeyWA_;
    }
    if (Novice::CheckHitKey(DIK_S) && Novice::CheckHitKey(DIK_D))
    {
        return pressKeySD_;
    }
    if (Novice::CheckHitKey(DIK_S) && Novice::CheckHitKey(DIK_A))
    {
        return pressKeySA_;
    }

    if (Novice::CheckHitKey(DIK_SPACE))
    {
        return pressKeySpace_;
    }
    

    return nullptr;
}

ICommand* InputHandler::HandleShootInput()
{
   

    return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
    ICommand* command = new MoveLeftCommand();
    this->pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
    ICommand* command = new MoveRightCommand();
    this->pressKeyD_ = command;
}

void InputHandler::AssignMoveUpCommand2PressKeyW()
{
    ICommand* command = new MoveUpCommand();
    this->pressKeyW_ = command;
}

void InputHandler::AssignMoveDownCommand2PressKeyS()
{
    ICommand* command = new MoveDownCommand();
    this->pressKeyS_ = command;
}

void InputHandler::AssignMoveUpRightCommand2PressKeyWD()
{
    ICommand* command = new MoveUpRightCommand();
    this->pressKeyWD_ = command;
}

void InputHandler::AssignMoveUpLeftCommand2PressKeyWA()
{
    ICommand* command = new MoveUpLeftCommand();
    this->pressKeyWA_ = command;
}

void InputHandler::AssignMoveDownRightCommand2PressKeySD()
{
    ICommand* command = new MoveDownRightCommand();
    this->pressKeySD_ = command;
}

void InputHandler::AssignMoveDownLeftCommand2PressKeySA()
{
    ICommand* command = new MoveDownLeftCommand();
    this->pressKeySA_ = command;
}

void InputHandler::AssignShotCommand2PressKeySpace()
{
    ICommand* command = new ShootCommand();
    this->pressKeySpace_ = command;
}

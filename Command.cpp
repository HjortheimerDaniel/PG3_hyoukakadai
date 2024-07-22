#include "Command.h"

ICommand::~ICommand()
{
}

void MoveRightCommand::Exec(Player& player)
{
	player.MoveRight();
}

void MoveLeftCommand::Exec(Player& player)
{
	player.MoveLeft();
}

void MoveUpCommand::Exec(Player& player)
{
	player.MoveUp();
}

void MoveDownCommand::Exec(Player& player)
{
	player.MoveDown();
}

void MoveUpRightCommand::Exec(Player& player)
{
	player.MoveUpRight();
}

void MoveUpLeftCommand::Exec(Player& player)
{
	player.MoveUpLeft();
}

void MoveDownRightCommand::Exec(Player& player)
{
	player.MoveDownRight();
}

void MoveDownLeftCommand::Exec(Player& player)
{
	player.MoveDownLeft();
}

void ShootCommand::Exec(Player& player)
{
	player.Shoot();
}

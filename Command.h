#pragma once
#include "Player.h"
class ICommand
{
public:
	virtual ~ICommand();
	virtual void Exec(Player& player) = 0;
};

class MoveRightCommand : public ICommand
{
public:
	void Exec(Player& player) override;
};

class MoveLeftCommand : public ICommand
{
public:
	void Exec(Player& player) override;
};

class MoveUpCommand : public ICommand
{
public:
	void Exec(Player& player) override;
};

class MoveDownCommand : public ICommand
{
public:
	void Exec(Player& player) override;
};

class MoveUpRightCommand : public ICommand
{
public:
	void Exec(Player& player) override;
};

class MoveUpLeftCommand : public ICommand
{
public:
	void Exec(Player& player) override;
};

class MoveDownRightCommand : public ICommand
{
public:
	void Exec(Player& player) override;
};

class MoveDownLeftCommand : public ICommand
{
public:
	void Exec(Player& player) override;
};

class ShootCommand : public ICommand
{
public:
	void Exec(Player& player) override;
};






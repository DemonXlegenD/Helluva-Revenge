#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Components/Entity.h"

class Character: public Entity
{
public:
	enum Direction { Left, Right };
	Character();
	Character(int _hp, int _damage,const float& _speed, const float& _attackSpeed, const float& _range);
	void Update(const float& _delta);
	void SetDirection(Direction _newDirection);
	Direction getDirection() { return direction; }

public:
	Direction direction;
	bool directionCharacter;
};


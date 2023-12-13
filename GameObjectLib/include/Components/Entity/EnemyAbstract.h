#pragma once
#include "Components/Entity.h"

class EnemyAbstract : public Entity
{
public:

	EnemyAbstract();
	EnemyAbstract(int _hp, int _damage, float _speed, float _attackSpeed, float _range);

};


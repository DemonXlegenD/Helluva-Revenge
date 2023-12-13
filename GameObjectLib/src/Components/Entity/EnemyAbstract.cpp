#include "Components/Entity/EnemyAbstract.h"


EnemyAbstract::EnemyAbstract() : Entity() {}

EnemyAbstract::EnemyAbstract(int _hp, int _damage, float _speed, float _attackSpeed, float _range) : Entity(_hp, _damage, _speed, _attackSpeed, _range) {};
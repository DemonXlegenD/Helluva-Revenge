#include "Components/Entity/Enemy/EnemyA.h"
#include "Scenes/SceneGameAbstract.h"

EnemyA::EnemyA() : EnemyAbstract()
{
	directionEnemy = false;
	direction = Direction::Left;
}

void EnemyA::Update(const float& _delta)
{
	Entity::Update(_delta);


}
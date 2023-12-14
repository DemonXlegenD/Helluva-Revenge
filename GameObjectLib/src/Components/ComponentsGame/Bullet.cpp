#include "Components/ComponentsGame/Bullet.h"
#include "Managers/SceneManager.h"
#include <cmath>

void Bullet::Update(const float& _delta)
{	
	Component::Update(_delta);
	Maths::Vector2f currentPosition = GetOwner()->GetPosition();
	const float distance = (currentPosition - initialPosition).Magnitude();
	if (distance > 1920.f) SceneManager::GetActiveGameScene()->RemoveGameObject(GetOwner());
}

float Bullet::GetDamageReduced() const
{
	Maths::Vector2f currentPosition = GetOwner()->GetPosition();
	const float distance = (currentPosition - initialPosition).Magnitude();

	return damage / (1.f + reductionFactor * pow(distance, 2));
}


float Bullet::GetDamageReduced(Maths::Vector2f& _currentPosition) const
{
	const float distance = (_currentPosition - initialPosition).Magnitude();

	return damage / (1.f + reductionFactor * pow(distance, 2));
}

void Bullet::AddAnimation(const std::string& _name, Animation* animation)
{
	sf::Texture* texture = new sf::Texture();
	if (animations.find(_name) == animations.end())
	{
		animations.insert(std::make_pair(_name, animation));
	}
}

Animation* Bullet::GetAnimation(const std::string& _name)
{
	if (animations.find(_name) != animations.end())
	{
		return animations.at(_name);
	}
	return nullptr;
}
Animation* Bullet::GetAndSetAnimation(const std::string& _name)
{
	if (animations.find(_name) != animations.end())
	{
		actualAnimation = animations.at(_name);
		return actualAnimation;
	}
	return nullptr;
}
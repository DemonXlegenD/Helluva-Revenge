#pragma once

#include "Components/Entity.h"

class ProtectionBall : public Entity
{
public:

	ProtectionBall();
	ProtectionBall(const int& _hp, const int& _damage, const float& _speed, const float& _attackSpeed, const float& _range);
	
	void SetHades(GameObject* _hades) { hades = _hades; }
	void Die() override;
		
private:
	GameObject* hades = nullptr;
};


class AstralBall : public Entity
{
public:

	AstralBall();
	AstralBall(const int& _hp, const int& _damage, const float& _speed, const float& _attackSpeed, const float& _range);

	void SetHades(GameObject* _hades) { hades = _hades; }

	void Power();

private:
	GameObject* hades = nullptr;
};

class SpirituelBall : public Entity
{
public:

	SpirituelBall();
	SpirituelBall(const int& _hp, const int& _damage, const float& _speed, const float& _attackSpeed, const float& _range);

	void SetHades(GameObject* _hades) { hades = _hades; }

	void update(const float& _delta) {}

private:
	GameObject* hades = nullptr;
};

class GreenBall : public Entity
{
public:

	GreenBall();
	GreenBall(const int& _hp, const int& _damage, const float& _speed, const float& _attackSpeed, const float& _range);

	void SetHades(GameObject* _hades) { hades = _hades; }

	void update(const float& _delta) {}

private:
	GameObject* hades = nullptr;
};
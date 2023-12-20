<<<<<<< Updated upstream
#include "Components/Entity/Enemy/ProtectionBall.h"
#include "Components/Entity/Enemy/Hades.h"
=======
#include "BuildersGameObject/BuilderEntityGameObject.h"
#include "Components/Entity/Character.h"
#include "Components/Entity/Enemy/Hades.h"
#include "Components/Entity/Enemy/ProtectionBall.h"
#include "Components/Shapes/Rectangle.h"
#include "Managers/SceneManager.h"
>>>>>>> Stashed changes

ProtectionBall::ProtectionBall() : Entity() {}
ProtectionBall::ProtectionBall(const int& _hp, const int& _damage, const float& _speed, const float& _attackSpeed, const float& _range) : Entity(_hp, _damage, _speed, _attackSpeed, _range) {}

<<<<<<< Updated upstream
void ProtectionBall::Die()
{
	Entity::Die();
=======
void ProtectionBall::Update(const float& _delta)
{
	Entity::Update(_delta);
	SetPower(_delta);

	if (spawn == 7) {
		deathTimer += _delta;
		if (deathTimer >= 8.0f) {
			Die();
		}

		// Mise à jour de la durée de vie des zones de réduction des dégâts
		for (auto it = damageReductionZones.begin(); it != damageReductionZones.end(); ) {
			it->second -= _delta;
			if (it->second <= 0) {
				// Détruire la zone
				SceneManager::GetActiveGameScene()->RemoveGameObject(it->first);
				it = damageReductionZones.erase(it);
			}
			else {
				++it;
			}
		}
	}
}

void ProtectionBall::SetHealth()
{
	switch (spawn)
	{
	case 0:
		SetHealthPoint(175.f);
		SetMaxHealthPoint(175.f);
		break;
	case 1:
		break;
	case 2:
		SetHealthPoint(50.f);
		SetMaxHealthPoint(50.f);
		break;
	case 3:
		SetHealthPoint(250.f);
		SetMaxHealthPoint(250.f);
		break;
	case 4:
		
		break;
	case 5:
		SetHealthPoint(100.f);
		SetMaxHealthPoint(100.f);
		break;
	case 6:
		break;
	case 7:
		SetHealthPoint(125.f);
		SetMaxHealthPoint(125.f);
		break;
	default:
		break;
	}
}

void ProtectionBall::SetPower(const float& _delta)
{
	switch (spawn)
	{
	case 2: 
		if (tp >= 5)
		{
			randX = rand() % 1300 + 500;
			randY = rand() % 400 + 200;
			GetOwner()->SetPosition(Maths::Vector2f(randX, randY));
			tp = 0;
		}
		tp += _delta;
		break;
	default:
		break;
	}
}

void ProtectionBall::Die()
{
	Entity::Die();
	switch (spawn)
	{
	case 0: 
		hades->GetComponent<Hades>()->SetIncible(false);
		hades->GetComponent<Hades>()->TakeDamage(50);
		hades->GetComponent<Hades>()->SetIncible(true);
		break;
	case 5:
		player->GetComponent<Character>()->TakeHealt(10);
		break;
	case 6:
		break;
	case 7:
		CreateDamageReductionZone(GetOwner()->GetPosition());
		break;
	default:
		break;
	}
>>>>>>> Stashed changes
	hades->GetComponent<Hades>()->RemoveBall(GetOwner());
}

void ProtectionBall::CreateDamageReductionZone(const Maths::Vector2f& position) {
	// Paramètres de la zone
	float width = 200.0f;  // Largeur de la zone
	float height = 50.0f;  // Hauteur de la zone
	float duration = 15.0f; // Durée de vie de la zone en secondes

	// Création de la zone de réduction des dégâts
	GameObject* damageReductionZone = BuilderEntityGameObject::CreatePlatformCollisionGameObject(
		"DamageReductionZone",
		position.x, position.y,
		width, height
	);

	Rectangle* zoneVisual = damageReductionZone->CreateComponent<Rectangle>();
	zoneVisual->GetRectangleShape().setFillColor(sf::Color(128, 0, 128)); // Couleur violette
	zoneVisual->GetRectangleShape().setSize(sf::Vector2f(width, height)); // Définir la taille

	SceneManager::GetActiveGameScene()->AddGameObject(damageReductionZone);
	damageReductionZones[damageReductionZone] = duration;
}

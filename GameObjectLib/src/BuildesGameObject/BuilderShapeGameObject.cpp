#include "BuildersGameObject/BuilderShapeGameObject.h"
#include "Managers/SceneManager.h"
#include "Components/Shapes/Carre.h"
#include "Components/RigidBody2D.h"

GameObject* BuilderShapeGameObject::CreatePlatformeGameObject(const std::string& _name, const float& _positionx, const float& _positiony)
{
	GameObject* gameObject = SceneManager::GetActiveScene()->CreateGameObject(_name);
	gameObject->SetPosition(Maths::Vector2f(_positionx, _positiony));
	gameObject->SetActive(false);

	Carre* carre = gameObject->CreateComponent<Carre>();
	carre->SetSize(100);
	carre->SetOrigin();

	RigidBody2D* rigidBody = gameObject->CreateComponent<RigidBody2D>();
	rigidBody->SetIsGravity(false);



	return gameObject;
};


#include "Scenes/ScenesGame/SceneGameWorld.h"
#include "BuilderGameObject.h"

#include "BuildersGameObject/BuilderEntityGameObject.h"
#include "Components/Entity/Character.h"


SceneGameWorld::SceneGameWorld(const std::string& _newName) : SceneGameAbstract(_newName) {}

void SceneGameWorld::Preload()
{
	SceneGameAbstract::Preload();
	AssetManager::AddAsset("BackgroundMapBackgroundWorld", "../Assets/Graphics/Maps/worldMapBackground.png");
	//AssetManager::AddAsset("BackgroundMapWorld", "../Assets/Graphics/Maps/worldMap1.png");
	AssetManager::AddAsset("idleEnemyA", "../Assets/Enemy/Hell-Beast-Files/PNG/with-stroke/hell-beast-idle.png");
}

void SceneGameWorld::Create()
{
	SceneGameAbstract::Create();
	CreatePlayer();
	CreateEnemy();

	GameObject* OverWorldMap = BuilderGameObject::CreateBackgroundOverWorldGameObject("BackgroundMapWorld1", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2, 0.47f, 0.47f, AssetManager::GetAsset("BackgroundMapBackgroundWorld"));
	OverWorldMap->SetPosition(Maths::Vector2f(OverWorldMap->GetPosition().x, OverWorldMap->GetPosition().y));
	float distance = (WindowManager::GetWindowWidth() / 2.0f) - (13600.0f / 2.0f);
	OverWorldMap->SetPosition(Maths::Vector2f(-distance, OverWorldMap->GetPosition().y));
	//GameObject* backgroundWorldMap2 = BuilderGameObject::CreateBackgroundGameObject("BackgroundMapWorld2", WindowManager::GetWindowWidth() / 2, WindowManager::GetWindowHeight() / 2, 0.47f, 0.47f, AssetManager::GetAsset("BackgroundMapWorld"));
	plateform = BuilderEntityGameObject::CreatePlateformGameObject("plateform", WindowManager::GetWindowWidth() / 2, 1200, 100, 1);
	this->CreatePlatformCollision();
}

void SceneGameWorld::CreatePlatformCollision()
{
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform1", 25, 1015, 0.6f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform2", 115, 1057, 0.3f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform3", 157, 1115, 0.52f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform4", 98, 1075, 0.1f, 1.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform5", 278, 1035, 0.1f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform5", 258, 1055, 0.1f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform6", 238, 1077, 0.1f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform6", 218, 1096, 0.1f, 0.5f));
	platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("MurExtremiteGauche", -25, 1015, 0.1f, 10.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform2", 215, 834, 0.15f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform3", 235, 910, 0.70f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform4", 166, 870, 0.1f, 1.1f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform5", 320, 885, 0.15f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform6", 345, 858, 0.15f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform7", 370, 831, 0.15f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform8", 510, 806, 1.3f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform9", 842, 935, 0.76f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform10", 1050, 860, 0.50f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform11", 1304, 870, 1.27f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform12", 1497, 950, 0.65f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform13", 1742, 870, 1.8f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform14", 754, 744, 0.64f, 0.96f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform15", 907, 744, 0.63f, 1.95f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform16", 1125, 655, 0.88f, 1.47f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform16", 1010, 680, 0.27f, 0.47f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform17", 1187, 900, 0.1f, 1.25f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform18", 1421, 910, 0.1f, 1.30f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform19", 1571, 910, 0.1f, 1.30f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform20", 1725, 757, 0.13f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform21", 1778, 705, 0.13f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform22", 1675, 807, 0.38f, 0.5f));
	//platformCarreCollision.push_back(BuilderEntityGameObject::CreatePlatformCollisionGameObject("Platform23", 1868, 693, 0.50f, 1.0f));

	platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle1", 7.1f, 7.1f, 135, 1054, 180));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle2", 7.7f, 7.7f, 1360, 715, 90));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle3", 7.7f, 7.7f, 1310, 853, 180));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle4", 7.7f, 7.7f, 1312, 700, 180));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle5", 7.7f, 7.7f, 1157, 905, 180));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle6", 7.7f, 7.7f, 1192, 940, 180));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle7", 7.7f, 7.7f, 785, 940, 180));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle8", 7.7f, 7.7f, 737, 895, 180));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle9", 7.5f, 7.5f, 692, 850, 180));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle10", 7.9f, 7.9f, 214, 833, 180));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle11", 7.7f, 7.7f, 965, 879, 90));
	//platformTriangleCollision.push_back(BuilderEntityGameObject::CreatePlatformTriangleCollisionGameObject("Triangle12", 7.7f, 7.7f, 1006, 840, 90));
}

void SceneGameWorld::CreateEnemy()
{
	std::cout << "okk";
	enemy = BuilderEntityGameObject::CreateEnemyAGameObject("EnemyA", WindowManager::GetWindowWidth() / 2, 40.f, 7.f, 7.f, AssetManager::GetAsset("idleEnemyA"));
}

void SceneGameWorld::Delete()
{
	Scene::Delete();
}

void SceneGameWorld::Render(sf::RenderWindow* _window)
{
	Scene::Render(_window);
	_window->draw(isPause ? backgroundAlpha2.backgroundAlpha : backgroundAlpha1.backgroundAlpha);
}

void SceneGameWorld::Collision(GameObject* _entity)
{
	RigidBody2D* rigidBody = player->GetComponent<RigidBody2D>();
	Entity* entityPlayer = player->GetComponent<Entity>();

	for (auto& platform : platformCarreCollision)
	{
		if (platform && RigidBody2D::IsColliding(*rigidBody, *(platform->GetComponent<RigidBody2D>())))
		{
			rigidBody->SetIsGravity(false);
			entityPlayer->SetOnFloor(true);
			break;
		}
	}

	if (!entityPlayer->GetOnFloor())
	{
		rigidBody->SetIsGravity(true);
		entityPlayer->SetOnFloor(false);
	}

	if (_entity && plateform)
	{
		if (RigidBody2D::IsColliding(*(_entity->GetComponent<RigidBody2D>()), *(plateform->GetComponent<RigidBody2D>())))
		{
			_entity->GetComponent<RigidBody2D>()->SetIsGravity(false);
			_entity->GetComponent<Entity>()->SetOnFloor(true);
		}
		else if (!RigidBody2D::IsColliding(*(_entity->GetComponent<RigidBody2D>()), *(plateform->GetComponent<RigidBody2D>())))
		{
			_entity->GetComponent<RigidBody2D>()->SetIsGravity(true);
			_entity->GetComponent<Entity>()->SetOnFloor(false);
		}
	}
	
}

void SceneGameWorld::Update(const float& _delta)
{
	SceneGameAbstract::Update(_delta);
	Collision(player);
	Collision(enemy);
}
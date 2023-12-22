#pragma once

#include "Scenes/SceneGameAbstract.h"

class SceneGameOverworld : public SceneGameAbstract 
{
public:
	SceneGameOverworld(const std::string& _newName);
	~SceneGameOverworld();

	void Awake() override;
	void Preload() override;

	void Collinding();

	void Create() override;
	void Delete() override;
	void Physics(const float& _delta) override;
	void Update(const float& _delta) override;
	void Render(sf::RenderWindow* _window) override;

private:
	GameObject* tileMap = nullptr;
};


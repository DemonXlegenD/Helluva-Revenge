#include "Engine.h"
#include "Managers/WindowManager.h"
#include "Managers/SceneManager.h"
#include "Managers/TimeManager.h"
#include "Managers/EventManager.h"
#include "Managers/WindowManager.h"
#include "Managers/HUDManager.h"
#include "Managers/FontManager.h"
#include "Managers/CameraManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

#include "Scenes/SceneGameUnderground.h"
#include "Scenes/SceneGameWorld.h"
#include "Scenes/SceneGameAbstract.h"
#include "Scenes/ScenesGame/ScenesTest.h"
Engine* Engine::instance = nullptr;

Engine* Engine::GetInstance()
{
	if (instance == nullptr)
		instance = new Engine();

	return instance;
}

void Engine::Init() const
{
	WindowManager::Init();
	TimeManager::Init();
	FontManager::AddFont("Roboto", "../Assets/Fonts/Roboto-Medium.ttf");
	FontManager::AddFont("PixelNES", "../Assets/Fonts/PixelNES.otf");
	CameraManager::Init(WindowManager::GetWindow());
	HUDManager::Init(WindowManager::GetWindow());
	SceneManager::AddScene("SceneMainMenu", new SceneMainMenu(std::string("MainMenu")));
	//SceneManager::AddScene("SceneGameUnderground", new SceneGameUnderground(std::string("SceneGameUnderground")));
	SceneManager::AddScene("SceneGameAbstract", new SceneGameAbstract(std::string("SceneGameAbstract")));
	SceneManager::AddScene("ScenesTest", new ScenesTest(std::string("ScenesTest")));
	SceneManager::AddScene("SceneGameWorld", new SceneGameWorld(std::string("SceneGameWorld")));
}

void Engine::Run() const
{
	SceneManager::RunScene("SceneMainMenu");
	while (!shouldQuit)
	{
		TimeManager::Update();

		const float delta = TimeManager::GetDeltaTime();
		sf::RenderWindow* window = WindowManager::GetWindow();
		EventManager::Update(delta);
		SceneManager::GetActiveScene()->Update(delta);

		WindowManager::Clear();

		HUDManager::Render(window);

		SceneManager::GetActiveScene()->Render(window);
		WindowManager::Display();
	}
}

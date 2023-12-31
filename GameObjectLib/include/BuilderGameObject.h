#pragma once
#include "GameObject.h"
#include "Components/Inputs/InputCharacter.h"

class BuilderGameObject
{
public:
	static GameObject* CreateButtonGameObject(const std::string& _name, const float& _x, const float& _y, const unsigned int& _fontSize);
	static GameObject* CreateButtonGameObject(const std::string& _name, const float& _x, const float& _y, const float& _width, const float& _height, const unsigned int& _fontSize);
	static GameObject* CreateButtonGameObject(const std::string& _name, const float& _x, const float& _y, const float& _scaleX, const float& _scaleY, const float& _frameWidth, const float& _frameHeight, const float& _totalFrameWidth, const float& _totalFrameHeight, sf::Texture* _texture, const unsigned int& _fontSize);

	static GameObject* CreateBackgroundGameObject(const std::string& _name, const float& _x, const float& _y, const float& _scalex, const float& _scaley, sf::Texture* _texture);
	static GameObject* CreateBackgroundGameObject(const std::string& _name, const float& _x, const float& _y, const Maths::Vector2f& _size, const float& _scalex, const float& _scaley, const LayerType& _layer, const sf::Color& _color);
	static GameObject* CreateBackgroundGameObject(const std::string& _name, const float& _x, const float& _y, const float& _scalex, const float& _scaley, sf::Texture* _texture, int _number);
	static GameObject* CreateBackgroundGameObject(const std::string& _name, const float& _x, const float& _y, const float& _scalex, const float& _scaley, sf::Texture* _texture, int _number, const float& _depth);
	static GameObject* CreateInputGameObject(const std::string& _name, const float& _x, const float& _y);
	static GameObject* CreateTextDialogueGameObject(const std::string& _name,const std::string& _firstText, const float& _x, const float& _y, const float& _width, const float& _height, const unsigned int& _fontSize, const sf::Uint32& _style, const sf::Color& _color);
	static GameObject* CreateDropDownGameObject(const std::string& _name, const float& _x, const float& _y, std::vector<std::string>& _buttons , const unsigned int& _fontSize);

	static GameObject* CreateSliderGameObject(const std::string& _name, const float& _x, const float& _y, const float& _widthBar, const float& _heightBar, const float& _widthCursor, const float& _heightCursor, const unsigned int& _fontSize, const float& _data, const float& _maxData);
	static GameObject* CreateSliderGameObject(const std::string& _name, const float& _x, const float& _y, const float& _widthBar, const float& _heightBar, const float& _widthCursor, const float& _heightCursor, const unsigned int& _fontSize, const float& _data, const float& _minData, const float& _maxData);
};


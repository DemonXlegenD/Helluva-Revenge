#include "Components/SpriteRenderer.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "Managers/AssetManager.h"
#include "Managers/HUDManager.h"
#include "Managers/CameraManager.h"
#include "Components/RigidBody2D.h"
Sprite::Sprite()
{
	scalex = 1.0f;
	scaley = 1.0f;
}

sf::Vector2f Sprite::GetBounds() const
{
	return sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height);
}

void Sprite::SetScale()
{
	scalex = GetOwner()->GetScale().GetX();
	scaley = GetOwner()->GetScale().GetY();
	sprite.setScale(scalex, scaley);
}

void Sprite::SetScale(const float& _scaleX, const float& _scaleY)
{
	scalex = _scaleX;
	scaley = _scaleY;
	sprite.setScale(_scaleX, _scaleY);
}

void Sprite::SetOrigin()
{
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
}

void Sprite::SetSprite()
{
	const Maths::Vector2f position = GetOwner()->GetPosition();
	sprite.setPosition(position.x, position.y);
}

void Sprite::SetTexture(sf::Texture* _texture)
{
	texture = _texture;
	sprite.setTexture(*texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	SetScale();
}


void Sprite::SetTexture(sf::Texture* _texture, unsigned int& _frame)
{
	texture = _texture;
	sprite.setTexture(*texture);
}

void Sprite::SetRecTexture(const unsigned int& _frame, const int& width, const int& height)
{
	sprite.setTextureRect(sf::IntRect(width * _frame, 0, width, height));
	sprite.setOrigin(width / 2, height / 2);
	RigidBody2D* rigidBody2D = GetOwner()->GetComponent<RigidBody2D>();
	rigidBody2D->SetSize(width, height);
	rigidBody2D->SetScale(scalex, scaley);
}

void Sprite::SetRecTexture(const unsigned int& _frameWidth, const unsigned int& _frameHeight, const int& _width, const int& _height)
{
	width = _width;
	height = _height;
	sprite.setTextureRect(sf::IntRect(_width * _frameWidth, _height * _frameHeight, _width, _height));
	sprite.setOrigin(width / 2, height / 2);
	RigidBody2D* rigidBody2D = GetOwner()->GetComponent<RigidBody2D>();
	rigidBody2D->SetSize(width, height);
	rigidBody2D->SetScale(scalex, scaley);
}


void Sprite::SetRecTextureWithFrame(const unsigned int& _actualFrameWidth, const unsigned int& _actualFrameHeight, const unsigned int& _frameWidth, const unsigned int& _frameHeight)
{
	const float _width = sprite.getLocalBounds().width;
	const float _height = sprite.getLocalBounds().height;
	const float widthAfterFrame = _width / _frameWidth;
	const float heightAfterFrame = _height / _frameHeight;
	width = widthAfterFrame;
	height = heightAfterFrame;
	sprite.setTextureRect(sf::IntRect(widthAfterFrame * _actualFrameWidth, heightAfterFrame * _actualFrameHeight, _width / _frameWidth, _height / _frameHeight));
	sprite.setOrigin(width / 2, height / 2);
	RigidBody2D* rigidBody2D = GetOwner()->GetComponent<RigidBody2D>();
	rigidBody2D->SetSize(width, height);
	rigidBody2D->SetScale(scalex, scaley);
}

void Sprite::Rotate(const float& angle)
{
	rotate = angle;
	sprite.setRotation(angle);
}

void Sprite::Update(const float& _delta)
{
	if (isActive) this->SetSprite();
}

void Sprite::Render(sf::RenderWindow* _window)
{
	if (isVisible)
	{
		Component::Render(_window);
		_window->draw(sprite);
	}

}

void Sprite::RenderGUI(sf::RenderWindow* _window)
{
	if (isVisible)
	{
		Component::RenderGUI(_window);
		_window->draw(sprite);
	}
}

#include "Player.h"
#include "Sprite.h"
#include "Actor.h"
#include <raylib.h>

Player::Player() 
{
	Actor::m_translation = new MathLibrary::Matrix3();
	Actor::m_globalTransform = new MathLibrary::Matrix3();
	m_localTransform = new MathLibrary::Matrix3();
	m_rotation = new MathLibrary::Matrix3();
	

	
};

void Player::GetPlayerInput()
{
	if (IsKeyDown(KEY_RIGHT))
		Player::m_globalTransform->m11 + 1;
	if (IsKeyDown(KEY_LEFT))
		Player::m_globalTransform->m11 - 1;
	if (IsKeyDown(KEY_UP))
		Player::m_globalTransform->m22 + 1;
	if (IsKeyDown(KEY_DOWN))
		Player::m_globalTransform->m22 - 1;
}

void Player::draw()
{
	Actor::draw();
}

void Player::update(float deltaTime)
{
	Player::GetPlayerInput();
	Actor::update(deltaTime);
}


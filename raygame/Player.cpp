#include "Player.h"
#include "Sprite.h"
#include "Actor.h"
#include <raylib.h>

Player::Player() 
{
	Actor::m_translation = new MathLibrary::Matrix3();
	Actor::m_globalTransform = new MathLibrary::Matrix3();
	Actor::m_localTransform = new MathLibrary::Matrix3();
	Actor::m_rotation = new MathLibrary::Matrix3();
	Actor::m_translation = new MathLibrary::Matrix3();
	Actor::m_scale = new MathLibrary::Matrix3();
	m_sprite = "Images/player.png";
	

	
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
	DrawCircle(getWorldPosition().x * 32, getWorldPosition().y * 32, 50, BLUE);
	/*Actor::draw();*/
	//m_sprite.draw(MathLibrary::Matrix3());
}

void Player::update(float deltaTime)
{
	Player::GetPlayerInput();
	Actor::update(deltaTime);
}


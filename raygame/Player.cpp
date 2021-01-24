#include "Player.h"
#include "Sprite.h"
#include "Actor.h"
#include <raylib.h>


Player::Player(float x, float y, const char* spriteFilePath, float collisionradius,  float speed, float maxspeed) :
Actor::Actor(x, y, collisionradius, speed, maxspeed)
{
	
	speed = m_soeed;
	collisionradius = m_collisionradius;
	maxspeed = m_maxspeed;
	m_sprite = *new Sprite(spriteFilePath);
    Actor::setLocalPosition(MathLibrary::Vector2(x, y));
	m_sprite = *new Sprite("Image/player.PNG");
}
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
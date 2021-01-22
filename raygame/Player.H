#pragma once

#include "Player.h"
#include "Actor.h"
#include "Sprite.h"
#include <Vector2.h>
#include <Matrix3.h>

class Player : Actor
{
public:
	Player();

	// <param> float x: Set the player's X position.
	// <param> float y: Set the player's y position.
	// <param> float speed: set the players speed to a certain value.
	// <param> float collisionradius:
	// <param> float maxspeed: set the payer's max speed to a certain value.
	Player(float x, float y, float collisionradius, Sprite m_sprite, float speed, float maxspeed);

	Player(float x, float y, Sprite* sprite, char icon = ' ');

	// <param> float x: Set the player's X position.
	// <param> float y: Set the player's y position.
	// <param> float speed: set the players speed to a certain value.
	// <param> float maxspeed: set the payer's max speed to a certain value.
	Player(float x, float y, const char* spriteFilePath, float collisionradius, float speed, float maxspeed);

	void update(float deltaTime) override;

	// A function that will be called and used for player input and movement of players sprite.
	void GetPlayerInput();

	bool checkCollision(Player* other);

	void OnCollision();

	void draw() override;




protected:

	MathLibrary::Matrix3* m_globalTransform;
	MathLibrary::Matrix3* m_localTransform;
	MathLibrary::Matrix3* m_rotation;
	MathLibrary::Matrix3* m_translation;
	MathLibrary::Matrix3* m_scale;
	MathLibrary::Vector2 m_acceleration;



private:

	float m_soeed;
	float m_maxspeed;
	float m_collisionradius;
	Sprite m_sprite;

};
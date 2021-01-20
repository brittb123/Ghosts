#pragma once

#include "Player.h"
#include "Actor.h"

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
	Player(float x, float y, float collisionradius, float speed, float maxspeed);


	// <param> float x: Set the player's X position.
	// <param> float y: Set the player's y position.
	// <param> float speed: set the players speed to a certain value.
	// <param> float maxspeed: set the payer's max speed to a certain value.
	Player(float x, float y, Sprite sprite, float collisionradius, float speed, float maxspeed);

	//A function to set a players local position to a specific point of the screen.
	void setLocalPosition(MathLibrary::Vector2 value);

	MathLibrary::Vector2 getLocalPosition();

	// A function that will be called and used for player input and movement of players sprite.
	void GetPlayerInput();

	bool checkCollision(Player* other);

	void OnCollision();




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

};
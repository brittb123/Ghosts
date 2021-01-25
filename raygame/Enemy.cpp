#pragma once
#include <cmath>;
#include "Actor.h"
#include "raylib.h"
#include "Enemy.h";


Enemy::Enemy()
{
}

Enemy::Enemy(float x, float y, MathLibrary::Vector2 newPoint, char icon)
{
	Actor m_target;
	Color m_alertColor;
	m_currentPoint = MathLibrary::Vector2();
	m_newPoint = MathLibrary::Vector2();
	float m_speed;
	Sprite m_sprite;
}

Enemy::Enemy(float x, float y, MathLibrary::Vector2 newPoint, Sprite* sprite, char icon)
{
	m_newPoint = newPoint;
	m_currentPoint = newPoint;
	m_sprite = *sprite;
}

Enemy::Enemy(float x, float y, Color rayColor, MathLibrary::Vector2 newPoint, const char* spriteFilePath, char icon)
{
	m_alertColor = CLITERAL(RED);
	m_newPoint = newPoint;
	m_currentPoint = newPoint;

	m_sprite =* new Sprite(spriteFilePath);
	m_sprite = *new Sprite("Image/blue.PNG");
}

//this will be done after we get the main game working~
//bool Enemy::checkTargetInSight(float maxAngle, float maxDistance)
//{
//	//Checks if the target has a value before continuing
//	/*if (m_target)
//		return false;*/
//
//	//Find the vector representing the distance between the actor and its target
//	Vector2 direction = target.getLocalPosition - getLocalPosition;
//	//Get the magnitude of the distance vector
//	float distance = direction.(float)getMagnitude;
//	//Use the inverse cosine to find the angle of the dot product in radians
//	float angle = _NODISCARD::math.acos(Vector2::(getForward, Vector2::(direction).getNormalized).dotProduct);
//
//	//Return true if the angle and distance are in range
//	if (angle <= maxAngle && distance <= maxDistance)
//		return true;
//
//	return false;
//}

//do second
void Enemy::updatePatrolLocation()
{
	//Calculate the distance between the current patrol point and the current position
	MathLibrary::Vector2 direction = m_currentPoint - getLocalPosition();
	float distance = direction.getMagnitude();

	//Switch to the new patrol point if the enemy is within distance of the current one
	if (m_currentPoint == m_newPoint && distance <= 1)
		m_currentPoint = m_newPoint; //<---new point is supposed to be point B
	else if (m_currentPoint == m_newPoint && distance <= 1) //<----new point is supposed to be point B
		m_currentPoint = m_newPoint;

	//Calcute new velocity to travel to the next waypoint
	direction = m_currentPoint - getLocalPosition();
	/*velocity = direction.getNormalized * speed;*/
}

//do second
void Enemy::update(float deltaTime)
{
	//dependant on checkTargetInSight so will be adding later
	updatePatrolLocation();
	Actor::update(deltaTime);
}



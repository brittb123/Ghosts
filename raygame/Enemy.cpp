#pragma once
#include <cmath>;

#include "Actor.h"
#include "Enemy.h";



//Add points

//remove points

/// <param name="x">Position on the x axis</param>
/// <param name="y">Position on the y axis</param>
/// <param name="icon">The symbol that will appear when drawn</param>
Enemy::Enemy(float x, float y, MathLibrary::Vector2 newPoint, char icon = ' ')
{
	m_newPoint = newPoint;
	m_currentPoint = newPoint;
}
Enemy::Enemy(float x, float y, Color rayColor, MathLibrary::Vector2 newPoint, char icon = ' ')
{
	m_alertColor = CLITERAL(RED);
	m_newPoint = newPoint;
	m_currentPoint = newPoint;

	/*m_sprite = new Sprite("Images/enemy.png");*/
}

//do second
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
	float distance = direction.getMagnitude;
}


void Enemy::draw()
{
	Enemy::m_sprite.draw*(getWorldPosition());
	Actor::draw();
}

//do second
void Enemy::update(float deltaTime)
{
	//dependant on checkTargetInSight so will be adding later

	updatePatrolLocation();
	Actor::update(deltaTime);
}



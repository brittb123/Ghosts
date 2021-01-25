#pragma once

#include <Vector2.h>
#include <Matrix3.h>
#include <math.h>

#include "Actor.h"
#include "Sprite.h"
#include "raylib.h"

class Sprite;

class Enemy : public Actor
{
public:
	Enemy();
	Enemy(float x, float y, MathLibrary::Vector2 newPoint, char icon = ' ');
	Enemy(float x, float y, MathLibrary::Vector2 newPoint, Sprite* sprite, char icon = ' ');
	Enemy(float x, float y, Color rayColor, MathLibrary::Vector2 newPoint, const char* spriteFilePath, char icon = ' ');
private:
	Actor m_target;
	Color m_alertColor;

	//there is 13 patrol points, this allows the enemy to move to different points without player needing to control it
	MathLibrary::Vector2 m_patrolPointA;
	MathLibrary::Vector2 m_patrolPointB;
	MathLibrary::Vector2 m_patrolPointC;
	MathLibrary::Vector2 m_patrolPointD;
	MathLibrary::Vector2 m_patrolPointE;
	MathLibrary::Vector2 m_patrolPointF;
	MathLibrary::Vector2 m_patrolPointG;
	MathLibrary::Vector2 m_patrolPointH;
	MathLibrary::Vector2 m_patrolPointI;
	MathLibrary::Vector2 m_patrolPointJ;
	MathLibrary::Vector2 m_patrolPointK;
	MathLibrary::Vector2 m_patrolPointL;
	MathLibrary::Vector2 m_patrolPointM;

	//points 
	MathLibrary::Vector2 m_currentPoint;
	MathLibrary::Vector2 m_newPoint;

	float m_speed;
	Sprite m_sprite;

public:
	//speed
	float setSpeed(float value);
	float getSpeed() { return m_speed;};

	//target
	Actor getTarget() { return m_target; };

	//this will most likely be moved to game since it will be added during game
	//Add points

	//remove points

	bool checkTargetInSight() {};

private:
	void updatePatrolLocation() {};

public:
	//this will be getting the sprite and draw and 
	void draw() override;
	//this overrides the update from Actor class and changes it in a way that benifits the Enemy, which is mainly updating patrol 
	void update(float deltaTime) override {};
};

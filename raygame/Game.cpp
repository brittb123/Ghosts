#pragma once

#include <iostream>
#include <Vector2.h>
#include <Matrix3.h>
#include "raylib.h"
#include "Game.h"
#include "Enemy.h"
#include "Player.H"
#include "Actor.h";

//To Britt:
//can you try to make printOptions() and battle() situated in a specific spot in the screen?
//for some reason theres errors when playing in enemy even tho it didn't happen at school

bool Game::m_gameOver = false;
Scene** Game::m_scenes = new Scene*;
int Game::m_sceneCount = 0;
int Game::m_currentSceneIndex = 0;

//characters
Enemy* enemy = new Enemy();
Player* player = new Player();
int enemyHealth = 100;
int playerAttack = 10;

Game::Game()
{
	m_gameOver = false;
	m_scenes = new Scene*;
	m_camera = new Camera2D();
	m_currentSceneIndex = 0;
	m_sceneCount = 0;
}

int Game::printOptions(const char* context, const char* option1, const char* option2)
{

	int input = -1;

	//Loops until the player selects an existing option
	while (input != 1 && input != 2)
	{
		//Prints the header and options for the menu.
		std::cout << context << std::endl;
		std::cout << "1. " << option1 << std::endl;
		std::cout << "> ";

		//Gets player input.
		std::cin >> input;

		//Checks if the player entered an acceptable input.
		if (input != 1)
		{
			//If the player did not input something valid, print an error and clear the screen.
			std::cout << "Invalid Input. Try Again";
			system("pause");
			system("cls");
		}
	}

	//Return the player's choice.
	return input;
}

void Game::start()
{
	int screenWidth = 1024;
	int screenHeight = 760;
	Scene* scene1 = new Scene();
	

	addScene(scene1);

	scene1->addActor(player);
	scene1->addActor(enemy);

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	m_camera->offset = { (float)screenWidth / 2, (float)screenHeight / 2 };
	m_camera->target = { (float)screenWidth / 2, (float)screenHeight / 2 };
	m_camera->zoom = 1;

	SetTargetFPS(60);

	
	enemy->Actor::setWorldPostion(MathLibrary::Vector2(15, 15));
	player->Actor::setWorldPostion(MathLibrary::Vector2(2, 3));
}


void Game::update(float deltaTime)
{
	player->Actor::checkCollision(enemy);
	for (int i = 0; i < m_sceneCount; i++)
	{
		m_scenes[i]->update(deltaTime);
	}
	
}

//this will hopefully allow player to attack enemy, granted from anywhere
void Game::battle()
{
	while (enemyHealth > 0)
	{
		//Gets player action
		int choice = printOptions("Your Turn", "Attack", "Run");

		//If action select was attack, have the player attack the enemy. Otherwise, return that the player escaped.
		if (choice == 1)
		{
			std::cout << "You did: " << playerAttack << " damage!" << std::endl;
			enemyHealth -= playerAttack;
			//maybe make it where the screen turns red when attacking but goes back to black
		}
			
		else
			break;
	}
	setGameOver(true);
}

void Game::draw()
{
	BeginDrawing();

	BeginMode2D(*m_camera);
	ClearBackground(RAYWHITE);

	for (int i = 0; i < m_sceneCount; i++)
	{
		m_scenes[i]->draw();
	}

	EndMode2D();
	EndDrawing();
}

void Game::end()
{
	CloseWindow();
}


MathLibrary::Matrix3* Game::getWorld()
{
	return getCurrentScene()->getWorld();
}

void Game::run()
{
	start();

	while (!m_gameOver && !RAYLIB_H::WindowShouldClose())
	{
		float deltaTime = RAYLIB_H::GetFrameTime();
		update(deltaTime);
		draw();
		battle();
	}

	end();
}

Scene* Game::getScene(int index)
{
	if (index < 0 || index >= m_sceneCount)
		return nullptr;

	return m_scenes[index];
}

Scene* Game::getCurrentScene()
{
	return m_scenes[m_currentSceneIndex];
}

int Game::getCurrentSceneIndex()
{
	return m_currentSceneIndex;
}

int Game::addScene(Scene* scene)
{
	//If the scene is null then return before running any other logic
	if (!scene)
		return -1;

	//Create a new temporary array that one size larger than the original
	Scene** tempArray = new Scene*[m_sceneCount + 1];

	//Copy values from old array into new array
	for (int i = 0; i < m_sceneCount; i++)
	{
		tempArray[i] = m_scenes[i];
	}

	//Store the current index
	int index = m_sceneCount;

	//Sets the scene at the new index to be the scene passed in
	tempArray[index] = scene;

	//Set the old array to the tmeporary array
	m_scenes = tempArray;
	m_sceneCount++;

	return index;
}

bool Game::removeScene(Scene* scene)
{
	//If the scene is null then return before running any other logic
	if (!scene)
		return false;

	bool sceneRemoved = false;

	//Create a new temporary array that is one less than our original array
	Scene** tempArray = new Scene*[m_sceneCount];

	//Copy all scenes except the scene we don't want into the new array
	int j = 0;
	for (int i = 0; i < m_sceneCount; i++)
	{
		if (tempArray[i] != scene)
		{
			tempArray[j] = m_scenes[i];
			j++;
		}
		else
		{
			sceneRemoved = true;
		}
	}

	//If the scene was successfully removed set the old array to be the new array
	if (sceneRemoved)
	{
		m_scenes = tempArray;
		m_sceneCount--;
	}
		

	return sceneRemoved;
}

void Game::setCurrentScene(int index)
{
	//If the index is not within the range of the the array return
	if (index < 0 || index >= m_sceneCount)
		return;

	//Call end for the previous scene before changing to the new one
	if (m_scenes[m_currentSceneIndex]->getStarted())
		m_scenes[m_currentSceneIndex]->end();

	//Update the current scene index
	m_currentSceneIndex = index;
}

bool Game::getKeyDown(int key)
{
	return RAYLIB_H::IsKeyDown((KeyboardKey)key);
}

bool Game::getKeyPressed(int key)
{
	return RAYLIB_H::IsKeyPressed((KeyboardKey)key);
}

void Game::destroy(Actor* actor)
{
	getCurrentScene()->removeActor(actor);
	if (actor->getParent())
		actor->getParent()->removeChild(actor);
	actor->end();
	delete actor;
}

void Game::setGameOver(bool value)
{
	Game::m_gameOver = value;
}

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <memory>
#include <vector>
#include "Wall.h"
#include "Empty.h"
#include "Door.h"
#include "Bomb.h"
#include "Rock.h"
#include "Board.h"
#include "Robot.h"
#include "Bonus.h"
#include "DumbGuard.h"
#include "SmartGuard.h"


class GameConsole
{
public:	GameConsole();
	void run();
	int getLives();
	void reduceLives();
	void reduceBombs();
	void setFreeze(bool freez);
	void setAccelerate(bool acce);
	void handleRobotStatus();
	void increaseLives();
	

private:


	void draw(sf::RenderWindow& window);
	void move(sf::RenderWindow& window, float& time);
	void MapCollisionCheck();
	void EntitiesCollisionCheck();
	void createBoard(Board & board);
	void levelUp();
	void upAllTimers(float time);
	void clearAll();
	void getBoard();
	void cleanAll();
	void cleanMap();
	void BombCollisionCheck();
	void cleanBombs();
	void cleanGuards();
	void initialFreeze();
	void initialAcceleration();


	int m_level = 1;
	int m_lives = ROBOT_LIVES;
	int m_row;
	int m_column;
	int m_gameTimer = 0;
	int m_numOfGuards = 0;
	int m_score = 0;

	size_t  m_bombLimit;
	size_t  m_timeLimit;


	std::vector<std::unique_ptr <Static>> m_map;
	std::vector<std::unique_ptr <Bomb>> m_bombs; 
	std::vector<std::unique_ptr <Entities>> m_entities;

	std::unique_ptr <Robot> m_robot;

	sf::RenderWindow m_window;
	sf::Clock m_clock;

	bool m_gameOver = false;
	bool m_freeze = false;
	bool m_accelerate = false; 
	bool m_sameLevel = false;

	float m_freezeTimer = 0;
	float m_accelerateTimer = 0;
	

};
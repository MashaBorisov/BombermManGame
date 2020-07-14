#include "Robot.h"
#include "Static.h"
#include "Wall.h"
#include "Rock.h"
#include "Door.h"
#include "DumbGuard.h"
#include "SmartGuard.h"
#include "Empty.h"
#include "Bomb.h"
#include "Bonus.h"




Robot::Robot(int xLoc, int yLoc, GameConsole & console) : Entities(xLoc, yLoc) , m_console{console}

{
	m_sprite.setTexture(*(ResurceManager::getInstance()->getTexture("robot")));

	m_sprite.setTextureRect(sf::IntRect(0, 0, IMAGE_SIZE, IMAGE_SIZE));
}



sf::Vector2f Robot::getStep(const sf::Window& window, const float& time, sf::Vector2f position)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{ 
		m_console.reduceBombs();
		m_bomb = true;
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setDirection(UP);
		return{ 0, -time* m_speed*m_factor };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setDirection(DOWN);
		return{ 0, time*m_speed *m_factor };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		setDirection(LEFT);
		return { -time* m_speed *m_factor, 0 };
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		setDirection(RIGHT);
		return{ time*m_speed *m_factor, 0 };
	}
	return { 0,0 };
}

void Robot::handleCollision(Static & s)
{
	return s.handleCollision(*this);
}

void Robot::handleCollision(Rock & r)
{
	wrongMove();
}

void Robot::handleCollision(Wall & w)
{
	wrongMove();
}

void Robot::handleCollision(Door & d)
{
	
		m_levelUp = true;

}

void Robot::handleCollision(Empty & em)
{
	return;
}

void Robot::handleCollision(Entities & en)
{
	return en.handleCollision(*this);
}

void Robot::handleCollision(Robot & r)
{
	return ;
}

void Robot::handleCollision(DumbGuard & dg)
{
	    m_console.reduceLives();
		m_isHurt = true;
		return;

}

void Robot:: handleCollision(SmartGuard & sg)
{
	    m_console.reduceLives();
		m_isHurt = true;
		return ;

}

void Robot::handleCollision(Bomb & b)
{
	if (b.getTimer() < 4000)
	
		return ;
	
	
	for (int i = 0; i < 5; i++)
		
		if (b.getExplosion(i).getGlobalBounds().intersects(this->getSprite().getGlobalBounds()))
		{
			m_console.reduceLives();
			setHurt(true);
		}
		
		
	
	return;
}

void Robot::handleCollision(Bonus & bo)
{

	bo.setHurt(true);

	int n = bo.getRandom() % 3;

	switch (n)
	{

	case 0: //case1:faster robot
		getConsole().setAccelerate(true);
			
		break;

	case 1:  //case2: freeze guards
		getConsole().setFreeze(true);
		
		break;

	case 2:  //case3: raise life
		getConsole().increaseLives();
			
		break;

	}


	return;
	

}


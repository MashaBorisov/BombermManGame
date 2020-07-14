#include "Bomb.h"
#include "Entities.h"
#include "Robot.h"
#include "DumbGuard.h"
#include "SmartGuard.h"
#include "Static.h"
#include "Wall.h"
#include "Empty.h"
#include "Rock.h"
#include "Bonus.h"
#include "Door.h"



Bonus::Bonus(int xLoc, int yLoc) : Static(xLoc, yLoc)

{

	m_sprite.setTextureRect(sf::IntRect(3*IMAGE_SIZE,0, IMAGE_SIZE, IMAGE_SIZE));
	m_sprite.setScale(0.9,0.9);

}


void Bonus::handleCollision(Entities & e)
{
	return e.handleCollision(*this);
}

void Bonus::handleCollision(Robot & r)
{
	setHurt(true);

	int n = getRandom() % 3;

	switch (n)
	{

	case 0: //case1:faster robot
		r.getConsole().setAccelerate(true);

		break;

	case 1:  //case2: freeze guards
		r.getConsole().setFreeze(true);

		break;

	case 2:  //case3: raise life
		r.getConsole().increaseLives();

		break;

	
		
		



	}


	return;

}

void Bonus::handleCollision(DumbGuard & dg)
{

	return;
}


void Bonus::handleCollision(SmartGuard & sg)
{

	return;
}

void Bonus::handleCollision(Static & s)
{
	return s.handleCollision(*this);
}

void Bonus::handleCollision(Rock & r)
{

	return;
}

void Bonus::handleCollision(Wall & w)
{

	return;
}

void Bonus::handleCollision(Door & d)
{

	return;
}

void Bonus::handleCollision(Empty & em)
{
	return;
}

void Bonus::handleCollision(Bomb & b)
{
	return;
}

void Bonus::handleCollision(Bonus & bo)
{
	return;
}
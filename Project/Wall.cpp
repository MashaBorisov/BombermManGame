#include "Wall.h"
#include "Entities.h"
#include "Robot.h"
#include "DumbGuard.h"
#include "SmartGuard.h"
#include "Static.h"
#include "Empty.h"
#include "Rock.h"
#include "Bomb.h"
#include "Door.h"
#include "Bonus.h"



Wall::Wall(int xLoc, int yLoc) : Static(xLoc, yLoc)

{

	m_sprite.setTextureRect(sf::IntRect(0, 0, IMAGE_SIZE, IMAGE_SIZE));

}

void Wall::handleCollision(Entities & e)
{
	return e.handleCollision(*this);
}

void Wall::handleCollision(Robot & r)

{
	r.wrongMove();

}

void Wall::handleCollision(DumbGuard & dg)
{
	dg.wrongMove();
}

void Wall::handleCollision(SmartGuard & sg)
{
	sg.wrongMove();
}


void Wall::handleCollision(Static & s)
{
	return s.handleCollision(*this);
}

void Wall::handleCollision(Rock & r)
{
	
	return ;
}

void Wall::handleCollision(Wall & w)
{
	return ;
}

void Wall::handleCollision(Door & d)
{
	
	return ;
}

void Wall::handleCollision(Empty & em)
{
	return;
}

void Wall::handleCollision(Bomb & b)
{
	return ;
}

void Wall::handleCollision(Bonus & bo)
{
	return;
}
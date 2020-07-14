#include "Door.h"
#include "Entities.h"
#include "Robot.h"
#include "DumbGuard.h"
#include "SmartGuard.h"
#include "Wall.h"
#include "Empty.h"
#include "Rock.h"
#include "Bomb.h"
#include "Static.h"
#include "Bonus.h"


Door::Door(int xLoc , int yLoc) : Static (xLoc,  yLoc)

{
	
	m_sprite.setTextureRect(sf::IntRect(0, IMAGE_SIZE, IMAGE_SIZE, IMAGE_SIZE));
}


void Door::handleCollision(Entities & e)
{
	return e.handleCollision(*this);
}

void Door::handleCollision(Robot & r)
{
	if (this->getSprite().getGlobalBounds().intersects(r.getSprite().getGlobalBounds()))
	   
		r.setLevel(true);
		
	
	return ;
}

void Door::handleCollision(DumbGuard & dg)
{

	return ;
}

void Door::handleCollision(SmartGuard & sg)
{
	
	return ;
}

void Door::handleCollision(Static & s)
{
	return s.handleCollision(*this);
}

void Door::handleCollision(Rock & r)
{

	return ;
}

void Door::handleCollision(Wall & w)
{
	
	return ;
}

void Door::handleCollision(Door & d)
{

	return;
}

void Door::handleCollision(Empty & em)
{
	return ;
}

void Door::handleCollision(Bomb & b)
{
	return;
}

void Door::handleCollision(Bonus & bo)
{
	return;
}


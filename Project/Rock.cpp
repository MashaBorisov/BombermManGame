#include "Rock.h"
#include "Entities.h"
#include "Robot.h"
#include "DumbGuard.h"
#include "SmartGuard.h"
#include "Wall.h"
#include "Empty.h"
#include "Static.h"
#include "Bomb.h"
#include "Door.h"
#include "Bonus.h"


Rock::Rock(int xLoc, int yLoc) : Static(xLoc, yLoc)

{

	m_sprite.setTextureRect(sf::IntRect(IMAGE_SIZE, 0, IMAGE_SIZE, IMAGE_SIZE));
}

void Rock::handleCollision(Entities & e)
{
	return e.handleCollision(*this);
}

void Rock::handleCollision(Robot & r)
{
	
	r.wrongMove();
}

void Rock::handleCollision(DumbGuard & dg)
{
	dg.wrongMove();

}

void Rock::handleCollision(SmartGuard & sg)
{
	sg.wrongMove();
}

void Rock::handleCollision(Static & s)
{
	return s.handleCollision(*this);
}

void Rock::handleCollision(Rock & r)
{
	return;
}

void Rock::handleCollision(Wall & w)
{
	return;
}

void Rock::handleCollision(Door & d)
{
	
	return;
}

void Rock::handleCollision(Empty & em)
{
	return ;
}

void Rock::handleCollision(Bomb & b)
{
	if (!b.getActivate())
	
		return ;

	
	for (int i = 0; i < 5; i++)
		
			if (b.getExplosion(i).getGlobalBounds().intersects(getSprite().getGlobalBounds()))
			
				setHurt(true);
		
			
		
	
	return;
}

void Rock::handleCollision(Bonus & em)
{
	return;
}



#include "SmartGuard.h"
#include "Robot.h"
#include "Static.h"
#include "Wall.h"
#include "Rock.h"
#include "Door.h"
#include "DumbGuard.h"
#include "Bomb.h"
#include "Bonus.h"


DumbGuard::DumbGuard(int xLoc, int yLoc) :Entities(xLoc, yLoc)
{
	m_sprite.setTexture(*(ResurceManager::getInstance()->getTexture("dumbGuard")));

	m_sprite.setTextureRect(sf::IntRect(0, 0, IMAGE_SIZE, IMAGE_SIZE));

	setDirection(RIGHT);
}


sf::Vector2f DumbGuard::getStep(const sf::Window& window, const float& time, sf::Vector2f position)
{

	switch (m_direction)
	{
	case UP:
		return { 0, m_speed * time };
		break;

	case DOWN:
		return { 0,-m_speed*time };
		break;

	case LEFT:
		return { -m_speed * time,0 };
		break;

	case RIGHT:
		return { m_speed * time,0 };
		break;

	default:
		break;
	}
	return { 0,0 };
}


void DumbGuard::handleCollision(Static & s)
{
	return s.handleCollision(*this);
}

void DumbGuard::handleCollision(Rock & r)

{
	wrongMove();
	return;
}

void DumbGuard::handleCollision(Wall & w)
{
	wrongMove();
	return;
}

void DumbGuard::handleCollision(Door & d)
{
	wrongMove();
	return;
}

void DumbGuard::handleCollision(Empty & em)
{
	return ;
}

void DumbGuard::handleCollision(Bonus & bo)
{
	return;
}


void DumbGuard::handleCollision(Entities & en)
{
	return en.handleCollision(*this);
}

void DumbGuard::handleCollision(Robot & r)
{
	if (this->getSprite().getGlobalBounds().intersects(r.getSprite().getGlobalBounds()))
	{
		r.setHurt(true);
		r.getConsole().reduceLives();
	}
  return; ;
	

}

void DumbGuard::handleCollision(DumbGuard & dg)
{
	return ;
}

void DumbGuard::handleCollision(SmartGuard & sg)
{

	return;
}


void DumbGuard::handleCollision(Bomb & b)
{
	if (b.getTimer() < 4000)
	
		return;
	
	
	for (int i = 0; i < 5; i++)
		
	if (b.getExplosion(i).getGlobalBounds().intersects(this->getSprite().getGlobalBounds()))
			
				setHurt(true);

	return;
			
		
	

}




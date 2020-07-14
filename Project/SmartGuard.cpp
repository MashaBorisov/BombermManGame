#include "SmartGuard.h"
#include "Robot.h"
#include "Static.h"
#include "Wall.h"
#include "Rock.h"
#include "Door.h"
#include "DumbGuard.h"
#include "Bomb.h"
#include "Bonus.h"

SmartGuard::SmartGuard(int xLoc, int yLoc) :Entities(xLoc, yLoc)
{
	m_sprite.setTexture(*(ResurceManager::getInstance()->getTexture("smartGuard")));

	m_sprite.setTextureRect(sf::IntRect(0, 0, IMAGE_SIZE, IMAGE_SIZE));

	setDirection(LEFT);
}

sf::Vector2f SmartGuard::getStep(const sf::Window& window, const float& time, sf::Vector2f position)
{
	sf::Vector2f m_location;
	m_location = m_sprite.getPosition();

	srand(std::time(NULL));

	int derection = (rand() % 2);  // check if x or y


	if (derection == 0)
	{

		if (m_location.x >= position.x)
		{
			setDirection(LEFT);
			return { -m_speed * time,0 };
		}
		setDirection(RIGHT);
		return { m_speed * time,0 };
	}
	if (derection == 1)

	{
		if (m_location.y >= position.y)
		{
			setDirection(UP);
			return { 0,-m_speed * time };
		}
		setDirection(DOWN);
		return { 0, m_speed * time };
	}
	return { 0,0 };
}

void SmartGuard::handleCollision(Static & s)
{
	return s.handleCollision(*this);
}

void SmartGuard::handleCollision(Rock & r)
{
	wrongMove();

}

void SmartGuard::handleCollision(Wall & w)
{
	wrongMove();
}

void SmartGuard::handleCollision(Door & d)
{
	wrongMove();
}

void SmartGuard::handleCollision(Empty & em)
{
	return ;
}

void SmartGuard::handleCollision(Entities & en)
{
	return en.handleCollision(*this);
}

void SmartGuard::handleCollision(Robot & r)
{
	r.getConsole().reduceLives();
		r.setHurt(true);
	
		return;
}

void SmartGuard::handleCollision(DumbGuard & dg)
{
	return ;
}

void SmartGuard::handleCollision(SmartGuard & sg)
{
	
	return;
}

void SmartGuard::handleCollision(Bomb & b)
{
	if (b.getTimer() < 4000)
	
		return;
	
	
	
	for (int i = 0; i < 5; i++)
		
		if (b.getExplosion(i).getGlobalBounds().intersects(getSprite().getGlobalBounds()))
			
				setHurt(true);
				return ;
			
		
}

void SmartGuard::handleCollision(Bonus & bo)
{
	return;

}

	

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



Bomb::Bomb(int xLoc, int yLoc , sf::Sprite sprite) : Static(xLoc, yLoc)

{
	m_sprite.setPosition(sprite.getPosition());
	m_sprite.setTextureRect(sf::IntRect(IMAGE_SIZE, IMAGE_SIZE, IMAGE_SIZE, IMAGE_SIZE));

	for (int i = 0; i < 5; i++)
	{
		m_explosion[i].setTexture(*(ResurceManager::getInstance()->getTexture("board")));
		m_explosion[i].setTextureRect(sf::IntRect(64, IMAGE_SIZE, IMAGE_SIZE, IMAGE_SIZE));
	}
	
	setExplosion(sprite);
}

void Bomb::handleCollision(Entities & e)
{
	return e.handleCollision(*this);
}



void Bomb::handleCollision(Bonus & bo)
{
	return;
}

void Bomb::handleCollision(Robot & r)
{
	if (m_timer < 4000)
	
		return;
	
	
	
	for (int i = 0; i < 5; i++)
	
		if (m_explosion[i].getGlobalBounds().intersects(r.getSprite().getGlobalBounds()))
		{
			r.setHurt(true);
			r.getConsole().reduceLives();
		}
			
	
	
	return;
	
}

void Bomb::handleCollision(DumbGuard & dg)
{
	if (m_timer < 4000)
		return;
	
	for (int i = 0; i < 5; i++)
		if (m_explosion[i].getGlobalBounds().intersects(dg.getSprite().getGlobalBounds()))
			
				dg.setHurt(true);
	return;
			
		
	
}

void Bomb::handleCollision(SmartGuard & sg)
{
	if (m_timer < 4000)
	
	return;

	for (int i = 0; i < 5; i++)
		
			if (m_explosion[i].getGlobalBounds().intersects(sg.getSprite().getGlobalBounds()))
			
				sg.setHurt(true);
	return;
			
		
}



void Bomb::handleCollision(Static & s)
{
	return s.handleCollision(*this);
}

void Bomb::handleCollision(Rock & r)
{
	if (!m_activate)
	
	return ;
	
	for (int i = 0; i < 5; i++)
		
		if (m_explosion[i].getGlobalBounds().intersects(r.getSprite().getGlobalBounds()))
		    r.setHurt(true);

			
	return;
}

void Bomb::handleCollision(Wall & w)
{
	
	return ;
}

void Bomb::handleCollision(Door & d)
{

	return;
}

void Bomb::handleCollision(Empty & em)
{
	return ;
}

void Bomb::handleCollision(Bomb & em)
{
	return ;
}

void Bomb::setExplosion(sf::Sprite sprite)
{

	sf::Vector2f temp = sprite.getPosition();

	m_explosion[0].setPosition(temp);
	m_explosion[1].setPosition({ temp.x , temp.y + IMAGE_SIZE });
	m_explosion[2].setPosition({ temp.x , temp.y - IMAGE_SIZE });
	m_explosion[3].setPosition({ temp.x - IMAGE_SIZE, temp.y });
	m_explosion[4].setPosition({ temp.x + IMAGE_SIZE, temp.y });
}

void Bomb::draw(sf::RenderWindow& window)
{
	if (m_timer < 4000)
	{

		window.draw(m_sprite);
		
	}
	else
	{
		m_activate = true; 
		for (int i = 0; i < 5; i++)
		{
			window.draw(m_explosion[i]);
		}
	}
}

void Bomb::raiseTimer(float time)
{
	m_timer += time;
}

void Bomb::updateTimer()
{
	m_timer = 0;
}
bool Bomb::isKill()
{
	if (m_timer > 6000)
		return true;
	return false;

}



#include "Entities.h"



Entities::Entities(int xLoc, int yLoc) : Shape(xLoc, yLoc),m_direction(0)
{
	m_sprite.setScale(0.9, 0.9);
}



void Entities::reframe(const float& factor)
{
	m_currentFrame += factor* REFRAME_SPEED;

	if (m_currentFrame > MAX_FRAMES)
		m_currentFrame -= MAX_FRAMES;

	switch (m_direction)
	{
	case UP:
		m_sprite.setTextureRect(sf::IntRect(IMAGE_SIZE*int(m_currentFrame), IMAGE_SIZE * 3, IMAGE_SIZE, IMAGE_SIZE));
		break;
	case DOWN:
		m_sprite.setTextureRect(sf::IntRect(IMAGE_SIZE * int(m_currentFrame), 0, IMAGE_SIZE, IMAGE_SIZE));
		break;
	case LEFT:
		m_sprite.setTextureRect(sf::IntRect(IMAGE_SIZE * int(m_currentFrame), IMAGE_SIZE, IMAGE_SIZE, IMAGE_SIZE));
		break;
	case RIGHT:
		m_sprite.setTextureRect(sf::IntRect(IMAGE_SIZE * int(m_currentFrame), IMAGE_SIZE * 2, IMAGE_SIZE, IMAGE_SIZE));
		break;

	default:
		break;
	}

}


void Entities::move(sf::Vector2f step)
{
	m_sprite.move(m_speed*step.x, m_speed*step.y);
}

void Entities::setDirection(int dir)
{
	m_direction = dir;
}

int Entities::getDirection()
{
	return m_direction;
}

void Entities::changeDirection()
{

	switch (m_direction)
	{
	case UP:
		m_direction = DOWN;
		break;
	case DOWN:
		m_direction = UP;
		break;
	case LEFT:
		m_direction = RIGHT;
		break;
	case RIGHT:
		m_direction = LEFT;
		break;
	default:
		break;
		
	}
}
void Entities::wrongMove()
{
	this->move(-this->getMyStep());
	this->changeDirection();
}
#include "Shape.h"



Shape::Shape(int xLoc, int yLoc):m_initialLocationX(xLoc), m_initialLocationY(yLoc)
{
	m_sprite.setPosition(xLoc * IMAGE_SIZE, yLoc * IMAGE_SIZE);

}
sf::Sprite Shape::getSprite()
{
	return m_sprite;
}

void Shape::setSprite(sf::Sprite other)
{
	m_sprite.setPosition(other.getPosition());
}


void Shape::initialPlace()
{
	m_sprite.setPosition(m_initialLocationX * IMAGE_SIZE, m_initialLocationY * IMAGE_SIZE);
}

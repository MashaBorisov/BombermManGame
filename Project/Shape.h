#pragma once
#include <SFML\Graphics.hpp>
#include "ResurceManager.h"

#include "Marcos.h"

class Shape
{
public:
	
	Shape(int xLoc, int yLoc);
	sf::Sprite getSprite();
	void setSprite(sf::Sprite other);
	void initialPlace();
	

protected:
	sf::Sprite m_sprite;
	int m_initialLocationX;
	int m_initialLocationY;
};


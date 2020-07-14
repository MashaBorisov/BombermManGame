#include "Empty.h"
#include "Entities.h"



Empty::Empty(int xLoc, int yLoc) : Static(xLoc, yLoc)

{
	m_sprite.setTextureRect(sf::IntRect(IMAGE_SIZE*2, 0, IMAGE_SIZE, IMAGE_SIZE));
}

void Empty::handleCollision(Entities & e)
{
	return e.handleCollision(*this);
}

void Empty::handleCollision(Robot & r)
{

	return;
}

void Empty::handleCollision(DumbGuard & dg)
{

	return;
}

void Empty::handleCollision(SmartGuard & sg)
{

	return;
}

void Empty::handleCollision(Static & s)
{
	return ;
}

void Empty::handleCollision(Rock & r)
{

	return ;
}

void Empty::handleCollision(Wall & w)
{

	return ;
}

void Empty::handleCollision(Door & d)
{

	return ;
}

void Empty::handleCollision(Empty & em)
{
	return ;
}

void Empty::handleCollision(Bomb & b)
{
	return;
}

void Empty::handleCollision(Bonus & bo)
{
	return;
}


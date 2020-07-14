#include "Static.h"



Static::Static(int xLoc, int yLoc) : Shape(xLoc, yLoc)
{
	m_sprite.setTexture(*(ResurceManager::getInstance()->getTexture("board")));
}


int Static::getRandom()
{
	static int last = 0;
	srand(time(NULL) + last);
	last = rand();
	return last;
}


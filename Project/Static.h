#pragma once
#include "Shape.h"
class Entities;
class Robot;
class DumbGuard;
class SmartGuard;
class Bomb;
class Rock;
class Wall;
class Door;
class Empty;
class Bonus;

class Static : public Shape

{
public:
	Static(int xLoc, int yLoc);

	virtual void handleCollision(Entities & e )=0;

	virtual void handleCollision(Robot & r ) = 0;

	virtual void handleCollision(DumbGuard & dg) = 0;

	virtual void handleCollision(SmartGuard & sg) = 0;

	virtual void handleCollision(Bomb & b) = 0;

	virtual void handleCollision(Static & s) = 0;

	virtual void handleCollision(Rock & r) = 0;

	virtual void handleCollision(Wall & w) = 0;

	virtual void handleCollision(Door & d) = 0;

	virtual void handleCollision(Empty & em) = 0 ;

	virtual void handleCollision(Bonus & bo) = 0;

	

	bool getHurt() { return m_isHurt; };

	void setHurt(bool hurt) { m_isHurt = hurt; };

	int getRandom();
private:

    bool m_isHurt = false;

};


#pragma once
#include "Shape.h"
class Static;
class Rock;
class Wall;
class Door;
class Empty;
class Robot;
class DumbGuard;
class SmartGuard;
class Bomb;
class Bonus;
class Bullet;

class Entities : public Shape
{
public:

	virtual void handleCollision(Static & s) = 0;
	virtual void handleCollision(Rock & r) = 0;
	virtual void handleCollision(Wall & w) = 0;
	virtual void handleCollision(Door & d) = 0;
	virtual void handleCollision(Empty & em) = 0;
	virtual void handleCollision(Entities & e) = 0;
	virtual void handleCollision(Robot & r) = 0;
	virtual void handleCollision(DumbGuard & dg) = 0;
	virtual void handleCollision(SmartGuard & sg) = 0;
	virtual void handleCollision(Bomb & b) = 0;
	virtual void handleCollision(Bonus & bo) = 0;
	


	Entities(int xLoc, int yLoc);
	void wrongMove();
	void reframe(const float& factor);
	void move(sf::Vector2f step);
	void setDirection(int dir);
	int getDirection();
	void changeDirection();
	virtual sf::Vector2f getStep(const sf::Window& window, const float& time , sf::Vector2f position) = 0;
	void setStep(sf::Vector2f step) { m_step = step; };
	sf::Vector2f getMyStep() { return m_step; };
	bool getHurt() { return m_isHurt; };
	void setHurt(bool hurt) { m_isHurt = hurt; };
	void setFactor(int factor) { m_factor = factor; };

protected:
	int m_direction;
	float m_speed = ROBOT_SPEED;
	float m_currentFrame=0;
    sf::Vector2f m_step;
	bool m_isHurt = false;
	int m_factor = 1;
	
};


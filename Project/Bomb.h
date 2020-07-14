#pragma once
#include "Static.h"

class Bomb :public Static
{
public:
	Bomb(int xLoc, int yLoc , sf::Sprite sprite);
	
	void handleCollision(Entities & e) override;
	void handleCollision(Robot & r) override;
	void handleCollision(DumbGuard & dg) override;
	void handleCollision(SmartGuard & sg) override;
	void handleCollision(Static & s) override; 
	void handleCollision(Rock & r) override ;
	void handleCollision(Wall & w) override ;
	void handleCollision(Door & d) override ;
	void handleCollision(Empty & em) override;
	void handleCollision(Bomb & b) override;
	void handleCollision(Bonus & bo) override;
	

	void draw(sf::RenderWindow& window);

	void raiseTimer(float time);

	void updateTimer();

	float getTimer() { return m_timer; };

	sf::Sprite getExplosion(int i) { return m_explosion[i]; };

	bool getActivate() { return m_activate; };

	void setActivate(bool status) { m_activate = status; };
	
	void setExplosion(sf::Sprite sprite);

	bool isKill();
private:

    sf::Sprite m_explosion[5];

	bool m_activate =  false;
  
	float m_timer = 0;
	


};


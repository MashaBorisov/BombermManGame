#pragma once
#include "Entities.h"
class SmartGuard :public Entities
{
public:
	SmartGuard(int xLoc, int yLoc);
	
	sf::Vector2f getStep(const sf::Window& window, const float& time, sf::Vector2f position);

	void handleCollision(Static & s)override;

	void handleCollision(Rock & r)override;

	void handleCollision(Wall & w)override;

	void handleCollision(Door & d)override;

	void handleCollision(Empty & em) override;

	void handleCollision(Entities & en)  override;

	void handleCollision(Robot & r) override;

	void handleCollision(DumbGuard & dg) override;

	void handleCollision(SmartGuard & sg) override;

	void handleCollision(Bomb & b) override;

	void handleCollision(Bonus & bo) override;

	
};


#pragma once
#include "Static.h"

class Wall : public Static
{
public:
	Wall(int xLoc, int yLoc);

	void handleCollision(Static & s) override;
	void handleCollision(Rock & r) override;
	void handleCollision(Wall & w) override;
	void handleCollision(Door & d) override;
	void handleCollision(Empty & em) override;
	void handleCollision(Entities & en)  override;
	void handleCollision(Robot & r) override;
	void handleCollision(DumbGuard & dg) override;
	void handleCollision(SmartGuard & sg) override;
	void handleCollision(Bomb & b) override;
	void handleCollision(Bonus & bo) override;
	
};



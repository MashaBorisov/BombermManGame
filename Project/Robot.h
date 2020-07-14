#pragma once
#include "Entities.h"
#include "GameConsole.h"

class GameConsole;

class Robot : public Entities
{
public:
	

	Robot(int xLoc, int yLoc , GameConsole& console);
	
	sf::Vector2f getStep(const sf::Window& window, const float& time, sf::Vector2f position);
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
	
	GameConsole& getConsole() { return  m_console; };
	bool getLevel() { return m_levelUp; };
	void setLevel(bool l) { m_levelUp = l; };
	bool getBomb() { return m_bomb; };
	void setBomb(bool b) { m_bomb = b; };
	
	
private: 
	GameConsole& m_console;
	bool m_levelUp = false; 
	bool m_bomb = false;
	
};


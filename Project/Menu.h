#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameConsole.h"

class Menu
{
public:
	Menu();
	void draw();
	void loadMenu();
	void run();
	~Menu();
private:
	sf::RenderWindow m_window;
	sf::Sprite m_background, m_buttonPlay, m_buttonExit;
};


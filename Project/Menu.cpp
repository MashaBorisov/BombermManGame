#include "Menu.h"



Menu::Menu()
	:m_window(sf::VideoMode(480, 360) ,  "Main menu")
{
	loadMenu();
}

Menu::~Menu()
{
}

void Menu::run()
{
	sf::Music music;
	music.openFromFile("mainMenu.ogg");
	music.setLoop(true);
	music.play();


	while (m_window.isOpen())
	{
		draw();
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{	m_window.close();
			break;
			}
			case sf::Event::MouseButtonPressed:
			{
				const auto coords = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				if (m_buttonExit.getGlobalBounds().contains(coords))
				{
					m_window.close();
					break;
				}
				if (m_buttonPlay.getGlobalBounds().contains(coords))
				{
					m_window.setVisible(false);
					music.stop();
					GameConsole console;
					console.run();
					m_window.setVisible(true);

					if (console.getLives() < 1)
					{
						music.openFromFile("LooseTheme.ogg");
						m_background.setTexture(*(ResurceManager::getInstance()->getTexture("mainLoose")));
					}
					else
					{
						music.openFromFile("mainMenu.ogg");
						m_background.setTexture(*(ResurceManager::getInstance()->getTexture("main")));
					}

					music.play();
					break;

				}
			}

			default:
				break;
			}
		}

	}
}

void Menu::draw()
{
	m_window.clear();
	m_window.draw(m_background);
	m_window.draw(m_buttonPlay);
	m_window.draw(m_buttonExit);
	m_window.display();
}

void Menu::loadMenu()
{
	m_background.setTexture(*(ResurceManager::getInstance()->getTexture("main")));
	m_buttonPlay.setTexture(*(ResurceManager::getInstance()->getTexture("play")));
	m_buttonExit.setTexture(*(ResurceManager::getInstance()->getTexture("exit")));
	m_buttonExit.setScale(EXIT_BUTTON_SCALE, EXIT_BUTTON_SCALE);
	m_buttonPlay.setScale(PLAY_BUTTON_SCALE, PLAY_BUTTON_SCALE);
	m_buttonPlay.setPosition(BUTTON_PLAY_POS_Y, BUTTON_POS_Y);
	m_buttonExit.setPosition(BUTTON_EXIT_POS_X, BUTTON_POS_Y);
}


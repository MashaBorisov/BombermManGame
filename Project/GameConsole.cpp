#include "GameConsole.h"
#include <experimental/vector>
#include <iostream>
#include <ctime>

GameConsole::GameConsole()
{
	getBoard();
}

void GameConsole::createBoard( Board & board)
{
	srand(std::time(NULL));

	for (int i = 0; i<board.getNumOfRows(); i++)
		for (int j = 0; j < board.getNumOfCols(); j++)
		{
			if (board.getCell(i, j) == ' ')
				m_map.push_back(std::make_unique<Empty>(j, i));

			if (board.getCell(i, j) == '#')
				m_map.push_back(std::make_unique<Wall>(j, i));

			if (board.getCell(i, j) == 'D')
				m_map.push_back(std::make_unique<Door>(j, i));

			if (board.getCell(i, j) == '@')
			{
				m_map.push_back(std::make_unique<Empty>(j, i));
				m_map.push_back(std::make_unique<Rock>(j, i));
			}
			if (board.getCell(i, j) == '&')
			{
				m_map.push_back(std::make_unique<Empty>(j, i));
				m_map.push_back(std::make_unique<Bonus>(j, i));
				m_map.push_back(std::make_unique<Rock>(j, i));
			}
			if (board.getCell(i, j) == '+')
			{
				m_map.push_back(std::make_unique<Empty>(j, i));
				m_map.push_back(std::make_unique<Bonus>(j, i));
			}

			if (board.getCell(i, j) == '!')
			{
				
				int n = rand() % 3;

				if (n == 0)
					m_entities.push_back(std::make_unique<SmartGuard>(j, i));
				else
					m_entities.push_back(std::make_unique<DumbGuard>(j, i));

				m_numOfGuards++;
				m_map.push_back(std::make_unique<Empty>(j, i));
			}
				

			if (board.getCell(i, j) == '/')
			{
			    auto temp =std::make_unique<Robot>(j, i, *this);
				m_robot=std::move(temp);
				m_map.push_back(std::make_unique<Empty>(j, i));
			}
		}
}

void GameConsole::run()
{
	m_window.setFramerateLimit(30);
	sf::Clock clock;


	sf::Music music;
	music.openFromFile("mainTheme.ogg");
	music.setLoop(true);
	music.play();

	sf::Font font;
	font.loadFromFile("gabriola.ttf");
	sf::Text text("", font, FONT_SIZE);

	while (m_window.isOpen())
	{
		handleRobotStatus();
		if (m_robot->getLevel())
		{
			m_score += SCORE_FOR_TOTAL_GUARDS * m_numOfGuards;
			m_level++;
			if (m_level > MAX_LEVEL)
				break;
			levelUp();
		}

		if (m_lives < 1)
			m_window.close();

		text.setPosition(0, m_row*IMAGE_SIZE);


		float time = clock.getElapsedTime().asMicroseconds();
		m_gameTimer = m_clock.getElapsedTime().asSeconds();



		if (m_gameTimer > m_timeLimit)
		{
			m_gameTimer = 0;
			m_robot->setHurt(true);
			handleRobotStatus();
		}


		text.setString("Lives: " + std::to_string(m_lives) + "  Time: " + std::to_string(m_timeLimit - m_gameTimer)
			+ "  Bomb: " + std::to_string(m_bombLimit) + "  Level: " + std::to_string(m_level) + "   Score: " + std::to_string(m_score));

			m_window.clear();
			clock.restart();
			time = time / SMOOTHING_VALUE;

			sf::Event event;
			while (m_window.pollEvent(event))
			{

				if (event.type == sf::Event::Closed)
					m_window.close();
			}
	

			move(m_window, time);
			MapCollisionCheck();
			EntitiesCollisionCheck();
			upAllTimers(time);
			BombCollisionCheck();
			draw(m_window);
			m_window.draw(text);
			cleanAll();
			m_window.display();
		}


	
}

void GameConsole::draw(sf::RenderWindow& window)
{
	for (auto const & map_ptr : m_map)
	{
		window.draw(map_ptr->getSprite());

	}
	for (auto const & en_ptr : m_entities)
	{
		window.draw(en_ptr->getSprite());

	}
	for (auto const & bomb_ptr : m_bombs)
	{
		bomb_ptr->draw(window);

	}
	
	window.draw(m_robot->getSprite());
}

void GameConsole::move(sf::RenderWindow& window, float& time)
{
	if (!m_freeze)
	{

		for (auto const & en_ptr : m_entities)
		{
			en_ptr->setStep(en_ptr->getStep(window, time, m_robot->getSprite().getPosition()));
			en_ptr->move(en_ptr->getMyStep());
			en_ptr->reframe(time);
		}
	}

	if (m_accelerate)
		m_robot->setFactor(2);

	m_robot->setStep(m_robot->getStep(window, time , m_robot->getSprite().getPosition()));

	if (m_robot->getBomb())
	{
		m_robot->setBomb(false);
		if (m_bombLimit > 0)
			m_bombs.push_back(std::make_unique<Bomb>(0, 0, m_robot->getSprite()));
	}

	m_robot->move(m_robot->getMyStep());
	m_robot->reframe(time);
}

void GameConsole::cleanGuards()
{

	std::experimental::erase_if(m_entities, [](std::unique_ptr<Entities>& c)
	{
		return c->getHurt();
	});

}

void GameConsole::cleanBombs()
{

	std::experimental::erase_if(m_bombs, [](std::unique_ptr<Bomb>& c)
	{
		return c->isKill();
	});

}

void GameConsole::cleanMap()
{
	
   std::experimental::erase_if(m_map, [](std::unique_ptr<Static>& c)

	{
		return c->getHurt();
	});

}

void GameConsole::EntitiesCollisionCheck()
{
	for (auto const & en_ptr : m_entities)
	{
		if (en_ptr->getSprite().getGlobalBounds().intersects(m_robot->getSprite().getGlobalBounds()))
		{

			en_ptr->handleCollision(*m_robot);
			if(m_robot->getHurt())
			{
				return;
			}
			
		}
	}
}

void GameConsole::BombCollisionCheck()
{
	
	for (auto const & bomb_ptr : m_bombs)
	{
		for (auto & en_ptr: m_entities)
				en_ptr->handleCollision(*bomb_ptr);
		

			m_robot->handleCollision(*bomb_ptr);
			

		for (auto  & map_ptr : m_map)
			map_ptr->handleCollision(*bomb_ptr);

	}
	for (auto & en_ptr : m_entities)
		if (en_ptr->getHurt())
			m_score += SCORE_FOR_BOMBING_GUARD;
}

void GameConsole::MapCollisionCheck()
{
	for (auto const & map_ptr : m_map)
	{
		
		for (auto const & en_ptr : m_entities)
			if (map_ptr->getSprite().getGlobalBounds().intersects(en_ptr->getSprite().getGlobalBounds()))
				en_ptr->handleCollision(*map_ptr);
		

		if (map_ptr->getSprite().getGlobalBounds().intersects(m_robot->getSprite().getGlobalBounds()))
			m_robot->handleCollision(*map_ptr);
		

	}
}

void GameConsole::levelUp()
{
	clearAll();
	getBoard();

}

void GameConsole::upAllTimers(float time)
{
	for (auto & bomb_ptr : m_bombs)
	     
		bomb_ptr->raiseTimer(time);
	
	if (m_accelerate)
		
		m_accelerateTimer += time;

	if (m_freeze)
		
		m_freezeTimer += time;

	initialAcceleration();

	initialFreeze();
	

}

void GameConsole::clearAll()
{
	m_map.clear();
	m_entities.clear();
	m_robot.reset();
	m_bombs.clear();
 }

void GameConsole::getBoard()
{
	Board board(m_level);
	if (!board.getGameStatus())
	{

		m_row = board.getNumOfRows();
		m_column = board.getNumOfCols();
		m_bombLimit = board.getBomb();
		m_timeLimit = board.getSteps();
		m_gameTimer = 0;
		m_numOfGuards = 0;
		m_clock.restart();
		if (m_timeLimit == 0)
			m_timeLimit = INF;
		if (m_bombLimit == 0)
			m_bombLimit = INF;
		m_window.create(sf::VideoMode(m_column*IMAGE_SIZE, m_row*IMAGE_SIZE + IMAGE_SIZE), "Bomberman");

		createBoard(board);
	}
	else
		m_gameOver = true;
}

void GameConsole::cleanAll()
{
	cleanBombs();
	cleanMap();
	cleanGuards();

}

int GameConsole::getLives()
{
	return m_lives;
}

void GameConsole::reduceLives()
{
	m_lives--;
}

void GameConsole::reduceBombs()
{
	m_bombLimit--;
}

void GameConsole::handleRobotStatus()
{
	if (m_robot->getHurt())
	{
		clearAll();
		Board board(m_level);
		createBoard(board);
		m_robot->setHurt(false);
		
	}
}

void GameConsole::setFreeze(bool freez)
{
	m_freeze = freez; 
}

void GameConsole::setAccelerate(bool acce)
{
	m_accelerate = acce; 
}

void GameConsole::initialFreeze()
{
	if (m_freezeTimer>4000)
	{
		m_freezeTimer = 0;
		m_freeze = false;
	}
}

void GameConsole::initialAcceleration()
{
	if (m_accelerateTimer>4000)
	{
		m_accelerateTimer = 0;
		m_accelerate = false;
		m_robot->setFactor(1);
	}
}

void GameConsole::increaseLives()
{
	m_lives++;
}


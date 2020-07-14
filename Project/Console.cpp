#include "Console.h"


Console::Console(const Board & board)
{
	creatBoard(board);
}

void Console::creatBoard(const Board & board)
{
	for (int i = 0; i<board.getSize(); i++)
		for (int j = 0; j < board.getSize(); j++)
		{
			if (board.getCell(i, j) == ' ')
				m_map.push_back(std::make_unique<Empty>(i, j));

			if (board.getCell(i, j) == '#')
				m_map.push_back(std::make_unique<Wall>(i, j));

			if (board.getCell(i, j) == 'D')
				m_map.push_back(std::make_unique<Door>(i, j));

			if (board.getCell(i, j) == '@')
				m_map.push_back(std::make_unique<Rock>(i, j));

		}
}


void Console::run()
{


	{

		std::ifstream  inputFile;

		inputFile.open("Board.txt");

		Board board(inputFile);

		creatBoard(board);
		sf::Window window(sf::VideoMode(800, 600), "SFML window");

		while (window.isOpen())
		{
			

			// Event processing
			sf::Event event;
			while (window.pollEvent(event))
			{
				for (auto map_ptr : m_map)
				{

				}

			

				if (event.type == sf::Event::Closed)
					window.close();
				
			}

			window.display();
		}


	}
}
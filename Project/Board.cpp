#include "Board.h"


Board::Board(int m_level)
{
	std::ifstream  inputFile;
	std::string fileName;
	fileName = "boards\\level" + std::to_string(m_level) + ".txt";
	inputFile.open(fileName);
	if (checkIfOpen(inputFile))
	{
		readFromFile(inputFile);

	}
	else
		m_gameOver = true;
}

void Board::readFromFile(std::ifstream &inputFile)
{


	

	inputFile >> m_numOfRows;
	inputFile >> m_numOfColumns;
	inputFile >> m_timeLimit;
	inputFile >> m_bombLimit;

	m_initiaTimeLimit = m_timeLimit;

	std::string line;

	getline(inputFile, line); // skip line;

	for (size_t i = 0; i < m_numOfRows; ++i)
	{

		getline(inputFile, line);

		m_board.push_back(line);

	}

	return;
}

char Board::getCell(int x, int y) const
{
	return m_board[x][y];
}

int Board::getNumOfRows() const
{
	return m_numOfRows;
}

int Board::getNumOfCols() const
{
	return m_numOfColumns;
}

size_t Board::getSteps() const
{
	return m_timeLimit;
}


size_t Board::getBomb() const
{
	return m_bombLimit;
}

void Board::reduceSteps()
{
	m_timeLimit--;
}

void Board::resetSteps()
{
	m_timeLimit = m_initiaTimeLimit;
}



bool Board::checkIfOpen(std::ifstream &inputFile)

{

	if (!inputFile.is_open())

	{
		m_gameOver = true;
		return false;
	}

	return true;

}

#pragma once

//--------------INCLUDE-------------------

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>     
#include <stdio.h>
#include <stdlib.h>

typedef std::vector<std::string> matrix;   //Board


class Board
{
public:
	Board() {};
	Board(int m_level);  // constructor

	char getCell(int x, int y) const;  // get cell

	int getNumOfRows() const;

	int getNumOfCols() const;

	void reduceSteps();  // reduce the number of steps

	size_t getSteps() const;  // get steps

	void resetSteps();  // give the initial num of steps

	void readFromFile(std::ifstream &inputFile); //read from file

	size_t getBomb() const; 

	bool getGameStatus() { return m_gameOver; };

private:

	  
	bool checkIfOpen(std::ifstream &inputFile);

	matrix m_board;   // our board

	size_t m_numOfRows,m_numOfColumns,m_timeLimit,m_bombLimit; 

	size_t m_initiaTimeLimit;

	bool m_gameOver = false;


};
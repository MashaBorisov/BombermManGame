#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Wall.h"
#include "Empty.h"
#include "Door.h"
#include "Rock.h"
#include "Board.h"

class Console
{
public:
	Console(const Board & board);
	void run();

private:
	void creatBoard(const Board & board);

	std::vector<std::unique_ptr <Static>> m_map; 
	//std::vector<std::unique_ptr <Entities>> m_guards;

};


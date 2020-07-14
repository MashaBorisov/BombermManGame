#include "ResurceManager.h"



ResurceManager::ResurceManager()
{
	loadTexture("robot.png", "robot");
	loadTexture("board.png", "board");
	loadTexture("smartGuard.png", "smartGuard");
	loadTexture("dumbGuard.png", "dumbGuard");
	loadTexture("main.png", "main");
	loadTexture("mainLoose.png", "mainLoose");
	loadTexture("play.png", "play");
	loadTexture("exit.png", "exit");
	
}

void ResurceManager::loadTexture(std::string path, std::string name)
{
	sf::Texture * temp = new sf::Texture();
	temp->loadFromFile(path);

	m_textures[name] = temp;

}

ResurceManager::~ResurceManager()
{
	
}

void ResurceManager::clean()
{
	for (auto index : m_textures)
	{
		delete index.second;
		index.second = nullptr;
	}
}

sf::Texture* ResurceManager::getTexture(std::string name)
{
	if (m_textures[name])
		return m_textures[name];

	return nullptr;
}

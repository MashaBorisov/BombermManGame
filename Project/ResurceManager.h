#pragma once
#include <SFML\Graphics.hpp>

class ResurceManager
{
public:
	static ResurceManager* getInstance()
	{
		static ResurceManager instance;
		return &instance;
	}

	void clean();

	
	~ResurceManager();
	sf::Texture * getTexture(std::string name);
private:
	ResurceManager();
	void loadTexture(std::string path, std::string name);

	std::map< std::string, sf::Texture * > m_textures;
};



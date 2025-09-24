#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{

	for (auto& pair : texturesMap)
	{
		delete pair.second;
	}

	for (auto& pair : fontsMap)
	{
		delete pair.second;
	}

	for (auto& pair : soundsMap)
	{
		delete pair.second;
	}
}

sf::Texture& ResourceManager::GetTexture(const std::string& path, bool useMipmap, sf::IntRect area)
{	
	auto iterator = texturesMap.find(path); 

	if (iterator == texturesMap.end())		
	{
		sf::Texture* texture = new sf::Texture();

		if (!texture->loadFromFile(path, useMipmap, area)) 
		{
			delete texture;
			throw std::runtime_error("No se pudo cargar textura: " + path);
		}

		
		iterator = texturesMap.emplace(path, texture).first;

	}

	return *iterator->second;	
}

sf::Font& ResourceManager::GetFont(const std::string& path)
{
	auto iterator = fontsMap.find(path);

	if (iterator == fontsMap.end())
	{
		sf::Font* font = new sf::Font();

		if (!font->openFromFile(path))
		{
			delete font;
			throw std::runtime_error("No se pudo cargar fuente: " + path);
		}

		iterator = fontsMap.emplace(path, font).first;
	}

	return *iterator->second;
}

sf::SoundBuffer& ResourceManager::getSound(const std::string& path)
{
	auto iterator = soundsMap.find(path);

	if (iterator == soundsMap.end())
	{
		sf::SoundBuffer* buffer = new sf::SoundBuffer();

		if (!buffer->loadFromFile(path))
		{
			delete buffer;
			throw std::runtime_error("No se pudo cargar sonido: " + path);
		}

		iterator = soundsMap.emplace(path, buffer).first;
	}

	return *iterator->second;
}

#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
class AssetManager
{
public:
	//Add a new asset to the assets list
	static void AddAsset(std::string _key, std::string _fileName);

	//Get an asset by its key
	static sf::Texture* GetAsset(std::string _key);

	static std::vector<sf::Texture*> GetAssetFrames(std::string _key, int framesPerRow, int numberOfRows, int frameWidth, int frameHeight, int rowNumber);
	static void AddAssetSegment(const std::string& key, const std::string& fileName, int row, int frameCount, int frameWidth, int frameHeight);

	//Get an asset by its key
	static void DeleteAsset(std::string _key);


private:
	static std::map<std::string, sf::Texture*> assets;

	std::vector<sf::Texture*> frames;
	size_t currentFrame = 0;
};


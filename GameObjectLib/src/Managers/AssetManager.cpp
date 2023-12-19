#include "Managers/AssetManager.h"

std::map<std::string, sf::Texture*> AssetManager::assets;

 void AssetManager::AddAsset(std::string _key, std::string _fileName)
{
	 sf::Texture* texture = new sf::Texture();
	if (AssetManager::assets.find(_key) == AssetManager::assets.end()) 
	{
		AssetManager::assets.insert(std::make_pair(_key, texture));
		if (!AssetManager::assets.at(_key)->loadFromFile(_fileName)) 
		{
			std::cout << "asset introuvable" << std::endl;
		}
	}
}

 sf::Texture* AssetManager::GetAsset(std::string _key)
 {
	 if (AssetManager::assets.find(_key) != AssetManager::assets.end()) 
	 {
		 return AssetManager::assets.at(_key);
	 }
	 return nullptr;
 }

 std::vector<sf::Texture*> AssetManager::GetAssetFrames(std::string _key, int framesPerRow, int numberOfRows, int frameWidth, int frameHeight, int rowNumber) {
	 std::vector<sf::Texture*> frameTextures;
	 sf::Texture* spriteSheet = GetAsset(_key);

	 if (spriteSheet && rowNumber < numberOfRows) {
		 for (int i = 0; i < framesPerRow; ++i) {
			 sf::Texture* frameTexture = new sf::Texture();
			 frameTexture->loadFromImage(spriteSheet->copyToImage(), sf::IntRect(i * frameWidth, rowNumber * frameHeight, frameWidth, frameHeight));
			 frameTextures.push_back(frameTexture);
		 }
	 }
	 return frameTextures;
 }
 void AssetManager::AddAssetSegment(const std::string& key, const std::string& fileName, int row, int frameCount, int frameWidth, int frameHeight) {
	 sf::Texture* texture = new sf::Texture();
	 if (AssetManager::assets.find(key) == AssetManager::assets.end()) {
		 if (texture->loadFromFile(fileName, sf::IntRect(0, row * frameHeight, frameWidth * frameCount, frameHeight))) {
			 AssetManager::assets[key] = texture;
		 }
		 else {
			 std::cout << "Segment asset not found: " << fileName << std::endl;
			 delete texture;
		 }
	 }
 }


void AssetManager::DeleteAsset(std::string _key)
 {
	 if (AssetManager::assets.find(_key) != AssetManager::assets.end())
	 {
		 delete AssetManager::assets.at(_key);
		 AssetManager::assets.erase(_key);
	 }

 }
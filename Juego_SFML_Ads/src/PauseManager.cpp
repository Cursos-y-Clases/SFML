#include "PauseManager.h"

PauseManager::PauseManager(ResourceManager& resources, sf::RenderWindow& window, Scene*& currentScene, MainMenu*& mainMenu) :
	currentScene (currentScene), mainMenu (mainMenu), window (window)
{
	this->currentScene = currentScene;
	this->mainMenu = mainMenu;

	std::string pauseBackgroundPath = "../textures/pause/pausebackground.png";
	sf::IntRect pauseBackgroundArea({ 0,0 }, { 1280, 720 });
	sf::Texture& pauseBackgroundTexture = resources.GetTexture(pauseBackgroundPath, false, pauseBackgroundArea);
	pauseBackground = new sf::Sprite(pauseBackgroundTexture);	
	pauseBackground->setPosition({ 1280 * 0.5f, 720 * 0.5f });

	std::string pauseButtonPath = "../textures/pause/pausebutton.png";
	sf::IntRect pauseButtonArea({ 0,0 }, { 249, 55 });
	sf::Texture& pauseButtonTexture = resources.GetTexture(pauseButtonPath, false, pauseButtonArea);
	continueButton = new sf::Sprite(pauseButtonTexture);
	continueButton->setPosition({ 1280 * 0.5f + 65, 720 * 0.5f + 30});
	mainMenuButton = new sf::Sprite(pauseButtonTexture);
	mainMenuButton->setPosition({ 1280 * 0.5f + 65, 720 * 0.5f + 120 });

	gamePaused = false;
}

PauseManager::~PauseManager(){}

void PauseManager::Input(){}

void PauseManager::Draw()
{
	if (!gamePaused) return;

	window.draw(*pauseBackground);
	window.draw(*continueButton);
	window.draw(*mainMenuButton);

}

void PauseManager::HandleEvents(const sf::Event& event)
{
	if (const auto* key = event.getIf<sf::Event::KeyPressed>()) {
		
		if (key->scancode == sf::Keyboard::Scancode::P) {
			
			if (gamePaused)
				UnpauseGame();
			else           
				PauseGame();
		}
	}

	if (!gamePaused) return;


	if (const auto* mouse = event.getIf<sf::Event::MouseButtonPressed>())  
	{
		if (mouse->button == sf::Mouse::Button::Left)	
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(window);   
			sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);   

			if (continueButton->getGlobalBounds().contains(worldPos))	
			{				
				UnpauseGame();
			}

			if (mainMenuButton->getGlobalBounds().contains(worldPos))
			{
				UnpauseGame();		
				currentScene = mainMenu;
			}

		}
	}
}


bool PauseManager::GetGamePaused()
{
	return gamePaused;
}

void PauseManager::PauseGame()
{
	gamePaused = true;
}

void PauseManager::UnpauseGame()
{
	gamePaused = false;
}

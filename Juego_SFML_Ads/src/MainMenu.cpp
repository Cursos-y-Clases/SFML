#include "MainMenu.h"

MainMenu::MainMenu(ResourceManager & resources, sf::RenderWindow & window)
	: Scene(window),
	text(resources.GetFont("../fonts/pixelart.ttf"), "COMENZAR", 48) {																	 
	std::string backgroundPath = "../textures/mainmenu/background.png";
	sf::IntRect backgroundArea({ 0, 0 }, { 1280, 720 });
		
	sf::Texture& backgroundTexture = resources.GetTexture(backgroundPath, false, backgroundArea);
	background = new sf::Sprite(backgroundTexture);


	std::string buttonPath = "../textures/mainmenu/button.png";
	sf::IntRect startButtonArea({ 0, 0 }, { 361,88 });

	sf::Texture& startButtonTexture = resources.GetTexture(buttonPath, false, startButtonArea);
	startButton = new sf::Sprite(startButtonTexture);

	startButton->setOrigin({ startButton->getTexture().getSize().x * 0.5f,
							startButton->getTexture().getSize().y * 0.5f });

	startButton->setPosition({ 1280 * 0.5f, 720 * 0.5f });

	std::string fontPath = "../fonts/pixelart.ttf";
	sf::Font& font = resources.GetFont(fontPath);

	buttonText = new sf::Text(font, "COMENZAR", 48);

	//buttonText->setFont(font);
	//buttonText->setString("COMENZAR");
	//buttonText->setCharacterSize(48);
	buttonText->setFillColor(sf::Color::Black);
	//buttonText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	buttonText->setPosition({ 1280 * 0.5f, 720 * 0.5f });
	buttonText->setOrigin(buttonText->getLocalBounds().getCenter());

	std::string musicPath = "../audio/music/retro_music.mp3";

	music.openFromFile(musicPath);

	music.setLooping(true);
	music.setVolume(50);
	music.play();

}

MainMenu::~MainMenu()
{
	delete buttonText;
	delete background;
	delete startButton;
}

void MainMenu::Input()
{

}

void MainMenu::Update(float deltaTime)
{
	if (wantsChange) return;

	if (music.getStatus() == sf::SoundSource::Status::Stopped)
		music.play();
}

void MainMenu::Draw()
{
	window.draw(*background);
	window.draw(*startButton);
	window.draw(*buttonText);
	//window->draw(text);
}

void MainMenu::HandleEvents(const sf::Event& event)
{
	if (const auto* mouse = event.getIf<sf::Event::MouseButtonPressed>())  //comprueba evento de click de mouse
	{
		if (mouse->button == sf::Mouse::Button::Left)	//comprueba si evento es de click izquierdo
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(window);   //obtiene la posición del mouse dentro de la ventana de SFML
			sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);   //convierte a coordenadas del mundo del juego la posición del mouse	

			if (startButton->getGlobalBounds().contains(worldPos))	//comprueba si el mouse esta sobre el boton tras haberse cumplido click izquierdo
			{
				nextSceneID = SceneID::Gameplay;
				wantsChange = true;

				music.stop();

			}
		}
	}

}

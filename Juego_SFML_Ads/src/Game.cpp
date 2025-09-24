#include "Game.h"

Game::Game(){}

void Game::Play()
{
	Initialize();	 //acá se crean todos los objetos con new
	Gameloop();		 //bucle de juego
	DeInitialize();  //acá se hacen todos los delete
}

void Game::Initialize()
{
	CreateWindow();
	CreatePlayer();
	CreateButton();
	CreateTestCollision();	

	//pueden implementar un scenemanager

	mainMenu = new MainMenu(resources, *window);
	pauseManager = new PauseManager(resources, *window, *&currentScene, *&mainMenu);	
	gameplay = new Gameplay(*player, resources, *window, *pauseManager);

	scenes.emplace(SceneID::MainMenu, mainMenu);
	scenes.emplace(SceneID::Gameplay, gameplay);

}

void Game::Gameloop()
{
	currentScene = scenes.find(SceneID::MainMenu)->second;

	while (window->isOpen())	//permite loopear
	{		
		Input();		//Captura de input
		Update();		//Update del juego
		Draw();			//Dibujado de los objetos
	}	
}

void Game::DeInitialize()
{
	DestroyWindow();
	DestroyPlayer();
}

void Game::Input()
{
	HandleEvents();
	currentScene->Input();
}

void Game::Update()
{
	float deltaTime = clock.restart().asSeconds();		//calculo de deltaTime
	
	currentScene->Update(deltaTime);

	if (currentScene->GetWantsChange())
	{
		currentScene->SetWantsChange(false);
		std::cout << (int)currentScene->GetNextSceneID();
		currentScene = scenes.find(currentScene->GetNextSceneID())->second;		

	}

	currentScene->Update(deltaTime);

	if (auto intersection = player->GetBounds().findIntersection(testCollision.getGlobalBounds()))	//detección de colisiones mediante Bounds
	{
		std::cout << "Colision" << std::endl;
	}
}

void Game::Draw()
{
	window->clear(); //borra todo lo que esta dibujado en ventana
		
	currentScene->Draw();

	window->display(); //muestra todo lo que se dibujó en ventana hasta el momento de su llamada
}

void Game::HandleEvents()
{
	while (const auto event = window->pollEvent())	//permite el manejo de eventos en SFML. Los eventos deben ir siempre dentro de este bucle.
	{
		if (event->is<sf::Event::Closed>()) //Permite que la ventana de juego reaccione al usuario (Mover ventana, estirar, maximizar, cerrar, etc).
			window->close();

		currentScene->HandleEvents(*event);	//en los eventos el operador * se encuentra sobrecargado. Normalmente los eventos de SFML vienen "cerrados en una caja" 
										//que puede estar llena o vacía. Con el operador * se pasa directamente el evento contenido (si es que lo hay)y no el contenedor 
		
	}
}

void Game::CreateWindow()
{
	unsigned int windowWidth = 1280;				
	unsigned int windowHeight = 720;
		
	window = new sf::RenderWindow(sf::VideoMode({ windowWidth, windowHeight }), "My Game");;
	window->setFramerateLimit(60);	//loquea a 60fps
}

void Game::DestroyWindow()
{
	delete window;
}

void Game::CreatePlayer()
{
	std::string path = "../textures/player/idle_right.png";		//path del sprite
	sf::Vector2i spriteSheetSize({ 17,34 });

	player = new Player(path, spriteSheetSize);
}

void Game::DestroyPlayer()
{
	delete player;
}

void Game::CreateButton()
{
	float width = 200.0f;
	float height = 50.0f;

	testButton.setSize(sf::Vector2f{ width, height });
	testButton.setOrigin(testButton.getSize() * 0.5f);

    sf::Vector2f pos = sf::Vector2f(window->getSize().x * 0.5f, window->getSize().y * 0.5f);

	testButton.setPosition(pos);

	testButton.setFillColor(sf::Color::Blue);
}

void Game::CreateTestCollision()
{
	float radius = 50.0f;

	testCollision.setRadius(50.0f);

	sf::Vector2f pos = sf::Vector2f(window->getSize().x * 0.75f - radius, window->getSize().y * 0.75f);

	testCollision.setPosition(pos);
	
}


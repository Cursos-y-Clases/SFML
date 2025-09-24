#include "Player.h"

Player::Player(std::string imageFilePath, sf::Vector2i spriteSheetSize)
{    
    sf::IntRect area({0, 0}, {135,68}); //spriteSheetTotal (spriteSheetSize)
   
    texture.loadFromFile(imageFilePath, false, area);

    sprite = new sf::Sprite(texture);

    //sf::IntRect currentArea({ currentXValue, 0 }, { 17 ,34 });  //Area del frame actual de la animación (IDLE)
    sf::IntRect currentArea({ currentXValue, 34 }, { 17 ,34 });  // (RUN)

    sprite->setTextureRect(currentArea); //seteo del frame actual (parte del spritesheet que se va a mostrar)

    sprite->setScale({ 3.0f, 3.0f });

    speed = 200.0f;

    canShoot = true;
    weapon = new Weapon();

    currentXValue = 0;
    animationTimer = 0;
}

Player::~Player()
{
    delete weapon;
    delete sprite;
}

void Player::Input()
{
    MovementInput();       
}

void Player::Update(float deltaTime)
{
    Movement(deltaTime);

    Animation(deltaTime);

    weapon->Update(deltaTime);
}

void Player::MovementInput()
{
    direction = sf::Vector2f({ 0,0 });

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        direction += sf::Vector2f({ 1,0 });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        direction += sf::Vector2f({ -1,0 });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        direction += sf::Vector2f({ 0,1 });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        direction += sf::Vector2f({ 0,-1 });
    }

    direction = VectorUtilities::NormalizeVector(direction);
}

void Player::Movement(float deltaTime)
{
    sprite->setPosition(sprite->getPosition() + direction * speed * deltaTime);
}

void Player::Animation(float deltaTime)
{
    int spriteXSize = 17;   //Tamaño en X del sprite

    int columnsCount = 7; //cantidad de columnas de la animación
    int maxXMovement = spriteXSize * (columnsCount - 1); //hasta donde se mueve en X la animación. Se resta en 1 porque la primer animación entra en 0,0

    float transitionTime = 0.4f;    //tiempo entre frame y frame de animación

    animationTimer += deltaTime;

    if (animationTimer >= transitionTime)
    {
        if (currentXValue != maxXMovement)
        {
            currentXValue += spriteXSize;
        }
        else
        {
            currentXValue = 0;
        }

        //sf::IntRect area({ currentXValue, 0 }, { 17 ,34 }); //(IDLE) Desde el punto inicial (primer vector) se arma un rectangulo a partir de otro vector (segundo vector)
        sf::IntRect area({ currentXValue, 34 }, { 17 ,34 }); //(RUN)

        sprite->setTextureRect(area);

        animationTimer = 0;
    }


}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(*sprite);
}

sf::FloatRect Player::GetBounds()
{
    return sprite->getGlobalBounds();
}

void Player::FireWeapon()
{
    sf::Vector2f shootPosition({ sprite->getPosition().x * 0.5f, sprite->getPosition().y * 0.5f });
    weapon->Shoot(shootPosition);
}

void Player::HandleEvents(const sf::Event& event)
{   
    if (const auto mouse = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouse->button == sf::Mouse::Button::Left)
        {
            if (!canShoot) return;

            FireWeapon();
            canShoot = false;
        }
    }
    else if (const auto mouse = event.getIf<sf::Event::MouseButtonReleased>())
    {
        if (mouse->button == sf::Mouse::Button::Left)
        {
            canShoot = true;

        }                
    }
}

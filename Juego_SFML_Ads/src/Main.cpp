#include <SFML/Graphics.hpp>
#include "Game.h"



int main()
{
    Game game;
    game.Play();
    
}

















































//Vector2f NormalizeVector(Vector2f vector);





/*sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML works!");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    Vector2f currentPos = shape.getPosition();

    Clock clock;
    float speed = 100;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        Vector2f direction = Vector2f({ 0,0 });


        if (Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            direction += Vector2f({ 1,0 });
        }

        if (Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            direction += Vector2f({ -1,0 });
        }

        if (Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            direction += Vector2f({ 0,1 });
        }

        if (Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            direction += Vector2f({ 0,-1 });
        }

        direction = NormalizeVector(direction);

        shape.setPosition(shape.getPosition() + direction * speed * deltaTime);


        window.draw(shape);
        window.display();
    }*/

//Vector2f NormalizeVector(Vector2f vector)
//{
//    Vector2f normalized;
//
//    float lenght = sqrt(vector.x * vector.x + vector.y * vector.y);
//	normalized = lenght > 0 ? vector / lenght : sf::Vector2f(0, 0);
//
//	return normalized;
//}

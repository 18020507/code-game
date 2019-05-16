#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>

class Object
{
private:
    sf::RenderWindow*   m_window;
    sf::Sprite          m_sprite_object;
public:
    Object(sf::RenderWindow* window, sf::Texture& texture);
    void                update();
    void                draw();

    sf::Vector2f        getPosition();
};

#endif // OBJECT_H

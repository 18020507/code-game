#ifndef OIL_H
#define OIL_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>

class Oil
{
private:
    sf::RenderWindow*   m_window;

    //sf::Texture         m_texture_oil;
    sf::Sprite          m_sprite_oil;
public:
    Oil(sf::RenderWindow* window, sf::Texture& texture);
    void                update();
    void                draw();

    sf::Vector2f        getPosition();
};

#endif // OIL_H

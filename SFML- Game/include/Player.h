#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

class Player
{
private:
    sf::RenderWindow*   m_window;

    sf::Texture         m_texture;
    sf::Sprite          m_sprite;
    sf::Time            m_time;
    sf::Clock           m_clock;
    int                 rotate_rest;
    int                 direction = 0;

public:
    Player(sf::RenderWindow* window);

    void                update();
    void                update_oil();
    void                draw();

    int getX()
    {
        return m_sprite.getPosition().x;
    }
    int getY()
    {
        return m_sprite.getPosition().y;
    }

    sf::Vector2f        getPosition();
};

#endif // PLAYER_H

#ifndef OBJECT2_H
#define OBJECT2_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include "Object.h"

class Object2
{
private:
    sf::RenderWindow*       m_window;

    sf::Sprite              m_sprite_object2;
    sf::Time                m_time;
    sf::Clock               m_clock;

public:
    Object2(sf::RenderWindow* window, sf::Texture& texture, Object* m_object_position);

//    Object*                 m_object_position;

    void                    update();
    void                    draw();

    sf::Vector2f            getPosition();
};

#endif // OBJECT2_H

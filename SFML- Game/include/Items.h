#ifndef ITEMS_H
#define ITEMS_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <sstream>


class Items
{
private:
    sf::RenderWindow*       m_window;

    sf::Font                m_font_items;
    sf::Text                m_text_items;

    sf::Sprite              m_sprite_items;

    sf::Time                m_time_items;
    sf::Clock               m_clock_items;
public:
    Items(sf::RenderWindow* window, sf::Texture& texture);
    int                     m_time_left;
    void                    update();
    void                    update_move();
    bool                    check_time();
    void                    draw_Items();
    void                    draw_Text();

    sf::Vector2f            getPosition();
};

#endif // ITEMS_H

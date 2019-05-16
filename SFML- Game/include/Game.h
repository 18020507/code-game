#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Player.h"
#include "Object.h"
#include "Object2.h"
#include "Oil.h"
#include "Items.h"
#include "Bullet.h"
#include <list>
#include <string>
#include <iostream>
#include <sstream>

class Game
{
private:
    sf::RenderWindow*       m_window;
    sf::Texture             m_texture_object;
    sf::Texture             m_texture_object2;
    sf::Texture             m_texture_oil;
    sf::Texture             m_texture_items;

    Player*                 m_player;

    sf::Clock               m_clock;
    sf::Time                m_time;
    sf::Clock               m_clock_oil;
    sf::Time                m_time_oil;
    sf::Clock               m_clock_shot;
    sf::Time                m_time_shot;

    std::list<Object>       m_object;
    std::list<Object2>      m_object2;
    std::list<Oil>          m_oil;
    std::list<Items>        m_items_list;

    unsigned int            m_score;
    sf::Font                m_font;
    sf::Text                m_text;

    float                   m_level;
    int                     m_gamelevel;
    sf::Text                m_text_level;

    Items*                  m_items;
    Bullet*                 m_bullet;
    int                     m_bullet_left;
    sf::Text                m_text_bullet;
public:
    Game(sf::RenderWindow* window);

    void shot_update();

    bool update();
    void update_faster();
    void update_loop();
    void update_oil();
    void update_items();
    bool check();
    void shot();
    void draw();
};

#endif // GAME_H

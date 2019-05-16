#include "Items.h"

Items::Items(sf::RenderWindow* window, sf::Texture& texture)   : m_time_left(50)
{
    this->m_window = window;

    this->m_font_items.loadFromFile("Assets/Font/Marker Felt.ttf");
    this->m_text_items.setFont(this->m_font_items);
    this->m_text_items.setCharacterSize(25);
    this->m_text_items.setPosition(500,80);

    this->m_sprite_items.setTexture(texture);
    this->m_sprite_items.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    int x = 13 + rand() % (500 - 13 - 13 + 1);
    this->m_sprite_items.setPosition(x, - 100);
}

void Items::update()
{

    m_time_items = m_clock_items.getElapsedTime();
    if (m_time_items.asSeconds() > 1.0)
    {
        m_time_left -= 1;
        m_clock_items.restart();
    }
    std::string Time_left;
    std::stringstream dem;
    dem << this->m_time_left;
    Time_left = dem.str();

    this->m_text_items.setString("Time Left: " + Time_left);
}

void Items::update_move()
{
    this->m_sprite_items.move(0, 5);
}

bool Items::check_time()
{
    if (m_time_left < 0)
    {
        return false;
    }
    return true;
}

void Items::draw_Items()
{
    this->m_window->draw(this->m_sprite_items);
}

void Items::draw_Text()
{
    this->m_window->draw(this->m_text_items);
}

sf::Vector2f Items::getPosition()
{
    return this->m_sprite_items.getPosition();
}

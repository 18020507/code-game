#include "Oil.h"

Oil::Oil(sf::RenderWindow* window, sf::Texture& texture)
{
    this->m_window = window;

    this->m_sprite_oil.setTexture(texture);
    this->m_sprite_oil.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    int x = 20 + rand() % (480 - 20 + 1);
    this->m_sprite_oil.setPosition(x, -100);
}

void Oil::update()
{
    this->m_sprite_oil.move(0, 5);
}

void Oil::draw()
{
    this->m_window->draw(this->m_sprite_oil);
}

sf::Vector2f Oil::getPosition()
{
    return this->m_sprite_oil.getPosition();
}


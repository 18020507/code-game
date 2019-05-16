#include "Object.h"

Object::Object(sf::RenderWindow* window, sf::Texture& texture)
{
    this->m_window = window;

    this->m_sprite_object.setTexture(texture);
    this->m_sprite_object.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    this->m_sprite_object.setRotation(180);
    int x = 25 + rand() % (475 - 25 + 1);
    this ->m_sprite_object.setPosition(x, 0);
}

void Object::update()
{
    this->m_sprite_object.move(0, 5);
}

void Object::draw()
{
    this->m_window->draw(this->m_sprite_object);
}

sf::Vector2f Object::getPosition()
{
    return this->m_sprite_object.getPosition();
}

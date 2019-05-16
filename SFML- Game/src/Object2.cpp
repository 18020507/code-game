#include "Object2.h"

Object2::Object2(sf::RenderWindow* window, sf::Texture& texture, Object* m_object_position)
{
    this->m_window = window;
  //  this->m_object_position = m_object_position;
    this->m_sprite_object2.setTexture(texture);
    this->m_sprite_object2.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
    this->m_sprite_object2.setRotation(180);
    int x = 25 + rand() % (475 - 25 + 1);
    this->m_sprite_object2.setPosition(x, m_object_position->getPosition().y - 200);
}
int s;
void Object2::update()
{
    this->m_time = this->m_clock.getElapsedTime();
    if(this->m_time.asSeconds() > 0.5)
    {
        s = rand() % 2;
        this->m_clock.restart();
    }
    if (s == 0 && m_sprite_object2.getPosition().x < 475)
        this->m_sprite_object2.move(2, 5);
    if (s == 1 && m_sprite_object2.getPosition().x > 25)
        this->m_sprite_object2.move(-2,5);
    if (m_sprite_object2.getPosition().x >= 475 || m_sprite_object2.getPosition().x <= 25)
        this->m_sprite_object2.move(0, 5);
}

void Object2::draw()
{
    this->m_window->draw(this->m_sprite_object2);
}

sf::Vector2f Object2::getPosition()
{
    return this->m_sprite_object2.getPosition();
}


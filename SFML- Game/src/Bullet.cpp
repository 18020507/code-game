#include "Bullet.h"
/*
Bullet::Bullet(sf::RenderWindow* window, Player* m_player_position)
{
    this->m_window = window;

    this->m_texture_bullet.loadFromFile("Assets/Texture/bullet.png");
    this->m_texture_bullet.setSmooth(true);
    this->m_sprite_bullet.setTexture(this->m_texture_bullet);
    this->m_sprite_bullet.setOrigin(this->m_texture_bullet.getSize().x/2, this->m_texture_bullet.getSize().y/2);
    this->m_sprite_bullet.setPosition(m_player_position->getPosition().x, m_player_position->getPosition().y - 50);
}

void Bullet::update()
{
    sf::Vector2f bullet_position = this->m_sprite_bullet.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        bullet_position.x -= 10;
    this->m_sprite_bullet.setPosition(bullet_position.x, bullet_position.y);
}

void Bullet::draw()
{
    this->m_window->draw(this->m_sprite_bullet);
}
sf::Vector2f Bullet::getPosition()
{
    return this->m_sprite_bullet.getPosition();
}
*/

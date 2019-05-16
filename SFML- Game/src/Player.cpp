#include "Player.h"

Player::Player(sf::RenderWindow* window)
{
    this->m_window = window;

    this->m_texture.loadFromFile("Assets/Texture/Xe.png");
    this->m_texture.setSmooth(true);

    this->m_sprite.setTexture(this->m_texture);
    this->m_sprite.setOrigin(this->m_texture.getSize().x/2,this->m_texture.getSize().y/2);
    this->m_sprite.setPosition(250, 550);

    rotate_rest = 0;
}

void Player::update()
{
    sf::Vector2f car_position = this->m_sprite.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        car_position.x -= 5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        car_position.x += 5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        car_position.y -= 5;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        car_position.y += 5;

    if (car_position.x <= 25)
        car_position.x = 25;
    if (car_position.x >= 475)
        car_position.x = 475;
    if (car_position.y >= 550)
        car_position.y = 550;
    if (car_position.y <= 50)
        car_position.y = 50;

    this->m_sprite.setPosition(car_position.x, car_position.y);
    if (rotate_rest > 0)
    {
        m_sprite.rotate(90.f);
        rotate_rest--;
    }
}
void Player::update_oil()
{
    if(rotate_rest <= 0)
        rotate_rest = 100;
    update();
}

void Player::draw()
{
    this->m_window->draw(this->m_sprite);
}

sf::Vector2f Player::getPosition()
{
    return this->m_sprite.getPosition();
}

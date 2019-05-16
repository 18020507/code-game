#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
//#include "Player.h"
/*
class Bullet
{
private:

    sf::RenderWindow*   m_window;

    sf::Texture         m_texture_bullet;
    sf::Sprite          m_sprite_bullet;
public:
    Bullet(sf::RenderWindow* window, Player* m_player_position);
    void update();
    void draw();
    sf::Vector2f        getPosition();
};
*/
class Bullet
{
    public:
    sf::CircleShape shape;
	sf::Vector2f currVelocity;
	float maxSpeed;

	Bullet(float radius = 5.f)
		: currVelocity(0.f, 0.f), maxSpeed(15.f)
	{
		this->shape.setRadius(radius);
		this->shape.setFillColor(sf::Color::Red);
	}
};
#endif // BULLET_H

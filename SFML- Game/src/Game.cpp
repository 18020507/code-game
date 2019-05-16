#include "Game.h"

Game::Game(sf::RenderWindow* window) : m_score(0), m_level(0), m_gamelevel(0), m_bullet_left(10)
{
    this->m_window = window;

    this->m_player = new Player(this->m_window);
    this->m_items =  new Items(this->m_window, this->m_texture_items);

    this->m_texture_object.loadFromFile("Assets/Texture/Object.png");
    this->m_texture_object.setSmooth(true);

    this->m_texture_object2.loadFromFile("Assets/Texture/ObjectZicZac.png");
    this->m_texture_object.setSmooth(true);

    this->m_texture_oil.loadFromFile("Assets/Texture/Oil1.png");
    this->m_texture_oil.setSmooth(true);

    this->m_texture_items.loadFromFile("Assets/Texture/watch1.png");
    this->m_texture_items.setSmooth(true);

    this->m_object.push_back(Object(this->m_window, this->m_texture_object));
    this->m_object2.push_back(Object2(this->m_window, this->m_texture_object2, &m_object.back()));

    this->m_font.loadFromFile("Assets/Font/Marker Felt.ttf");
    this->m_text.setFont(this->m_font);
    this->m_text.setCharacterSize(30);
    this->m_text.setPosition(500,0);

    this->m_text_level.setFont(this->m_font);
    this->m_text_level.setCharacterSize(30);
    this->m_text_level.setPosition(500,40);

    this->m_text_bullet.setFont(this->m_font);
    this->m_text_bullet.setCharacterSize(30);
    this->m_text_bullet.setPosition(500, 200);
}

Bullet b1;
std::vector<Bullet> bullets;
sf::Vector2f v(0.f, -1.f);

void Game::shot()
{
    //std::cout << b1.shape.getPosition().x << " " << b1.shape.getPosition().y << std::endl;
    this->m_time_shot = this->m_clock_shot.getElapsedTime();
    if (m_time_shot.asSeconds() > 1.0)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            b1.shape.setPosition(this->m_player->getX(), this->m_player->getY() - 50);
            b1.currVelocity = v * b1.maxSpeed;
            if (m_bullet_left > 0)
                bullets.push_back(Bullet(b1));
            m_bullet_left --;
            m_clock_shot.restart();
        }
    }
}

bool Game::update()
{
    //------ Object
    if (this->m_object.size() > 0)
    {
        for (std::list<Object>::iterator it = this->m_object.begin(); it != this-> m_object.end(); it++)
        {
            it->update();
        }
        int x = abs(this->m_player->getPosition().x - this->m_object.begin()->getPosition().x);
        int y = abs(this->m_player->getPosition().y - this->m_object.begin()->getPosition().y);

        if (x <= 40 && y <= 90)
        {
            return false;
        }

        if(this->m_object.begin() -> getPosition().y >= 550)
        {
            this->m_score += 1;
            this->m_object.pop_front();
        }
    }
    //------- Object2
    if (this->m_object2.size() > 0)
    {
        for (std::list<Object2>::iterator it = this->m_object2.begin(); it != this-> m_object2.end(); it++)
        {
            it->update();
        }
        int x = abs(this->m_player->getPosition().x - this->m_object2.begin()->getPosition().x);
        int y = abs(this->m_player->getPosition().y - this->m_object2.begin()->getPosition().y);

        if (x <= 40 && y <= 80)
        {
            return false;
        }

        if(this->m_object2.begin() -> getPosition().y >= 550)
        {
            this->m_score += 1;
            this->m_object2.pop_front();
        }
    }
    //----- Oil
    if (this->m_oil.size() > 0)
    {
        for (std::list<Oil>::iterator it = this->m_oil.begin(); it != this-> m_oil.end(); it++)
        {
            it->update();
        }

        if(this->m_oil.begin() -> getPosition().y >= 550)
        {
            this->m_score += 1;
            this->m_oil.pop_front();
        }
    }
    //----- Items
    if (this->m_items_list.size() > 0)
    {
        for (std::list<Items>::iterator it = this->m_items_list.begin(); it != this->m_items_list.end(); it++)
        {
            it->update_move();
        }

        if (this->m_items_list.begin() -> getPosition().y >= 550)
        {
            this->m_items_list.pop_front();
        }
    }
    //-----Bullet
    for (int i = 0; i < bullets.size(); i++)
    {
        for (std::list<Object>::iterator it = this->m_object.begin(); it != this-> m_object.end(); it++)
        {
            int x = abs(bullets[i].shape.getPosition().x - it->getPosition().x);
            int y = abs(bullets[i].shape.getPosition().y - it->getPosition().y);
            if (x <= 25 && y <= 50)
            {
                m_object.erase(it);
                bullets.erase(bullets.begin() + i);
                break;
            }
        }

        for (std::list<Object2>::iterator it = this->m_object2.begin(); it != this-> m_object2.end(); it++)
        {
            int x2 = abs(bullets[i].shape.getPosition().x - it->getPosition().x);
            int y2 = abs(bullets[i].shape.getPosition().y - it->getPosition().y);
            if (x2 <= 35 && y2 <= 60)
            {
                m_object2.erase(it);
                bullets.erase(bullets.begin() + i);
                break;
            }
        }
        bullets[i].shape.move(bullets[i].currVelocity);
        if (bullets[i].shape.getPosition().x < 0 || bullets[i].shape.getPosition().x > 645
                || bullets[i].shape.getPosition().y < 0 || bullets[i].shape.getPosition().y > 600)
        {
            bullets.erase(bullets.begin() + i);
        }
    }
    return true;
}

void Game::update_faster()
{
    if (this->m_score > 5)
    {
        this->m_level = 0.1;
        this->m_gamelevel = 1;
    }
    if (this->m_score > 10)
    {
        this->m_level = 0.2;
        this->m_gamelevel = 2;
    }
    if (this->m_score > 15)
    {
        this->m_level = 0.3;
        this->m_gamelevel = 3;
    }
    if (this->m_score > 20)
    {
        this->m_level = 0.3;
        this->m_gamelevel = 4;
    }
    if (this->m_score > 25)
    {
        this->m_level = 0.4;
        this->m_gamelevel = 5;
    }
    if (this->m_score > 30)
    {
        this->m_level = 0.5;
        this->m_gamelevel = 6;
    }
    if (this->m_score > 40)
    {
        this->m_level = 0.7;
        this->m_gamelevel = 7;
    }
}

void Game::update_loop()
{
    //---- lay thoi gian roi gaan lai
    this->m_time = this->m_clock.getElapsedTime();
    this->m_time_oil = this->m_clock_oil.getElapsedTime();
    //---- Nhanh hon


    if (this->m_time.asSeconds() > 2.0 - this->m_level)
    {
        this->m_object.push_back(Object(this->m_window, this->m_texture_object));
        this->m_clock.restart();

        this->m_object2.push_back(Object2(this->m_window, this->m_texture_object2, &m_object.back()));
        this->m_clock.restart();
    }

    if (this->m_time_oil.asSeconds() > 6.0 - this->m_level)
    {
        //------ Oil
        this->m_items_list.push_back(Items(this->m_window, this->m_texture_items));
        this->m_oil.push_back(Oil(this->m_window, this->m_texture_oil));
        this->m_clock_oil.restart();
    }
    std::string out_score;
    std::stringstream ss;
    ss << this->m_score;
    out_score = ss.str();

    std::string out_level;
    std::stringstream lv;
    lv << this->m_gamelevel;
    out_level = lv.str();

    std::string out_bullet;
    std::stringstream b;
    if(m_bullet_left <=0 )
        m_bullet_left = 0;
    b << this->m_bullet_left;
    out_bullet = b.str();

    this->m_text.setString("Score: " + out_score);
    this->m_text_level.setString("Level: " + out_level);
    this->m_text_bullet.setString("Bullets: " + out_bullet);
}

void Game::update_oil()
{
    //------ Khoang cach de va cham
    int x = abs(this->m_player->getPosition().x - this->m_oil.begin()->getPosition().x);
    int y = abs(this->m_player->getPosition().y - this->m_oil.begin()->getPosition().y);
    //------ Va cham thi Xe xoay
    if (x <= 40 && y <= 60)
    {
        this->m_player->update_oil();
    }
    //----- Khong Va Cham thi Xe Di chuyên Binh thuong
    else
        this->m_player->update();
}

void Game::update_items()
{
    int x = abs(this->m_player->getPosition().x - this->m_items_list.begin()->getPosition().x);
    int y = abs(this->m_player->getPosition().y - this->m_items_list.begin()->getPosition().y);

    if (x <= 37 && y <= 62)
    {
        this->m_items->m_time_left += 20;
        this->m_items_list.pop_front();
    }
    this->m_items->update();
}

bool Game::check()
{
    this->m_items->check_time();
}

void Game::draw()
{
    //----- draw Oil
    if(this->m_oil.size() > 0)
    {
        for (std::list<Oil>::iterator it = this->m_oil.begin(); it!=this->m_oil.end(); it ++)
        {
            it->draw();
        }
    }

    //----- draw Player
    this->m_player->draw();

    //----- draw Object
    if (this->m_object.size() > 0)
    {
        for (std::list<Object>::iterator it = this->m_object.begin(); it!=this->m_object.end(); it++)
        {
            it->draw();
        }
    }

    //----- draw Object2
    if (this->m_object2.size() > 0)
    {
        for (std::list<Object2>::iterator it = this->m_object2.begin(); it!=this->m_object2.end(); it++)
        {
            it->draw();
        }
    }

    if (this->m_items_list.size() > 0)
    {
        for (std::list<Items>::iterator it = this->m_items_list.begin(); it!= this->m_items_list.end(); it++)
        {
            it->draw_Items();
        }
    }
    this->m_window->draw(this->m_text);
    this->m_window->draw(this->m_text_level);

    //----- draw Items
    this->m_items->draw_Text();

    for (size_t i = 0; i < bullets.size(); i++)
    {
        this->m_window->draw(bullets[i].shape);
    }

    this->m_window->draw(this->m_text_bullet);
}

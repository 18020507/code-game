#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include "Game.h"
#include "Player.h"
#include "Object.h"
#include "Object2.h"
#include "Oil.h"
#include "Items.h"
#include "Bullet.h"
#include <iostream>
#include <string>
#include <vector>

using namespace sf;
using namespace std;

int Game_Over();

sf::RenderWindow window(sf::VideoMode(645, 600), "Don't hit car", sf::Style::Close);
void Game_play(RenderWindow &window)
{
    Music   music;
    music.openFromFile("bin/Debug/Ampyx-Rise.wav");
    music.play();
    music.setLoop(true);
    music.setVolume(100);

    Texture         m_texture_road;
    m_texture_road.loadFromFile("Assets/Texture/background.png");
    m_texture_road.setSmooth(true);
    Sprite          m_sprite_road(m_texture_road);
    Sprite          m_sprite_road2(m_texture_road);

    srand(time(NULL));
    Game game(&window);
    double RoadY1 = 0;
    double RoadY2 = -600;

    while (game.update())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        m_sprite_road.setPosition(0, RoadY1);
        m_sprite_road2.setPosition(0, RoadY2);
        if (RoadY2 > 0)
        {
            RoadY1 = 0;
            RoadY2 = RoadY1 - 500;
        }
        RoadY1 += 2.0;
        RoadY2 += 2.0;


        window.draw(m_sprite_road);
        window.draw(m_sprite_road2);

        game.draw();
        game.shot();
        game.update_faster();
        game.update_loop();
        game.update_oil();
        game.update_items();
        window.display();
    }
    music.pause();
    Texture         m_texture_gameover;
    m_texture_gameover.loadFromFile("Assets/Texture/Over.png");
    Sprite          m_sprite_gameover(m_texture_gameover);

    Music   music_end;
    music_end.openFromFile("bin/Debug/ChacAiDoSeVe.wav");
    music_end.play();

    Font            m_font_quit;
    m_font_quit.loadFromFile("Assets/Font/Marker Felt.ttf");
    Text            m_quit;
    m_quit.setString("Quit");
    m_quit.setFont(m_font_quit);
    m_quit.setCharacterSize(30);
    m_quit.setPosition(590,550);

    while(window.isOpen())
    {
        Event   event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(m_sprite_gameover);
        window.draw(m_quit);
        window.display();
        if (Mouse::getPosition(window).x >= 590 && Mouse::getPosition(window).x <= 640 && Mouse::getPosition(window).y >= 550 && Mouse::getPosition(window).y <= 580)
        {
            m_quit.setFillColor(Color::Magenta);
            if (Mouse::isButtonPressed(Mouse::Left))
                break;
        }
        else
            m_quit.setFillColor(Color::Yellow);
    }
}

void How_to_play(RenderWindow &window)
{
    Texture         m_texture_howToPlay;
    m_texture_howToPlay.loadFromFile("Assets/Texture/How_to_play.png");
    Sprite          m_sprite_howToPlay(m_texture_howToPlay);

    Font            m_font_quit;
    m_font_quit.loadFromFile("Assets/Font/Marker Felt.ttf");
    Text            m_quit;
    m_quit.setString("Quit");
    m_quit.setFont(m_font_quit);
    m_quit.setCharacterSize(30);
    m_quit.setPosition(590,550);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(m_sprite_howToPlay);
        window.draw(m_quit);
        window.display();

        if (Mouse::getPosition(window).x >= 590 && Mouse::getPosition(window).x <= 640 && Mouse::getPosition(window).y >= 550 && Mouse::getPosition(window).y <= 580)
        {
            m_quit.setFillColor(Color::Magenta);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                break;
            }
        }
        else
            m_quit.setFillColor(Color::Red);
    }
}

void Menu(RenderWindow &window)
{
    Texture     m_texture_Menu;
    m_texture_Menu.loadFromFile("Assets/Texture/Menu.png");
    Sprite      m_sprite_Menu(m_texture_Menu);
    Font        m_font_menu;
    m_font_menu.loadFromFile("Assets/Font/Marker Felt.ttf");
    Text        m_play;
    m_play.setString("Play");
    m_play.setFont(m_font_menu);
    m_play.setCharacterSize(30);
    m_play.setPosition(300,300);

    Text        m_howToPlay;
    m_howToPlay.setString("HowToPlay");
    m_howToPlay.setFont(m_font_menu);
    m_howToPlay.setCharacterSize(30);
    m_howToPlay.setPosition(270,340);

    Text        m_quit;
    m_quit.setString("Quit");
    m_quit.setFont(m_font_menu);
    m_quit.setCharacterSize(30);
    m_quit.setPosition(300,380);

    Music   music_begin;
    music_begin.openFromFile("bin/Debug/Start.wav");
    music_begin.play();
    music_begin.setLoop(true);
    music_begin.play();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(m_sprite_Menu);
        window.draw(m_play);
        window.draw(m_quit);
        window.draw(m_howToPlay);
        window.display();

        if (Mouse::getPosition(window).x >= 300 && Mouse::getPosition(window).x <= 350 && Mouse::getPosition(window).y >= 300 && Mouse::getPosition(window).y <= 330)
        {
            m_play.setFillColor(Color::Magenta);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                music_begin.pause();
                Game_play(window);
                music_begin.play();
            }
        }
        else
            m_play.setFillColor(Color::Yellow);

        if (Mouse::getPosition(window).x >= 270 && Mouse::getPosition(window).x <= 400 && Mouse::getPosition(window).y >= 340 && Mouse::getPosition(window).y <= 370)
        {
            m_howToPlay.setFillColor(Color::Magenta);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                How_to_play(window);
            }
        }
        else
            m_howToPlay.setFillColor(Color::Yellow);

        if (Mouse::getPosition(window).x >= 300 && Mouse::getPosition(window).x <= 350 && Mouse::getPosition(window).y >= 380 && Mouse::getPosition(window).y <= 410)
        {
            m_quit.setFillColor(Color::Magenta);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                break;
            }
        }
        else
            m_quit.setFillColor(Color::Yellow);
    }
}

int main()
{
    //sf::RenderWindow window(sf::VideoMode(645, 600), "Don't hit car", sf::Style::Close);
    window.setFramerateLimit(60);
    Menu(window);
    return EXIT_SUCCESS;
}
/*
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <bits/stdc++.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "console.h"

#define consoleWidth	80
#define consoleHeight	25
#define roadWidth		26

using namespace std;

int dem = 0;
struct ToaDo
{
    int y, x;	// y là tung độ, x là hoành độ
};

struct HinhDang
{
    char a[3][3];
};

struct Xe
{
    ToaDo td;	// tọa độ tại vị trí hd.a[1][1]
    HinhDang hd;
    int diem;
    int time;
};

struct VatCan
{
    ToaDo td;
    HinhDang hd;
};

struct ToaDoLon
{
    int y,x;
};

struct HinhDangLon
{
    char a[5][5];
};

struct VatCanLon
{
    ToaDoLon tdl;
    HinhDangLon hdl;
};

struct ToaDoItems
{
    int y,x;
};

struct TenItems
{
    string s = "TIME";
};

struct Items
{
    ToaDoItems tdvp;
    TenItems ten;
};

void KhoiTaoXe (Xe &xe)
{
    //------ Xe
#define pHD xe.hd.a

    xe.diem = 0;
    xe.time = 160;
    xe.td.y = consoleHeight - 2;
    xe.td.x = roadWidth / 2;

    pHD[0][0] = pHD[0][2] = pHD[2][0] = pHD[2][2] = 'o';	// bánh xe
    pHD[0][1] = '^';	// đầu xe
    pHD[1][0] = pHD[1][2] = '|';	// thân xe
    pHD[2][1] = '-';
    pHD[1][1] = ' ';

}

void KhoiTaoVatCan(VatCan &vc)
{
    //---------vật cản

    vc.td.x = 2 + rand() % (roadWidth - 4);
    vc.td.y = -2;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            vc.hd.a[i][j] = 173;
}

void KhoiTaoVatCanLon(VatCanLon &vcl, VatCan &vc)
{
    //---------- VatCanLon

    vcl.tdl.x = 3 + rand() % (roadWidth - 3 - 3 - 1);
    vcl.tdl.y = vc.td.y - 10;

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            vcl.hdl.a[i][j] = 174;
}

void KhoiTaoItems(Items &vp, VatCan &vc)
{
    vp.tdvp.x = 1 + rand() % (roadWidth - 4);
    vp.tdvp.y = vc.td.y - 17;
}

void HienThiXe( Xe xe )
{
    clrscr();

    // hiển thị biên

    TextColor (default_ColorCode);
    for (int i = 0; i < consoleHeight; i++)
        printf ("%c\n", 179);

    for (int i = 0; i < consoleHeight; i++)
    {
        gotoXY (roadWidth, i);
        putchar (179);
    }

    // hiển thị xe
    TextColor (ColorCode_Cyan);
    for (int kDong = -1; kDong <= 1; kDong++)
        for (int kCot = -1; kCot <= 1; kCot++)
        {
            int x = kCot + xe.td.x;
            int y = kDong + xe.td.y;

            gotoXY (x, y);
            putchar (xe.hd.a[kDong+1][kCot+1]);	//a[0][0] --> a[2][2]
        }
}

void HienThiTrangThaiGame(Xe xe, Items vp, VatCan vc)
{
    // hiển thị trạng thái game
    gotoXY (roadWidth + 2, 10);
    cout << "Diem = " << " " << xe.diem << endl;
    gotoXY (roadWidth + 2, 11);
    cout << "Time left: " << xe.time << endl;
    gotoXY (roadWidth + 2, 12);
    cout << vp.tdvp.x << " " << vp.tdvp.y << " " << dem;
}

void HienThiVatCan( VatCan vc )
{
    // hiển thị vật cản nè
    TextColor (ColorCode_Red);
    for (int kDong = -1; kDong <= 1; kDong++)
        for (int kCot = -1; kCot <= 1; kCot++)
        {
            int x = kCot + vc.td.x;
            int y = kDong + vc.td.y;

            if (y >= 0 && y < consoleHeight)
            {
                gotoXY (x, y);
                putchar (vc.hd.a[kDong+1][kCot+1]);	//a[0][0] --> a[2][2]
            }
        }
}

void HienThiVatCanLon(VatCanLon vcl)
{
    TextColor( ColorCode_Red);
    for (int kDong = -2; kDong <= 2; kDong++)
        for (int kCot = -2; kCot <= 2; kCot++)
        {
            int x = kCot + vcl.tdl.x;
            int y = kDong + vcl.tdl.y;

            if (y >= 0 && y < consoleHeight)
            {
                gotoXY (x, y);
                cout << vcl.hdl.a[kDong+2][kCot+2];
            }
        }
}

void HienThiItems(Items vp)
{
    TextColor(ColorCode_Pink);
    int x = vp.tdvp.x;
    int y = vp.tdvp.y;
    if (y >= 0 && y < consoleHeight)
    {
        gotoXY(x,y);
        cout << vp.ten.s;
    }
}

void DieuKhien(Xe &xe)
{
    if (_kbhit())
    {
        int key = _getch();

        if ((key == 'A' || key == 'a') && xe.td.x > 2)
            xe.td.x--;
        else if ((key == 'D' || key == 'd') && xe.td.x < roadWidth - 2)
            xe.td.x++;
        else if ((key == 'S' || key == 's') && xe.td.y < consoleHeight-2)
            xe.td.y++;
        else if ((key == 'W' || key == 'w') && xe.td.y > 0)
            xe.td.y--;
    }
}

// trả về 0 nếu ko có gì
// trả về -1 tức là va chạm
void XuLyDiXuong (Xe &xe, VatCan &vc, int &ThoiGianSleep)
{
    vc.td.y++;
    // nếu vật cản đi xuống dưới đáy tức là xe đã vượt qua vật cản
    // thì tăng điểm
    if (vc.td.y > consoleHeight)
    {
        xe.diem++;
        vc.td.x = 2 + rand() % (roadWidth - 4);
        vc.td.y = -2;

        if (ThoiGianSleep > 100)
            ThoiGianSleep -= 20;
    }
}

void VatCanLonDiXuong(Xe &xe, VatCanLon &vcl, VatCan &vc, int &ThoiGianSleep)
{
    vcl.tdl.y++;
    if (vcl.tdl.y > consoleHeight)
    {
        xe.diem++;
        vcl.tdl.x = 3 + rand() % (roadWidth - 3 - 3 + 1);
        vcl.tdl.y = vc.td.y - 10;

        if (ThoiGianSleep > 100)
            ThoiGianSleep -= 50;
    }
}

void VatCanLonDiChuyen(VatCanLon &vcl)
{
    int s = rand()%(1+1);
    if(s==0)
    {
        if(roadWidth - vcl.tdl.x > 3 && vcl.tdl.y > 0)
        {
            vcl.tdl.x++;
        }
    }
    else
    {
        if(vcl.tdl.x - 3 > 0 && vcl.tdl.y > 0)
        {
            vcl.tdl.x--;
        }
    }
}

void ItemsDiXuong(Items &vp, VatCan &vc)
{
    vp.tdvp.y ++;
    if (vp.tdvp.y > consoleHeight)
    {
        dem ++;
        vp.tdvp.x = 1 + rand() % (roadWidth - 4);
        vp.tdvp.y = vc.td.y - 17;
    }
}

void XuLyThoiGian (Xe &xe)
{
    while (xe.time >= 0)
    {
        xe.time --;
        break;
    }
}

int XuLyVaChamVatCan (Xe &xe, VatCan &vc)
{
    int dX = abs (xe.td.x - vc.td.x);
    int dY = abs (xe.td.y - vc.td.y);

    if (dX < 3 && dY < 3)
    {
        return -1;
    }
    return 0;
}

int XuLyVaChamVatCanLon (Xe &xe, VatCanLon &vcl)
{
    int Dxl = abs (xe.td.x - vcl.tdl.x);
    int Dyl = abs (xe.td.y - vcl.tdl.y);

    if (Dxl < 4 && Dyl < 4)
    {
        return -1;
    }
    return 0;
}

void XuLyVaChamItems (Xe &xe, Items &vp, VatCan &vc, int &ThoiGianSleep)
{
    int Dxvp = xe.td.x - vp.tdvp.x;
    int Dyvp = abs(xe.td.y - vp.tdvp.y);

    if ((Dxvp <= 5 && Dxvp > -1) && Dyvp <= 1)
    {
        dem ++;
        xe.time = 200;
        vp.tdvp.x = 1 + rand() % (roadWidth - 4);
        vp.tdvp.y = vc.td.y - 17;
    }
}
int main()
{
    srand (time (NULL));	// khởi tạo bộ sinh số ngẫu nhiên

    Xe xe;
    VatCan vc;
    Items vp;
    VatCanLon vcl;

    KhoiTaoXe (xe);
    KhoiTaoVatCan (vc);
    KhoiTaoItems (vp, vc);
    KhoiTaoVatCanLon (vcl, vc);

    int DieuKienVc = 0;
    int DieuKienVcl = 0;
    int ThoiGianSleep = 150;

    while (1)
    {
        // hiển thị
        HienThiXe(xe);
        HienThiTrangThaiGame(xe, vp, vc);
        HienThiVatCan(vc);
        HienThiVatCanLon(vcl);

        // điều khiển
        DieuKhien(xe);

        // xử lý
        XuLyDiXuong(xe, vc, ThoiGianSleep);
        VatCanLonDiXuong(xe, vcl, vc, ThoiGianSleep);
        VatCanLonDiChuyen(vcl);
        ItemsDiXuong(vp, vc);
        XuLyThoiGian(xe);

        DieuKienVc = XuLyVaChamVatCan(xe, vc);
        DieuKienVcl = XuLyVaChamVatCanLon(xe, vcl);

        // TRuong Hop Items Xuat Hien
        if(dem >= 2 && dem % 2 == 0 )
        {
            HienThiItems(vp);

            XuLyVaChamItems(xe, vp, vc, ThoiGianSleep);
        }

        // game over
        if (DieuKienVc == -1 || DieuKienVcl == -1)
        {
            gotoXY (roadWidth + 2, 13);
            cout << "LOSER";
            while (_getch() != 13)	;
            break;
        }
        if (xe.time < 0)
        {
            gotoXY (roadWidth + 2, 13);
            cout << "Ban Chet Vi Bom No";
            while (_getch() != 13);
            break;
        }
        Sleep (ThoiGianSleep);
    }
    return 0;
}
*/

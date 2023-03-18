#include <iostream>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include "Menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(960, 720), "This is the menu", sf::Style::Close | sf::Style::Resize);
    Menu gamemenu(window.getSize().x, window.getSize().y);
    //main bg
    sf::RectangleShape background(sf::Vector2f(960, 720));
    sf::Texture mainbg;
    mainbg.loadFromFile("light.jpg");
    background.setTexture(&mainbg);
    sf::RectangleShape offbackground(sf::Vector2f(960, 720));
    offbackground.setTexture(&mainbg);
    sf::RectangleShape onbackground(sf::Vector2f(960, 720));
    onbackground.setTexture(&mainbg);
    sf::RectangleShape optbackground(sf::Vector2f(960, 720));
    optbackground.setTexture(&mainbg);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    gamemenu.MoveUp();
                }

                if (event.key.code == sf::Keyboard::Down)
                {
                    gamemenu.MoveDown();
                }

                if (event.key.code == sf::Keyboard::Return)
                {
                    sf::RenderWindow PlayOffline(sf::VideoMode(960, 720), "New CV", sf::Style::Close | sf::Style::Resize);
                    sf::RenderWindow PlayOnline(sf::VideoMode(960, 720), "Editing CV", sf::Style::Close | sf::Style::Resize);

                    int num = gamemenu.GetPressedItem();
                    if (num == 0)
                    {
                        while (PlayOffline.isOpen())
                        {
                            sf::Event vent;
                            while (PlayOffline.pollEvent(vent))
                            {
                                if (vent.type == sf::Event::Closed)
                                    PlayOffline.close();
                                if (vent.type == sf::Event::KeyPressed)
                                {
                                    if (vent.key.code == sf::Keyboard::Escape)
                                        PlayOffline.close();
                                }
                            }
                            PlayOnline.close();
                            PlayOffline.clear();
                            PlayOffline.draw(offbackground);
                            PlayOffline.display();
                        }
                    }
                    if (num == 1)
                    {
                        while (PlayOnline.isOpen())
                        {
                            sf::Event vent;
                            while (PlayOnline.pollEvent(vent))
                            {
                                if (vent.type == sf::Event::Closed)
                                    PlayOnline.close();
                                if (vent.type == sf::Event::KeyPressed)
                                {
                                    if (vent.key.code == sf::Keyboard::Escape)
                                        PlayOnline.close();
                                }
                            }
                            PlayOffline.close();
                            //Options.close();
                            PlayOnline.clear();
                            PlayOnline.draw(onbackground);
                            PlayOnline.display();
                        }
                    }
                    if (num == 2)
                        window.close();
                    break;
                }
            }

        }

        window.clear();
        window.draw(background);
        gamemenu.Draw(window);
        window.display();
    }
}







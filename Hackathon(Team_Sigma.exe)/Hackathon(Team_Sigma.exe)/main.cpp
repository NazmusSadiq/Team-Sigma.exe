#include <iostream>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include "Menu.h"
#include <string>
#include "second_page.h"
#include "filename.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(960, 720), "This is the menu", sf::Style::Close | sf::Style::Resize);
    Menu gamemenu(window.getSize().x, window.getSize().y);
    Industry ind(window.getSize().x, window.getSize().y);
    //main bg
    sf::RectangleShape background(sf::Vector2f(960, 720));
    sf::Texture mainbg;
    mainbg.loadFromFile("light.jpg");
    background.setTexture(&mainbg);
    std::string filename;

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseMoved) {
                gamemenu.mousePressed(window);

            }
            if (event.type == sf::Event::KeyReleased || event.type == sf::Event::MouseButtonReleased)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    gamemenu.MoveUp();
                }

                if (event.key.code == sf::Keyboard::Down)
                {
                    gamemenu.MoveDown();
                }
                if (event.key.code == sf::Keyboard::Return || event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::RenderWindow NewCV(sf::VideoMode(960, 720), "New CV", sf::Style::Close | sf::Style::Resize);
                    sf::RenderWindow ExistingCV(sf::VideoMode(960, 720), "Editing CV", sf::Style::Close | sf::Style::Resize);

                    int num = gamemenu.GetPressedItem();
                    if (num != 2)
                    {
                        getStringInput(filename);
                        //std::cout << filename;
                    }
                    if (num == 0)
                    {
                        while (NewCV.isOpen())
                        {
                            sf::Event vent;

                            while (NewCV.pollEvent(vent))
                            {
                                if (vent.type == sf::Event::Closed)
                                    NewCV.close();
                                if (vent.type == sf::Event::KeyPressed)
                                {
                                    if (vent.key.code == sf::Keyboard::Escape)
                                        NewCV.close();
                                }
                                if (vent.type == sf::Event::MouseMoved) {
                                    ind.mousePressed(window);
                                }
                                if (vent.type == sf::Event::KeyReleased || vent.type == sf::Event::MouseButtonReleased) {
                                    if (vent.key.code == sf::Keyboard::Up)
                                    {
                                        ind.MoveUp();
                                    }
                                    if (vent.key.code == sf::Keyboard::Down)
                                    {
                                        ind.MoveDown();
                                    }
                                    if (vent.mouseButton.button == sf::Mouse::Left) {
                                        sf::RenderWindow cvtype(sf::VideoMode(960, 720), "CV type", sf::Style::Close | sf::Style::Resize);///////////
                                        int num1 = ind.GetPressedItem();
                                        ind.jobType = num1;
                                        while (cvtype.isOpen()) {
                                            sf::Event ent;
                                            while (cvtype.pollEvent(ent)) 
                                            {
                                                if (num1 <3) 
                                                {
                                                    sf::RenderWindow pinfo(sf::VideoMode(960, 720), "Personal Information", sf::Style::Close | sf::Style::Resize);
                                                    while (pinfo.isOpen())
                                                    {
                                                        sf::Event nt;
                                                        while (pinfo.pollEvent(nt))
                                                        {
                                                            if (nt.type == sf::Event::Closed || (nt.type == sf::Event::KeyReleased && nt.key.code == sf::Keyboard::Escape))
                                                            {
                                                                pinfo.close();
                                                            }
                                                        }
                                                        pinfo.clear();
                                                        //ExistingCV.close();
                                                        //NewCV.close();
                                                        cvtype.close();
                                                        //headerfile class var.draw(cvtype)
                                                        pinfo.draw(background);
                                                        pinfo.display();
                                                    }
                                                }
                                                if (num1 == 3)
                                                    cvtype.close();
                                            }
                                        }
                                        cvtype.clear();
                                        ExistingCV.close();
                                        NewCV.close();
                                        //headerfile class var.draw(cvtype)
                                        cvtype.draw(background);
                                        cvtype.display();
                                    }

                                }

                            }
                            ExistingCV.close();
                            NewCV.clear();
                            NewCV.draw(background);
                            ind.Draw(NewCV);
                            NewCV.display();
                        }

                    }
                    if (num == 1)
                    {
                        while (ExistingCV.isOpen())
                        {
                            sf::Event vent;
                            while (ExistingCV.pollEvent(vent))
                            {
                                if (vent.type == sf::Event::Closed)
                                    ExistingCV.close();
                                if (vent.type == sf::Event::KeyPressed)
                                {
                                    if (vent.key.code == sf::Keyboard::Escape)
                                        ExistingCV.close();
                                }
                            }
                            NewCV.close();
                            //Options.close();
                            ExistingCV.clear();

                            ExistingCV.draw(background);
                            ExistingCV.display();
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

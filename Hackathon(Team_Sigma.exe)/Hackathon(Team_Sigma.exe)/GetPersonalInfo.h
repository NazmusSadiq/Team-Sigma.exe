#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

void getPersonalInfo(std::string inputString[5])
{
    sf::RenderWindow window(sf::VideoMode(960, 720), "Personal Information",sf::Style::Close); // Create a window
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(960, 720));
    sf::Texture tex;
    tex.loadFromFile("light.jpg");
    shape.setTexture(&tex);
    sf::Font font; // Create a font object
    if (!font.loadFromFile("arial.ttf")) // Load a font file
    {
        std::cout << "Error loading font file!" << std::endl;
        return;
    }

    sf::Text text[5], textans[5],title; // Create a text object for input box
    for (int i = 0; i < 5; i++)
    {
        text[i].setFont(font); // Set the font
        text[i].setCharacterSize(30); // Set the character size
        text[i].setFillColor(sf::Color::Black);
        textans[i].setFont(font); // Set the font
        textans[i].setCharacterSize(30); // Set the character size
        textans[i].setFillColor(sf::Color::Black);
    } // Set the fill color
    title.setFont(font); // Set the font
    title.setCharacterSize(30); // Set the character size
    title.setFillColor(sf::Color::Black);
    title.setString("Personal Information");
    title.setPosition(290, 100);
    title.setScale(1.5, 1.5);
    text[0].setPosition(100, 250); // Set the position of the text
    text[0].setString("First Name:\n");
    text[1].setPosition(100, 290); // Set the position of the text
    text[1].setString("Last Name:\n");
    text[2].setPosition(100, 330); // Set the position of the text
    text[2].setString("Nationality:\n");
    text[3].setPosition(100, 370); // Set the position of the text
    text[3].setString("Date Of Birth(DD/MM/YY):\n");
    text[4].setPosition(100, 410);
    text[4].setString("Gender:\n");
    textans[0].setPosition(280, 250); // Set the position of the text
    textans[1].setPosition(280, 290); // Set the position of the text
    textans[2].setPosition(280, 330); // Set the position of the text
    textans[3].setPosition(470, 370); // Set the position of the text
    textans[4].setPosition(230, 410); // Set the position of the text
    int i = 0;
    std::string abc = "";
    while (window.isOpen()) // Main game loop
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) // Close window when "X" is clicked
            {
                window.close();
            }
            else if (event.type == sf::Event::TextEntered) // Get string input from user
            {
                if (event.text.unicode < 128) // Check if the input character is a valid ASCII character
                {
                    if (event.text.unicode == '\b') // Handle backspace
                    {
                        if (!inputString[i].empty()) // Check if the input string is not empty
                        {
                            inputString[i].pop_back(); // Remove the last character from the input string
                        }
                        textans[i].setString(inputString[i]); // Set the input string to the text object
                    }
                    else if (event.text.unicode == '\r') // Handle enter key
                    {
                        i++;
                        if (i > 4) return;// Return the input string when enter key is pressed
                    }
                    else // Add character to input string
                    {
                        inputString[i] += (char)(event.text.unicode); // Add the input character to the input string
                        textans[i].setString(inputString[i]); // Set the input string to the text object
                    }
                }
            }
        }

        window.clear(sf::Color::White); // Clear the window with white color
        window.draw(shape);
        window.draw(title);
        for(int i=0;i<5;i++)
            window.draw(text[i]);
        for (int i = 0; i < 5; i++)
            window.draw(textans[i]); // Draw the text object to the window
        window.display(); // Update the window display
    }
}
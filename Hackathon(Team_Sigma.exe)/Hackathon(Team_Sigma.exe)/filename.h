#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

void getStringInput(std::string& inputString)
{
    sf::RenderWindow window(sf::VideoMode(960, 720), "SFML Window"); // Create a window

    sf::Font font; // Create a font object
    if (!font.loadFromFile("arial.ttf")) // Load a font file
    {
        std::cout << "Error loading font file!" << std::endl;
        return;
    }

    sf::Text text,text1; // Create a text object for input box
    text1.setFont(font); // Set the font
    text1.setCharacterSize(30); // Set the character size
    text1.setFillColor(sf::Color::Black); // Set the fill color
    text1.setPosition(250, 250); // Set the position of the text
    text1.setString("Enter name of your CV (Don't use space)\n");
    text.setFont(font); // Set the font
    text.setCharacterSize(40); // Set the character size
    text.setFillColor(sf::Color::Black); // Set the fill color
    text.setPosition(330, 300); // Set the position of the text

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
                        if (!inputString.empty()) // Check if the input string is not empty
                        {
                            inputString.pop_back(); // Remove the last character from the input string
                        }
                        text.setString(inputString); // Set the input string to the text object
                    }
                    else if (event.text.unicode == '\r') // Handle enter key
                    {
                        return; // Return the input string when enter key is pressed
                    }
                    else // Add character to input string
                    {
                        inputString += static_cast<char>(event.text.unicode); // Add the input character to the input string
                        text.setString(inputString); // Set the input string to the text object
                    }
                }
            }
        }

        window.clear(sf::Color::White); // Clear the window with white color
        window.draw(text1);
        window.draw(text); // Draw the text object to the window
        window.display(); // Update the window display
    }
}
#include <iostream>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include "second_page.h"


sf::Text title;
Industry::Industry(float width, float height)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Not Loaded";
	}
	
	title.setFont(font); // Set the font
	title.setCharacterSize(30); // Set the character size
	title.setFillColor(sf::Color::Black);
	title.setString("Types Of CV");
	title.setPosition(340, 100);
	title.setScale(1.4, 1.4);
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Corporate");
	menu[0].setPosition(sf::Vector2f(width / 2 - 75, height / (MAX_NUMBER_OF_ITEMS + 1) * 1+150));
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Academics");
	menu[1].setPosition(sf::Vector2f(width / 2 - 75, height / (MAX_NUMBER_OF_ITEMS + 1) * 2+150));
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("Industrial");
	menu[2].setPosition(sf::Vector2f(width / 2 - 75, height / (MAX_NUMBER_OF_ITEMS + 1) * 3+150));
	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::Black);
	menu[3].setString("Back");
	menu[3].setPosition(sf::Vector2f(width / 2 - 75, height / (MAX_NUMBER_OF_ITEMS + 1) * 4+150));
	selectedItemIndex = 0;
}

void Industry::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
	window.draw(title);
}
void Industry::MoveUp()
{
	menu[selectedItemIndex].setFillColor(sf::Color::Black);
	selectedItemIndex--;
	menu[selectedItemIndex].setFillColor(sf::Color::Red);

	if (selectedItemIndex < 0)
	{
		selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Industry::MoveDown()
{
	menu[selectedItemIndex].setFillColor(sf::Color::Black);
	selectedItemIndex++;

	if (selectedItemIndex >= MAX_NUMBER_OF_ITEMS)
	{

		selectedItemIndex = 0;
	}
	menu[selectedItemIndex].setFillColor(sf::Color::Red);
}

int Industry::GetPressedItem()
{
	return selectedItemIndex;
}

void Industry::mousePressed(sf::RenderWindow& window)
{
	sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	sf::FloatRect but_1 = menu[0].getGlobalBounds();
	sf::FloatRect but_2 = menu[1].getGlobalBounds();
	sf::FloatRect but_3 = menu[2].getGlobalBounds();
	sf::FloatRect but_4 = menu[3].getGlobalBounds();
	if (but_1.contains(mousePos)) {
		menu[0].setFillColor(sf::Color::Red);
		selectedItemIndex = 0;
	}
	else {
		menu[0].setFillColor(sf::Color::Black);
	}
	if (but_2.contains(mousePos)) {
		menu[1].setFillColor(sf::Color::Red);
		selectedItemIndex = 1;
	}
	else {
		menu[1].setFillColor(sf::Color::Black);
	}
	if (but_3.contains(mousePos)) {
		menu[2].setFillColor(sf::Color::Red);
		selectedItemIndex = 2;
	}
	else {
		menu[2].setFillColor(sf::Color::Black);
	}
	if (but_4.contains(mousePos)) {
		menu[3].setFillColor(sf::Color::Red);
		selectedItemIndex = 3;
	}
	else {
		menu[3].setFillColor(sf::Color::Black);
	}
}

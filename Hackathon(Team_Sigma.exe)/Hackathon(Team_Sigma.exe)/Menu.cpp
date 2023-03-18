#include <iostream>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Window.hpp>
#include "Menu.h"



Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Plaguard-ZVnjx.otf"))
	{
		std::cout << "Not Loaded";
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Create a CV");
	menu[0].setPosition(sf::Vector2f(width / 2-75, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Open an existing CV");
	menu[1].setPosition(sf::Vector2f(width / 2-75, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString("Exit Application");
	menu[2].setPosition(sf::Vector2f(width / 2-75, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	selectedItemIndex = 0 ;
}

void Menu::Draw(sf::RenderWindow  &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MoveUp()
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
 
void Menu::MoveDown()
{
		menu[selectedItemIndex].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		
		if (selectedItemIndex >= MAX_NUMBER_OF_ITEMS)
		{
			selectedItemIndex = 0;
		}
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
}

int Menu::GetPressedItem()
{
	return selectedItemIndex;
}



#pragma once
#define MAX_NUMBER_OF_ITEMS 3
#include<SFML/Graphics.hpp>
class Menu
{
public:
	Menu(float width, float height);
	void Draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();
	sf::RectangleShape box;
	sf::Texture boxtex;
private:
	int selectedItemIndex;
	sf:: Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

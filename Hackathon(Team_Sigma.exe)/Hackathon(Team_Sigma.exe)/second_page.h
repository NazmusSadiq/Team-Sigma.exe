#pragma once
#define MAX_NUMBER_OF_ITEMS 4
#include<SFML/Graphics.hpp>
class Industry
{
public:
	Industry(float width, float height);
	void Draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();
	void mousePressed(sf::RenderWindow& window);
	int jobType;

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

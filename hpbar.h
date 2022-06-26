#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"
class Hpbar
{
public:
	sf::Sprite sprite;
	sf::Texture texture;
	int max;
	sf::RectangleShape bar;
	Hpbar();
	void update(int k = PLAYER_HP);
	void draw(sf::RenderWindow& window);
};

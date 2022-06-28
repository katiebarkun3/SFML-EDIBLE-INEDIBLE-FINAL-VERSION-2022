#include "hpbar.h"

Hpbar::Hpbar()
{
	texture.loadFromFile(IMAGES_FOLDER + HPBAR_FILE_NAME);
	sprite.setTexture(texture);
	bar.setFillColor(sf::Color(0, 0, 0));
	max = 100;
}

void Hpbar::update(int k)

{
	if (k > 0)
		if (k < max)
		bar.setSize(sf::Vector2f(((max - k) * 126 / max), 22)); 
	if (k >= 100) {
		bar.setSize(sf::Vector2f(0, 0));
	}
	if (k <= 100 && k > 70) {
		texture.loadFromFile(IMAGES_FOLDER + HPBAR_FILE_NAME);
		sprite.setTexture(texture);
	}
	if (k < 70 && k > 50) {
		texture.loadFromFile(IMAGES_FOLDER + HPBAR_YELLOW_FILE_NAME);
		sprite.setTexture(texture);
	}
	if (k < 50 && k > 30) {
		texture.loadFromFile(IMAGES_FOLDER + HPBAR_ORANGE_FILE_NAME);
		sprite.setTexture(texture);
	}
	if (k < 30 && k > 0) {
		texture.loadFromFile(IMAGES_FOLDER + HPBAR_RED_FILE_NAME);
		sprite.setTexture(texture);
	}
	
}

void Hpbar::draw(sf::RenderWindow& window)
{

	sprite.setPosition(0, 0);
	bar.setPosition(13, 9);

	window.draw(sprite);
	window.draw(bar);
}


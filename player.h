#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

class Player {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speed = sf::Vector2f(0.f, 0.f);
	sf::Vector2f acc = sf::Vector2f(0.f, 0.f);
	sf::Vector2f pos = sf::Vector2f(200.f, WINDOW_HEIGHT - 250.f);
	sf::Clock player_clock;
	float CurrentFrame = 0;
	float GRAVITY = 0.6f;
	int hp = PLAYER_HP;
	bool isJumping = false;
public:
	Player();
	void update();
	void draw(sf::RenderWindow& window);
	void decreaseHp(size_t);
	void increaseHp(size_t);
	void jump();
	void resetSpeed() { speed.y = 0.f; }
	int getHp();
	bool getIsJump() { return isJumping; }
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	sf::Vector2f getSpeed() { return speed; }
};


#include "player.h"
#include "settings.h"

Player::Player() {
	texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);
	sprite.setTexture(texture);
	sf::FloatRect g_bounds = sprite.getGlobalBounds();
	sprite.setPosition(WINDOW_WIDTH / 2 - g_bounds.width / 2,
		WINDOW_HEIGHT - g_bounds.height - PLAYER_OFFSET_Y);
}
void Player::update() {
	acc = sf::Vector2f(0.f, GRAVITY);
	sf::Vector2f position = sprite.getPosition();
	sf::FloatRect g_bounds = sprite.getGlobalBounds();

	float time = player_clock.getElapsedTime().asMicroseconds();
	player_clock.restart();
	time = time / 800;
	sprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
	CurrentFrame += 0.005 * time;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
		position.x < WINDOW_WIDTH - g_bounds.width) {

		texture.loadFromFile(IMAGES_FOLDER + RIGHT_ANIMATION_PLAYER_FILE_NAME);

		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(128 * int(CurrentFrame), 0, 128, 128));
		acc.x = PLAYER_ACC_X;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
		position.x > 0) {

		texture.loadFromFile(IMAGES_FOLDER + LEFT_ANIMATION_PLAYER_FILE_NAME);

		if (CurrentFrame > 3) CurrentFrame -= 3;
		sprite.setTextureRect(sf::IntRect(128 * int(CurrentFrame), 0, 128, 128));
		acc.x = -PLAYER_ACC_X;
	}
	else
	{
		texture.loadFromFile(IMAGES_FOLDER + PLAYER_FILE_NAME);
	}
	acc.x += speed.x * FRICTION;
	speed += acc;
	pos += speed + sf::Vector2f(0.5f * acc.x, 0.5f * acc.y);
	if (pos.y >= 760.f) { 
		speed.y = 0;
		pos.y = PLAYER_POSITION_Y;
		isJumping = false;
	}
	sprite.setPosition(pos);
	
}
void Player::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Player::decreaseHp(size_t dmg) { hp -= dmg; }
void Player::increaseHp(size_t add_hp) { hp += add_hp; }
void Player::jump() { speed.y = JUMP_SPEED; isJumping = true; }
sf::FloatRect Player::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Player::getPosition() { return sprite.getPosition(); }
int Player::getHp() { return hp; }
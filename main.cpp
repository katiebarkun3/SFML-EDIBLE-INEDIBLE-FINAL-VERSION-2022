#include "game.h"
#include <ctime>
int main() {
	srand(time(0));
	rand();
	Game game;
	game.play();
	return 0;
}
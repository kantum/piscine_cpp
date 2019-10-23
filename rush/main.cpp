#include <iostream>
#include <unistd.h>
#include <string>
#include <ncurses.h>

#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Character.hpp"
#include "Menu.hpp"

# define FRAME_RATE 60

int main() {
	clock_t start2, now;

	Menu	*menu;
	Game	*game;

	while (42)
	{
		game = new Game;
		menu = new Menu;
		menu->setMenu(game->getMaxY(), game->getMaxX());
		delete menu;

		game->colorInit();
		game->spawnPlayer();
		game->spawnEnemy();
		while (!game->isEndgame())
		{
			start2 = clock();
			game->getEvent();
			game->refresh();
			now = clock();
			usleep(CLOCKS_PER_SEC/FRAME_RATE - (now - start2));
		}
		delete game;
	}
	endwin();
	return (0);
}

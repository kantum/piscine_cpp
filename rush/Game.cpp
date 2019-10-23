#include "Game.hpp"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <ncurses.h>

#define	NB_COLOR 7

Game::Game() : _endgame(false), _score(0) {
	time(&this->_start);
	initscr();
	cbreak();
	noecho();
	start_color();
	curs_set(0);
    this->_proj = Projectile(0,0,1);
    this->_proj2 = Projectile(0,0,-1);
    this->_proj2.setNull(true);
	std::srand(std::time(0));
	getmaxyx(stdscr, this->_maxY, this->_maxX);
	this->_enemy = new Enemy[NB_ENEMY];
	for (int i = 0; i < NB_ENEMY; i++)
	{
		this->_enemy[i].setLife(0);
		this->_enemy[i].setPosYX(0,0);
		this->_enemy[i].setSpeed(1);
		this->_enemy[i].setColor(1);
	}
}

Game::~Game() {
	delete [] this->_enemy;
}

Game::Game(Game const &src) {
	*this = src;
}

Game &Game::operator=(Game const &rhs) {
    if(this != &rhs){
        this->setPlayer(rhs.getPlayer());
        this->setMaxY(rhs.getMaxY());
        this->setMaxX(rhs.getMaxX());
       this->_proj = rhs._proj;
       this->_proj2 = rhs._proj2;
        for (int j = 0; j < NB_ENEMY; j++) {
            this->_enemy[j] = rhs._enemy[j];
        }
        this->setEndgame(rhs.isEndgame());
        this->setScore(rhs.getScore());;
    }
    return *this;
}

Player Game::getPlayer() const {
	return this->_player;
}

void Game::setPlayer(Player player) {
	this->_player = player;
}

void Game::setMaxX(int x) {
	this->_maxX = x;
}

int Game::getMaxX(void) const {
	return this->_maxX;
}

void Game::setMaxY(int y) {
	this->_maxY = y;
}

int Game::getMaxY() const {
	return this->_maxY;
}

void Game::spawnPlayer(void) {
	this->_player = Player(this->_maxY - 3, this->_maxX / 2);
	this->drawPlayer();
}

void Game::drawPlayer(void) {
	attron(COLOR_PAIR(COLOR_BLACK));
	mvprintw(this->getPlayer().getPosY() - 1, this->getPlayer().getPosX()    , "^");
	mvprintw(this->getPlayer().getPosY()    , this->getPlayer().getPosX()    , " ");
	mvprintw(this->getPlayer().getPosY()    , this->getPlayer().getPosX() - 1, "/");
	mvprintw(this->getPlayer().getPosY()    , this->getPlayer().getPosX() + 1, "\\");
	mvprintw(this->getPlayer().getPosY() + 1, this->getPlayer().getPosX() - 2, "/");
	mvprintw(this->getPlayer().getPosY() + 1, this->getPlayer().getPosX() + 2, "\\");
	attroff(COLOR_PAIR(COLOR_BLACK));
}

void Game::refresh() {
    this->_now = time(0);
    werase(stdscr);
    this->stars();
    if (!this->canrespawn())
        this->spawnEnemy();
    this->drawPlayer();
    this->checkhit();
    this->drawProj();
    this->drawEnemy();
    this->displayinfo();
	this->enemyfire();
    time(&this->_finsish);
    wrefresh(stdscr);
}

void	Game::getEvent(void)
{
	int c;
	nodelay(stdscr, 1);
	keypad(stdscr, TRUE);
	timeout(0);
	c = wgetch(stdscr);
	refresh();
	switch(c)
	{	
		case KEY_UP:
			if (!(this->_player.getPosY() < 2 + this->_player.getSpeed()))
				this->_player.moveUp();
			break;
		case KEY_DOWN:
			if (!(this->_player.getPosY() > this->_maxY - 3 - this->_player.getSpeed()))
				this->_player.moveDown();
			break;
		case KEY_RIGHT:
			if (!(this->_player.getPosX() > this->_maxX - 3 - this->_player.getSpeed()))
				this->_player.moveRight();
			break;
		case KEY_LEFT:
			if (!(this->_player.getPosX() <= 0 + this->_player.getSpeed()))
				this->_player.moveLeft();
			break;
		case 's':
			if (this->_player.getSpeed() == 2)
				this->_player.setSpeed(5);
			else
				this->_player.setSpeed(2);
			break;
		case ' ':
			if (this->_proj.isNull())
				this->_player.fire(this->getProj());
			break;
		case 27:
			this->setEndgame(true);
			break;
		default:
			break;
	}
}

void	Game::colorInit(void)
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void	Game::stars(void)
{
	static int y = 0;
	static int speed= SCROLL_SPEED;
	static int color = 1;
	int spread = 17;

	if (!speed--)
	{
		speed = SCROLL_SPEED;
		if (y == spread)
			y = 1;
		else
			y++;
		color = rand() % NB_COLOR;
	}
	for (int i = 0; i < this->_maxY; i += 1)
	{
		for (int k = 0; k < 20; k++)
		{
			attron(COLOR_PAIR((color + 1) % NB_COLOR));
			mvprintw(y - this->_maxY + i * spread,
					this->_maxX - (k * spread * 2), ".");
			attroff(COLOR_PAIR((color + 1) % NB_COLOR));
		}
	}
}

void Game:: drawProj(void) {
	if (!this->_proj.isNull()){
		this->_proj.update();
		this->_proj.draw();
		if (this->_proj.getPosY() <= 0)
			this->_proj.setNull(true);
	}

    if (!this->_proj2.isNull()){
        this->_proj2.update();
        this->_proj2.draw();
        if (this->_proj2.getPosY() > this->_maxY) {

            this->_proj2.setNull(true);
        }
    }

}

void Game::spawnEnemy(void) {
	for (int i = 0; i < NB_ENEMY; i++)
	{
		this->_enemy[i].rdmyx();
		this->_enemy[i].setLife(1);
	}
}

void Game::drawEnemy(void) {
	static int speed = SCROLL_SPEED;

	if (!speed--)
	{
		speed = SCROLL_SPEED;
		for (int i = 0; i < NB_ENEMY; i++) {
			if (this->_enemy[i].getLife() > 0){
				if(this->_enemy[i].getPosY() < this->getMaxY() + 1)
					this->_enemy[i].setPosY(this->_enemy[i].getPosY() + 1);
				else
					this->_enemy[i].rdmyx();
			}
		}
	}
	else
	{
		for (int i = 0; i < NB_ENEMY; i++) {
			if (this->_enemy[i].getLife() > 0)
			{
				mvprintw(this->_enemy[i].getPosY(),     this->_enemy[i].getPosX(),     "V");
				mvprintw(this->_enemy[i].getPosY() - 1, this->_enemy[i].getPosX() - 1, "V");
				mvprintw(this->_enemy[i].getPosY() - 1, this->_enemy[i].getPosX() + 1, "V");
			}
			else if (this->_enemy[i].getLife() == 0)
			{
				static int xtime= 10;
				if (!--xtime)
				{
					xtime = 10;
					this->_enemy[i].setLife(-1);
				}
				this->_enemy[i].explode();
			}
		}
	}
}

Projectile &Game::getProj() {
	return _proj;
}

void Game::checkhit() {
	int	playerY = this->getPlayer().getPosY();
	int	playerX = this->getPlayer().getPosX();
	int	projY   = this->getProj().getPosY();
	int	projX   = this->getProj().getPosX();
	int	speed   = this->getProj().getSpeed();
	int plsize  = 5;
	int ensize  = 3;

	if (ensize && plsize > 2)
		plsize  = (plsize - 1) / 2;
	else
		plsize = 0;
	if (ensize && ensize > 2)
		ensize  = (ensize - 1) / 2;
	else
		ensize = 0;

	for (int i = 0; i < NB_ENEMY; i++)
	{
		int enemyY     = this->_enemy[i].getPosY();
		int enemyX     = this->_enemy[i].getPosX();
		int enemyLife  = this->_enemy[i].getLife();
		if (       enemyX  - ensize <= projX
				&& enemyX  + ensize >= projX
				&& enemyY <= (projY + speed / 2)
				&& enemyY >= (projY - speed / 2)
				&& enemyLife > 0)
		{
			this->getProj().setNull(true);
			this->_enemy[i].setLife(0);
			this->setScore(this->getScore() + 1);
		}
		if (       enemyY - ensize <= playerY + plsize
				&& enemyY + ensize >= playerY - plsize
				&& enemyX - ensize <= playerX + plsize
				&& enemyX + ensize >= playerX - plsize
				&& this->_enemy[i].getLife() > 0)
		{
			this->getPlayer().setLife(this->getPlayer().getLife() - 1);
			this->_enemy[i].setLife(0);
			this->_player.explode();
			this->_player.setLife(this->getPlayer().getLife() - 1) ;
			if (this->getPlayer().getLife() <= 0)
				this->setEndgame(true);
		}

	}
	this->checkhitplayer();
}

void Game::checkhitplayer() {

    int yp = this->getPlayer().getPosY();
    int xp = this->getPlayer().getPosX();
    int yj = this->getProj2().getPosY();
    int xj = this->getProj2().getPosX();
    int plsize  = 5;
    if (plsize > 2)
        plsize  = (plsize - 1) / 2;
    else
        plsize = 0;

    if(yj <= yp + plsize
       && yj >= yp - plsize
       && xj >= xp - plsize
       && xj <= xp + plsize){
        this->getProj2().setNull(true);
        this->getPlayer().setLife(this->getPlayer().getLife() - 1);
        this->_player.setLife(this->getPlayer().getLife() - 1) ;
        if (this->getPlayer().getLife() <= 0)
            this->setEndgame(true);
    }


}

bool Game::isEndgame() const {
	return this->_endgame;
}

void Game::setEndgame(bool endgame) {
	this->_endgame = endgame;
}

void Game::displayinfo() const {

	mvprintw(this->getMaxY() - 5 ,3,
			"Score : %d ", this->getScore());
	mvprintw(this->getMaxY() - 4 ,3,
			"Life : %d ", this->getPlayer().getLife());
	mvprintw(this->getMaxY() - 3 ,3,
			"Temps ecoule  : %.0f seconds ", difftime(this->_finsish, this->_start),
             (difftime(this->_finsish, this->_start) / 60 ));
}

unsigned int Game::getScore() const {
	return this->_score;
}

void Game::setScore(unsigned int score) {
	this->_score = score;
}

bool Game::canrespawn() {
	for (int i = 0; i < NB_ENEMY; i++) {
		if(this->_enemy[i].getLife() > 0)
			return true;
	}
	return false;
}

Projectile &Game::getProj2() {
    return this->_proj2;
}

void Game::enemyfire() {
    if (this->getProj2().isNull()) {
        Enemy f = this->_enemy[rand() % NB_ENEMY];
        if(f.getLife() > 0 && f.getPosY() > 1) {
            f.fire(this->getProj2());
        }
    }

}

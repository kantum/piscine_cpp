#ifndef GAME_HPP
#define GAME_HPP

#define SCROLL_SPEED 10
#define NB_ENEMY 42

#include "ncurses.h"
#include "Player.hpp"
#include "Enemy.hpp"
#include <unistd.h>

class Game {
private:
    Player _player;
    Projectile  _proj;
    Projectile  _proj2;
    Enemy *_enemy;
	int	_maxX;
	int	_maxY;
	bool _endgame;
	unsigned int _score;
	time_t _start;
	time_t _finsish;
	time_t _now;

public:
    virtual ~Game();
    Game();
    Game(Game const &src);
    Game    &operator=(Game const &rhs);

    Player getPlayer() const;

	void refresh(void);
    void setPlayer(Player player);
    void spawnPlayer(void);
    void spawnEnemy(void);
	void setMaxX(int x);
	int  getMaxX(void) const;
	void setMaxY(int x);
	int  getMaxY(void) const;
    void getEvent(void);
    void stars(void);
	void colorInit(void);
    bool isEndgame() const;
    void setEndgame(bool endgame);
    void displayinfo() const;
    unsigned int getScore() const;
    void setScore(unsigned int score);
    bool canrespawn();
    void    enemyfire();
    void checkhit();
    void checkhitplayer();
    void drawPlayer(void);
    void drawEnemy(void);
    void drawProj(void);
    Projectile &getProj();
    Projectile &getProj2();

};


#endif

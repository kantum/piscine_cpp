#include <ncurses.h>
#include "Enemy.hpp"
#include "Projectile.hpp"
#include <iostream>
#include <unistd.h>

Enemy::Enemy() {
    this->setLife(1);
    this->setSpeed(10);
}

Enemy::Enemy(int posY, int posX) : Character(posY, posX) {
    this->setLife(1);
}

Enemy::~Enemy() {

}

Enemy::Enemy(Enemy const &src) {
    *this = src;
}

Enemy &Enemy::operator=(Enemy const &rhs) {
    if (this != &rhs){
        this->setPosY(rhs.getPosY());
        this->setPosX(rhs.getPosX());
        this->setLife(rhs.getLife());
        this->setColor(rhs.getColor());
        this->setSpeed(rhs.getSpeed());
    }
    return *this;
}

void Enemy::fire(Projectile &p) {
    p.setNull(false);
    p.setPosYX(this->getPosY() + 2, this->getPosX());
    p.setSpeed(1);
    p.setDirection(DIR_DOWN);
}


void Enemy::rdmyx() {
    int xmin =               40;
    int ymin =              -50;
    int xmax = 0;
    int ymax = 0;
    getmaxyx(stdscr, ymax, xmax);
    xmax = xmax - 40;
    ymax = ymax - 50 - ymin;
    this->setPosYX(
            ymin + rand() % ymax,
            xmin + rand() % xmax);
}

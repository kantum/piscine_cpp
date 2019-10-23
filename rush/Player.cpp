
#include "Player.hpp"
#include "Projectile.hpp"
#include "Game.hpp"
#include <ncurses.h>

Player::Player() {
}

Player::~Player() {
}

Player::Player(int posY, int posX) : Character(posY, posX) {
    this->setLife(4);
    this->setSpeed(5);
}

Player::Player(Player const &src) {
    *this = src;
}

Player &Player::operator=(Player const &rhs) {
    if (this != &rhs){
        this->setPosY(rhs.getPosY());
        this->setPosX(rhs.getPosX());
        this->setLife(rhs.getLife());
        this->setColor(rhs.getColor());
        this->setSpeed(rhs.getSpeed());
    }
    return *this;
}

void Player::fire(Projectile &p) {
    p.setNull(false);
    p.setPosYX(this->getPosY() - 4, this->getPosX());
	p.setSpeed(5);
	p.setDirection(DIR_UP);
}

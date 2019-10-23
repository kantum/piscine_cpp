
#include "Character.hpp"

Character::Character() {
	this->_speed = 1;
	this->_color = 1;
}

Character::~Character() {

}

int Character::getColor() const {
    return this->_color;
}

void Character::setColor(int color) {
    this->_color = color;
}

int Character::getPosY() const {
    return this->_posY;
}

void Character::setPosY(int posY) {
    this->_posY = posY;
}

void Character::setPosX(int posX) {
    this->_posX = posX;
}

int Character::getSpeed() const {
    return this->_speed;
}

void Character::setSpeed(int speed) {
    this->_speed = speed;
}

int Character::getPosX() const {
    return this->_posX;
}

int Character::getLife() const {
    return this->_life;
}

void Character::setLife(int life) {
    this->_life = life;
}

Character::Character(Character const &src) {
    *this = src;
}

Character &Character::operator=(Character const &rhs) {
    if (this != &rhs){
        this->setPosY(rhs.getPosY());
        this->setPosX(rhs.getPosX());
        this->setLife(rhs.getLife());
        this->setColor(rhs.getColor());
        this->setSpeed(rhs.getSpeed());
    }
    return *this;
}

void Character::setPosYX(int posY, int posX) {
    this->setPosX(posX);
    this->setPosY(posY);
}

Character::Character(int posY, int posX) : _posY(posY), _posX(posX), _life(5), _speed(1), _color(1) {}

Character::Character(int posY, int posX, int life) : _posY(posY), _posX(posX), _life(life),  _speed(1), _color(1) {}

void Character::moveUp(void) {
    this->setPosY(this->getPosY() - this->getSpeed());
}

void Character::moveDown(void) {
    this->setPosY(this->getPosY() + 1);
}

void Character::moveRight(void) {
    this->setPosX(this->getPosX() + this->getSpeed());
}

void Character::moveLeft(void) {
    this->setPosX(this->getPosX() - this->getSpeed());
}

void Character::fire(Projectile &p) {
    (void)p;
}

void Character::explode() {
	int xpos = this->getPosX();;
	int ypos = this->getPosY();;
	attron(COLOR_PAIR(3));
	mvprintw(ypos - 1, xpos - 1, "\\");
	mvprintw(ypos - 1, xpos    , "|");
	mvprintw(ypos + 1, xpos - 1, "/");
	mvprintw(ypos + 1, xpos + 1, "\\");
	mvprintw(ypos + 1, xpos    , "|");
	mvprintw(ypos - 1, xpos + 1, "/");
	mvprintw(ypos    , xpos - 1, "-");
	mvprintw(ypos    , xpos + 1, "-");
	attroff(COLOR_PAIR(3));
}

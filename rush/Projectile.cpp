
#include "Projectile.hpp"
#include <ncurses.h>

Projectile::Projectile() : _null(true) {}

Projectile::Projectile(int pox, int posY,  int direction)
	: _posX(pox), _posY(posY), _direction(direction), _null(true) {
    this->spawn();
}

Projectile::Projectile(Projectile const &src) {
    *this = src;
}

Projectile &Projectile::operator=(Projectile const &rhs) {
    if(this != &rhs){
        this->setPosYX(rhs.getPosY(), rhs.getPosX());
        this->setDirection(rhs.getDirection());
        this->setNull(rhs.isNull());
        this->setSpeed(rhs.getSpeed());
        this->setType(rhs.isType());
    }
    return *this;
}

Projectile::~Projectile() {
}

int Projectile::getPosX() const {
    return this->_posX;
}

void Projectile::setPosX(int posX) {
    this->_posX = posX;
}

int Projectile::getPosY() const {
    return this->_posY;
}

void Projectile::setPosY(int posY) {
    this->_posY = posY;
}

void Projectile::setPosYX(int posY, int posX) {
    this->setPosY(posY);
    this->setPosX(posX);
}

void Projectile::update() {

	this->setPosY(this->getPosY() + (this->_speed * this->getDirection()));
}

int Projectile::getDirection() const {
    return _direction;
}

void Projectile::setDirection(int direction) {
    _direction = direction;
}

void Projectile::spawn() const {
    this->draw();
}

bool Projectile::isNull() const {
    return this->_null;
}

void Projectile::setNull(bool null) {
    this->_null = null;
}

int Projectile::getSpeed() const {
    return this->_speed;
}

void Projectile::setSpeed(int speed) {
    this->_speed = speed;
}

void Projectile::draw() const {
	attron(COLOR_PAIR(3));
    mvprintw(this->getPosY(), this->getPosX(), "o");
	attroff(COLOR_PAIR(3));
}

bool Projectile::isType() const {
    return _type;
}

void Projectile::setType(bool type) {
    _type = type;
}

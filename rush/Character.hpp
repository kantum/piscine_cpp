#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#define N_PROJ 20

#include <ncurses.h>
#include "Projectile.hpp"

class Character {
public:
    Character(int posY, int posX, int life);

    Character(int posY, int posX);

    Character();
    Character( Character const &src );
    Character   &operator=( Character const &rhs);

    virtual ~Character();

    int getPosY() const;
    void setPosY(int posY);
    int getColor() const;
    void setColor(int color);
    int getSpeed() const;
    void setSpeed(int speed);
    void setPosYX(int posY, int posX);
    int getPosX() const;
    void setPosX(int posX);
    int getLife() const;
    void setLife(int life);

    void moveUp(void);
    void moveDown(void);
    void moveRight(void);
    void moveLeft(void);

    virtual void fire(Projectile &p) ;

    void    explode();

protected:
    int _posY;
    int _posX;
    int _life;
    int _speed;
    int _color;
};


#endif

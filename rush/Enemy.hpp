
#ifndef ENEMY_HPP
#define ENEMY_HPP


#include "Character.hpp"

class Enemy : public Character {
public:
    Enemy(int posY, int posX);
    Enemy();
    Enemy( Enemy const &src );
    Enemy   &operator=( Enemy const &rhs);

    virtual ~Enemy();

    void fire(Projectile &p);

    void    rdmyx();

};


#endif

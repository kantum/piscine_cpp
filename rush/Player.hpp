#ifndef CPPR00_PLAYER_HPP
#define CPPR00_PLAYER_HPP


#include "Character.hpp"

class Player : public Character {
public:
    Player();
    Player( Player const &src);
    Player  &operator=( Player const &rhs);
    Player(int posY, int posX);

    virtual ~Player();

    void fire(Projectile &p);


};


#endif
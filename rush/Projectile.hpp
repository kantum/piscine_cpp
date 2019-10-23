#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#define DIR_UP -1
#define DIR_DOWN 1


class Projectile {
public:
    Projectile();
    Projectile(Projectile const &src);
    Projectile  &operator=(Projectile const &rhs);
    virtual ~Projectile();

    Projectile(int pox, int posY, int direction);

    int			getPosX() const;
    void		setPosX(int pox);
    int			getPosY() const;
    void		setPosY(int posY);
    void		setPosYX(int posY, int posX);
    void		update();
    int			getDirection() const;
    void		setDirection(int direction);
    void		spawn() const;
    void		draw() const;
    bool		isNull() const;
    void		setNull(bool null);
    int			getSpeed() const;
    void		setSpeed(int speed);

    bool isType() const;

    void setType(bool type);

private:

    int			_posX;
    int			_posY;
    int			_direction;
    bool		_null;
	int			_speed;
	bool        _type;

};


#endif

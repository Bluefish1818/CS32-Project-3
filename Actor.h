#ifndef ACTOR_H_
#define ACTOR_H_

#include <string>
#include <list>
#include <vector>

#include "GraphObject.h"
// #include "StudentWorld.h"
class StudentWorld;

using namespace std;

class Valentine : public GraphObject
{
  public:
    Valentine(StudentWorld* sw, int x, int y);
    virtual void doSomething();

  private:
    StudentWorld* m_world;
};


class Actor : public GraphObject
{
public:
    Actor::Actor(StudentWorld* sw, int id, int x, int y)
        : GraphObject(id, x, y), m_world(sw), m_posX(x), m_posY(y), m_objectID(id), m_alive(true)
    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() {};

    virtual ~Actor() {}

    StudentWorld*   getWorld() const { return m_world; }
    int             getID() const { return m_objectID; }
    int             getPosX() const { return m_posX; }
    int             getPosY() const { return m_posY; }
    bool            getAlive() const { return m_alive; }



    void setPos(int x, int y) { m_posX = x; m_posY = y; }
    void setAlive(bool AliveState) { m_alive = AliveState; }


    virtual bool isPushable() { return false; }

    bool checkAndMove(int dir);

    bool firePea();


private:
    const int action = 5;
    bool m_alive;
    int m_objectID;
    int m_posX;
    int m_posY;
    StudentWorld* m_world;
};


class Collidable : public Actor
{
public:
    Collidable::Collidable(StudentWorld* sw, int id, int x, int y)
        : Actor(sw, id, x, y)
    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    bool isPushable() { return true; }
    virtual void doSomething() {}

private:

};


class Player : public Collidable
{
public:
    Player::Player(StudentWorld* sw, int id, int x, int y)
        : Collidable(sw,IID_PLAYER,x,y), m_health(20), m_peas(20)
    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething();
    //virtual void shootPea();
    virtual ~Player() {};

    virtual int getHealth() const { return m_health; }
    virtual int getPeas()   const { return m_peas; }
private:
    int m_health;
    int m_peas;
};


class Robot : public Collidable
{
public:
    Robot::Robot(StudentWorld* sw, int id, int x, int y)
        : Collidable(sw, id, x, y), m_value(0), m_health(0)
    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() {};
    virtual int getValue() const { return m_value; }
    virtual bool isRobot() { return true; }
    virtual ~Robot() {};
private:
    int m_value;
    int m_health;
};

// RageBot
// ThiefBots

class VerticalRageBot : public Robot
{
public:
    VerticalRageBot::VerticalRageBot(StudentWorld* sw, int id, int x, int y)
        : Robot(sw, IID_RAGEBOT, x, y), dir(right)
    {
        setVisible(true);
        setDirection(dir);
    }
    virtual void doSomething() {};
    /*void doSomething()
    {
        If the player is in my line of sight, then
            Fire my pea cannon in the direction of the player
            Else if I can move in my current direction w / o hitting an obstacle, then
            Move one square in my current direction
            Else if I’m about to run into an obstacle, then
            Reverse my direction, but don’t move during this tick
    }
    ...*/
private:
    int dir;
};

class HorizontalRageBot : public Robot
{
public:

    void doSomething() {}
    HorizontalRageBot::HorizontalRageBot(StudentWorld* sw, int id, int x, int y)
        : Robot(sw, IID_RAGEBOT, x, y), dir(up)
    {
        setVisible(true);
        setDirection(dir);
    }
    /*void doSomething()
    {
        If the player is in my line of sight, then
            Fire my pea cannon in the direction of the player
            Else if I can move in my current direction w / o hitting an obstacle, then
            Move one square in my current direction
            Else if I’m about to run into an obstacle, then
            Reverse my direction, but don’t move during this tick
    }
    ...*/
private:
    int dir;
};

class ThiefBot : public Robot
{
public:
    void doSomething() {}
    ThiefBot::ThiefBot(StudentWorld* sw, int id, int x, int y)
        : Robot(sw, IID_THIEFBOT, x, y)
    {
        setVisible(true);
    }
private:

};


class MeanThiefBot : public ThiefBot
{
public:
    virtual void doSomething() {}
    MeanThiefBot::MeanThiefBot(StudentWorld* sw, int id, int x, int y)
        : ThiefBot(sw, IID_MEAN_THIEFBOT, x, y)
    {
        setVisible(true);
    }
private:

};

class Goodie : public Actor
{
public:
    virtual void doSomething() {}
    Goodie::Goodie(StudentWorld* sw, int id, int x, int y)
        : Actor(sw, id, x, y)
    {
        setVisible(true);
    }
    virtual bool isGoodie() { return true; }
private:

};

class RestoreHealthGoodie : public Goodie
{
public:
    RestoreHealthGoodie::RestoreHealthGoodie(StudentWorld* sw, int id, int x, int y)
        : Goodie(sw, IID_RESTORE_HEALTH, x, y)
    {
        setVisible(true);
    }
private:

};
// HealthGoodie

class AmmoGoodie : public Goodie
{
public:
    AmmoGoodie::AmmoGoodie(StudentWorld* sw, int id, int x, int y)
        : Goodie(sw, IID_AMMO, x, y)
    {
        setVisible(true);
    }
    void doSomething() {}

private:

};
// AmmoGoodie

class ExtraLifeGoodie : public Goodie
{
public:
    ExtraLifeGoodie::ExtraLifeGoodie(StudentWorld* sw, int id, int x, int y)
        : Goodie(sw, IID_EXTRA_LIFE, x, y)
    {
        setVisible(true);
    }
    void doSomething() {}
private:

};

class Pit : public Collidable
{
public:

    Pit::Pit(StudentWorld* sw, int id, int x, int y)
        : Collidable(sw, IID_PIT, x, y)
    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    void doSomething() {}
};

// Wall
class Wall : public Collidable
{
public:
    Wall::Wall(StudentWorld* sw, int id, int x, int y)
        : Collidable(sw, IID_WALL, x, y)
    {
        setVisible(true);
        setDirection(left);
        // TESTING!!!!!!!!!!!
    }
    void doSomething() { firePea(); }
private:

};
// Pits

class Marble : public Collidable
{
public:
    Marble::Marble(StudentWorld* sw, int id, int x, int y)
        : Collidable(sw, IID_MARBLE, x, y)

    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() {}
private:

};

class ThiefBotFactory : public Collidable
{
public:

    ThiefBotFactory::ThiefBotFactory(StudentWorld* sw, int id, int x, int y)
        : Collidable(sw, IID_ROBOT_FACTORY, x, y)

    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() {}
private:

};

//MeanThiefBotFactory

class MeanThiefBotFactory : public ThiefBotFactory
{
public:
    
    MeanThiefBotFactory::MeanThiefBotFactory(StudentWorld* sw, int id, int x, int y)
        : ThiefBotFactory(sw, IID_ROBOT_FACTORY, x, y)
    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() {}
private:

};
class Exit : public Goodie
{
public:
    Exit::Exit(StudentWorld* sw, int id, int x, int y)
        : Goodie(sw, IID_EXIT, x, y)

    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() {}
private:

};

class Crystal : public Goodie
{
public:

    Crystal::Crystal(StudentWorld* sw, int id, int x, int y)
        : Goodie(sw, IID_CRYSTAL, x, y)

    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() {}
};

class Projectile : public Actor
{
public:
    Projectile::Projectile(StudentWorld* sw, int id, int x, int y)
        : Actor(sw, id, x, y)

    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() {}
private:

};



class Pea : public Projectile
{
public:
    Pea::Pea(StudentWorld* sw, int id, int dir, int x, int y)
        : Projectile(sw, IID_PEA, x, y), m_direction(dir)
    {
        setVisible(true);

    }
    virtual void doSomething();
    int getPeaDir() const { return m_direction; }
private:
    int m_direction;
};
#endif // ACTOR_H_

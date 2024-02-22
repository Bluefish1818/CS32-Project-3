#ifndef ACTOR_H_
#define ACTOR_H_


#include "GraphObject.h"
#include "StudentWorld.h"

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
        : GraphObject(id, x, y), m_world(sw), m_posX(x), m_posY(y), m_objectID(id)
    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() = 0;

    virtual ~Actor() {}

    StudentWorld*   getWorld() const { return m_world; }
    int             getID() const { return m_objectID; }
    int             getPosX() const { return m_posX; }
    int             getPosY() const { return m_posY; }
    bool            getAlive() const { return m_alive; }
    Actor*          getActorAtPoint(int x, int y) const;


private:
    bool m_alive = true;
    int m_objectID;
    int m_posX;
    int m_posY;
    StudentWorld* m_world;
};


class Damagable : public Actor
{
public:

private:
    int m_health;
};

class Player : public Actor
{
public:
    Player::Player(StudentWorld* sw, int id, int x, int y)
        : Actor(sw,IID_PLAYER,x,y), m_health(20), m_peas(20)
    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething();
    //virtual void shootPea();
    virtual ~Player() {};

    int getHealth() const { return m_health; }
    int getPeas()   const { return m_peas; }
private:
    int m_health;
    int m_peas;
};

class Robot : public Actor
{
public:
    int getValue() const { return m_value; }
    virtual ~Robot() {};
private:
    int m_value;
};

// RageBot
// ThiefBots

class RageBot : public Robot
{
public:
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
};



class Goodie : public Actor
{
public:

private:

};

class HealthGoodie : public Goodie
{
public:

private:

};
// HealthGoodie

class AmmoGoodie : public Goodie
{
public:

private:

};
// AmmoGoodie

class Environment : public Actor
{
public:
    Environment::Environment(StudentWorld* sw, int id, int x, int y)
        : Actor(sw, id, x, y)

    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() {}
private:

};

// Wall
class Wall : public Environment
{
public:
    Wall::Wall(StudentWorld* sw, int id, int x, int y)
        : Environment(sw, IID_WALL, x, y)

    {
        setVisible(true);
        // TESTING!!!!!!!!!!!
    }
    virtual void doSomething() {}
private:

};
// Pits

class Interactable : public Environment
{
public:

private:

};

class Immovable : public Environment
{
public:

private:

};

class RobotFactory : public Environment
{
public:

private:

};
#endif // ACTOR_H_

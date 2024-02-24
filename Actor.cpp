#include <list>
#include "Actor.h"
#include "StudentWorld.h"
#include "GameConstants.h"

using namespace std;

// VALENTINE OBJECT (FROM SKELETON)
Valentine::Valentine(StudentWorld* sw, int x, int y)
 : GraphObject(IID_EXTRA_LIFE, x, y), m_world(sw)
{
}

void Valentine::doSomething()
{
    int key;
    if (m_world->getKey(key))
    {
        if (key == KEY_PRESS_ENTER)
        	m_world->playSound(SOUND_GOT_GOODIE);
    }
}

void Player::doSomething()
{
    int key;
    if (getWorld()->getKey(key))
    {
        setPos(getX(), getY());
        if (key == KEY_PRESS_UP || key == 'w' || key == '8')
        {

            setDirection(up);
            if (!(getWorld()->isCollidable(getX(), getY() + 1)))
            {
                moveTo(getX(), getY() + 1);
                setPos(getX(), getY() + 1);
                
            }
            
        }
        if (key == KEY_PRESS_RIGHT || key == 'd' || key == '6')
        {
            setDirection(right);
            if (!(getWorld()->isCollidable(getX() + 1, getY())))
            {
                moveTo(getX() + 1, getY());
                setPos(getX() + 1, getY());
            }

        }
        if (key == KEY_PRESS_DOWN || key == 's' || key == '5')
        {
            setDirection(down);
            if (!(getWorld()->isCollidable(getX(), getY() - 1)))
            {
                moveTo(getX(), getY() - 1);
                setPos(getX(), getY() - 1);
            }

        }
        if (key == KEY_PRESS_LEFT || key == 'a' || key == '4')
        {
            setDirection(left);
            if (!(getWorld()->isCollidable(getX() - 1, getY())))
            {
                moveTo(getX() - 1, getY());
                setPos(getX() - 1, getY());
            }
        }
        if (key == KEY_PRESS_SPACE && m_peas > 0)
        {
            getWorld()->playSound(SOUND_PLAYER_FIRE);
            firePea();
            m_peas--;
        }
    }
}

bool Actor::checkAndMove(int dir)
{
    if (m_alive)
    {
        setPos(getX(), getY());
        if (dir == up)
        {
            setDirection(up);
            if (!(getWorld()->isCollidable(getX(), getY() + 1)))
            {
                moveTo(getX(), getY() + 1);
                setPos(getX(), getY() + 1);
                return true;
            }
            return false;

        }
        if (dir == right)
        {
            setDirection(right);
            if (!(getWorld()->isCollidable(getX() + 1, getY())))
            {
                moveTo(getX() + 1, getY());
                setPos(getX() + 1, getY());
                return true;
            }
            return false;

        }
        if (dir == down)
        {
            setDirection(down);
            if (!(getWorld()->isCollidable(getX(), getY() - 1)))
            {
                moveTo(getX(), getY() - 1);
                setPos(getX(), getY() - 1);
                return true;
            }
            return false;

        }
        if (dir == left)
        {
            setDirection(left);
            if (!(getWorld()->isCollidable(getX() - 1, getY())))
            {
                moveTo(getX() - 1, getY());
                setPos(getX() - 1, getY());
                return true;
            }
            return false;

        }
        if (dir == action)
        {
            firePea();
            getWorld()->playSound(SOUND_PLAYER_FIRE);
        }
    }
}


void Pea::doSomething()
{
    if (!(getWorld()->isCollidable(getX(), getY())))
    {
        checkAndMove(getPeaDir());
    }
    else
    {
        setAlive(false);
        setVisible(false);
    }
    
}

bool Actor::firePea()
{
    int dir = getDirection();
    int x = getPosX();
    int y = getPosY();


    if (dir == up)
    {
        getWorld()->createPea(m_world, dir, x, y + 1);
        return true;
    }
    else if (dir == right)
    {
        getWorld()->createPea(m_world, dir, x + 1, y);
        return true;
    }
    else if (dir == down)
    {
        getWorld()->createPea(m_world, dir, x, y - 1);
        return true;
    }
    else if (dir == left)
    {
        getWorld()->createPea(m_world, dir, x - 1, y);
        return true;
    }
    return false;
}
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
        if (key == KEY_PRESS_UP || key == 'w' || key == '8')
        {
            setDirection(up);
            moveTo(getX(), getY() + 1);
            
        }
        if (key == KEY_PRESS_RIGHT || key == 'd' || key == '6')
        {
            setDirection(right);
            moveTo(getX() + 1, getY());

        }
        if (key == KEY_PRESS_DOWN || key == 's' || key == '5')
        {
            setDirection(down);
            moveTo(getX(), getY() - 1);

        }
        if (key == KEY_PRESS_LEFT || key == 'a' || key == '4')
        {
            setDirection(left);
            moveTo(getX() - 1, getY());
        }
        if (key == KEY_PRESS_SPACE)
        {
            getWorld()->playSound(SOUND_PLAYER_FIRE);
            
        }
    }
}




Actor* Actor::getActorAtPoint(int x, int y) const
{
    list<Actor*>::iterator it;
    
    return nullptr;
}

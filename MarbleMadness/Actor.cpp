#include "Actor.h"
#include "StudentWorld.h"


// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

void Avatar::doSomething()
{
    int key;
    if (getWorld()->getKey(key))
    {
        switch (key)
        {
            case KEY_PRESS_LEFT:
                setDirection(left);
                if(getWorld()->canWalk(getX()-1, getY()))
                    moveTo(getX()-1, getY());
                break;
            case KEY_PRESS_RIGHT:
                setDirection(right);
                if(getWorld()->canWalk(getX()+1, getY()))
                    moveTo(getX()+1, getY());
                break;
            case KEY_PRESS_UP:
                setDirection(up);
                if(getWorld()->canWalk(getX(), getY()+1))
                    moveTo(getX(), getY()+1);
                break;
            case KEY_PRESS_DOWN:
                setDirection(down);
                if(getWorld()->canWalk(getX(), getY()-1))
                    moveTo(getX(), getY()-1);
                break;
        }
    }
}

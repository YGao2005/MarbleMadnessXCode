#include "Actor.h"
#include "StudentWorld.h"


// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp

void Avatar::doSomething() {
    int key;
    if (getWorld()->getKey(key)) {
        switch (key) {
            case KEY_PRESS_LEFT:
                setDirection(left);
                if (getWorld()->canWalk(getX() - 1, getY()))
                    moveTo(getX() - 1, getY());
                break;
            case KEY_PRESS_RIGHT:
                setDirection(right);
                if (getWorld()->canWalk(getX() + 1, getY()))
                    moveTo(getX() + 1, getY());
                break;
            case KEY_PRESS_UP:
                setDirection(up);
                if (getWorld()->canWalk(getX(), getY() + 1))
                    moveTo(getX(), getY() + 1);
                break;
            case KEY_PRESS_DOWN:
                setDirection(down);
                if (getWorld()->canWalk(getX(), getY() - 1))
                    moveTo(getX(), getY() - 1);
                break;
        }
    }
}

void Crystal::doSomething() {
    if (getCollected()) {
        return;
    }
    if (getWorld()->getAvatar()->getX() == getX() && getWorld()->getAvatar()->getY() == getY()) {
            setCollected(true);
            setVisible(false);
            getWorld()->playSound(SOUND_GOT_GOODIE);
            getWorld()->increaseScore(50);
            getWorld()->decCrystals();
    }
}

void Exit::doSomething() {
    if (!isVisible() && getWorld()->getCrystals() == 0) {
        setVisible(true);
        getWorld()->playSound(SOUND_REVEAL_EXIT);
    }
}

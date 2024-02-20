#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
//functions I can use
//GraphObject(int imageID, int startX, int startY, Direction startDirection = none);
//void setVisible(bool shouldIDisplay);
//double getX() const;
//double getY() const;
//void moveTo(double x, double y);
//Direction getDirection() const; // Directions: none, up, down, left, right
//void setDirection(Direction d); // Directions: none, up, down, left, right
class StudentWorld;

class Actor : public GraphObject
{
public:
    Actor(int imageID, double startX, double startY, int startDirection, StudentWorld* world, bool isTangible)
        : GraphObject(imageID, startX, startY, startDirection), m_world(world), m_tangible(isTangible)
    {
        setVisible(true);
    }
    //required by specs
    virtual void doSomething() = 0;
    bool getTangible() const { return m_tangible; }

    //for my use
    StudentWorld* getWorld() { return m_world; }
private:
    StudentWorld* m_world;
    bool m_tangible;
};

class Wall : public Actor
{
public:
    Wall(double startX, double startY, StudentWorld* world) : Actor(IID_WALL, startX, startY, none, world, true) {
        setVisible(true);
    }
    virtual void doSomething() {}
};


class Avatar : public Actor
{
public:
    Avatar(double startX, double startY, StudentWorld *world) : Actor(IID_PLAYER, startX, startY, right, world, false) {}
    virtual void doSomething();

};

#endif // ACTOR_H_

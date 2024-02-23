#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Level.h"
#include "Actor.h"
#include <string>
#include <list>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
  StudentWorld(std::string assetPath);
  ~StudentWorld();
  virtual int init();
  virtual int move();
  virtual void cleanUp();
  bool canWalk(int x, int y);
  Actor *getAvatar();
  void decCrystals();
  int getCrystals() { return m_crystals; }

private:
    std::list<Actor*> m_actors;
    Avatar* m_avatar;
    int m_crystals;
    int endX;
    int endY;
};

#endif // STUDENTWORLD_H_

#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
    return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
    m_crystals = 0;
    m_avatar = nullptr;
}

int StudentWorld::init()
{
    Level lev(assetPath());
    ostringstream oss;
    oss << "level" << setw(2) << setfill('0') << getLevel();
    string levelFile = oss.str() + ".txt";
    Level::LoadResult result = lev.loadLevel(levelFile);
    if (result == Level::load_fail_file_not_found || getLevel() == 99)
    {
        return GWSTATUS_PLAYER_WON;
    }
    else if (result == Level::load_fail_bad_format)
    {
        return GWSTATUS_LEVEL_ERROR;
    }
    else if (result == Level::load_success)
    {
        cerr << "Successfully loaded level" << endl;
    }

    for(int x = 0; x < VIEW_WIDTH; x++)
    {
        for(int y = 0; y < VIEW_HEIGHT; y++)
        {
            Level::MazeEntry item = lev.getContentsOf(x, y);
            switch(item)
            {
                case Level::empty:
                    break;
                case Level::exit:
                    m_actors.push_front(new Exit(x, y, this));
                    endX = x;
                    endY = y;
                    break;
                case Level::player:
                    if(m_avatar == nullptr)
                        m_avatar = new Avatar(x, y, this);
                    break;
                case Level::horiz_ragebot:
                    break;
                case Level::vert_ragebot:
                    break;
                case Level::thiefbot_factory:
                    break;
                case Level::mean_thiefbot_factory:
                    break;
                case Level::wall:
                    m_actors.push_front(new Wall(x, y, this));
                    break;
                case Level::marble:
                    break;
                case Level::pit:
                    break;
                case Level::crystal:
                    m_actors.push_front(new Crystal(x, y, this));
                    m_crystals++;
                    break;
                case Level::restore_health:
                    break;
                case Level::extra_life:
                    break;
                case Level::ammo:
                    break;
            }
        }
    }

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you type q

    setGameStatText("Game will end when you type q");
    if (m_avatar != nullptr)
        m_avatar->doSomething();
    for(auto & m_actor : m_actors)
    {
        m_actor->doSomething();
    }
    if (getAvatar()->getX() == endX && getAvatar()->getY() == endY && getCrystals() == 0) {
        playSound(SOUND_FINISHED_LEVEL);
        increaseScore(2000);
        return GWSTATUS_FINISHED_LEVEL;
    }
    return GWSTATUS_CONTINUE_GAME;
}

StudentWorld::~StudentWorld()
{
    StudentWorld::cleanUp();
}

void StudentWorld::cleanUp()
{

    if(m_avatar != nullptr){
        delete m_avatar;
        m_avatar = nullptr;
    }

    for(auto & m_actor : m_actors)
    {
        delete m_actor;
    }
    m_actors.clear();
}

bool StudentWorld::canWalk(int x, int y)
{
    for(auto & m_actor : m_actors)
    {
        if(m_actor->getX() == x && m_actor->getY() == y && m_actor->getTangible())
        {
            return false;
        }
    }
    return true;
}

Actor *StudentWorld::getAvatar()
{
    return m_avatar;
}

void StudentWorld::decCrystals()
{
    m_crystals--;
}

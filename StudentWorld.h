#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Level.h"
#include "Actor.h"
#include <list>
#include <string>
#include <vector>

class Wall;
class Valentine;
class Player;

class StudentWorld : public GameWorld
{
public:
	  StudentWorld(std::string assetPath);
	  //~StudentWorld();

	  virtual int init();
	  virtual int move();
	  virtual void cleanUp();
	  virtual int renderLevel(string level);

	  // virtual void read();
	  /*
	  unsigned int getLevel() const;
	  unsigned int getLives() const;
	  void decLives();
	  void incLives();
	  unsigned int getScore() const;
	  void increaseScore(unsigned int howMuch);
	  void setGameStatText(string text);
	  string assetPath() const;
	  bool getKey(int& value);
	  void playSound(int soundID);
	  */

	  void createWall(StudentWorld* world,int x, int y) { totalActors.std::push_back(Wall(world,IID_WALL,x, y)); }


private:
	  // Valentine* m_valentine;
	  Player* m_player;
	  Wall* m_wall;
	  StudentWorld* m_world;
	  std::vector<Actor*> totalActors;
};


#endif // STUDENTWORLD_H_

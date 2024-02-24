#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Level.h"
#include "Actor.h" // Circular Dependancy!!!
#include "GraphObject.h"
#include "GameConstants.h"

#include <list>
#include <string>
#include <vector>

using namespace std;

class StudentWorld : public GameWorld
{
public:
	  StudentWorld(std::string assetPath);
	  //~StudentWorld();

	  virtual int init();
	  virtual int move();
	  virtual void cleanUp();

	  virtual int renderLevel(string level, StudentWorld* world);

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
	  //std::vector<Actor*> getActorList() { return totalActors; }
	  bool isCollidable(int x, int y) const
	  {
		  for (int i = 0; i < totalActors.size(); i++) {
			  if (totalActors[i]->getPosX() == x && totalActors[i]->getPosY() == y)
			  {
				  return totalActors[i]->isPushable();
			  }
		  }
		  return false;
	  }


	  void createWall					(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_wall = new Wall		(world,IID_WALL,x, y)); }
	  void createPlayer					(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_player = new Player	(world, IID_PLAYER, x, y)); }
	  void createMarble					(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_marble = new Marble	(world, IID_MARBLE, x, y)); }
	  void createVerticalRageBot		(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new VerticalRageBot		(world, IID_RAGEBOT, x, y)); }
	  void createHorizontalRageBot		(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new HorizontalRageBot	(world, IID_RAGEBOT, x, y)); }
	  void createThiefBot				(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new ThiefBot				(world, IID_THIEFBOT, x, y)); }
	  void createMeanThiefBot			(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new MeanThiefBot			(world, IID_MEAN_THIEFBOT, x, y)); }
	  void createThiefBotFactory		(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new ThiefBotFactory		(world, IID_ROBOT_FACTORY, x, y)); }
	  void createMeanThiefBotFactory	(StudentWorld* world, int x, int y) { totalActors.push_back(m_actors = new MeanThiefBotFactory		(world, IID_ROBOT_FACTORY, x, y)); }
	  void createAmmoGoodie				(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new AmmoGoodie			(world, IID_AMMO, x, y)); }
	  void createRestoreHealthGoodie	(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new RestoreHealthGoodie	(world, IID_RESTORE_HEALTH, x, y)); }
	  void createExtraLifeGoodie		(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new ExtraLifeGoodie		(world, IID_EXTRA_LIFE, x, y)); }
	  void createPit					(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new Pit		(world, IID_PIT, x, y)); }
	  void createExit					(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new Exit		(world, IID_EXIT, x, y)); }
	  void createPea					(StudentWorld* world, int dir, int x, int y)	{ totalActors.push_back(m_peas = new Pea		(world, IID_PEA, dir, x, y)); }
	  void createCrystal				(StudentWorld* world, int x, int y)	{ totalActors.push_back(m_actors = new Crystal	(world, IID_CRYSTAL, x, y)); }

private:
	  // Valentine* m_valentine;
	  Player* m_player;
	  Wall* m_wall;
	  Marble* m_marble;
	  Actor* m_actors;
	  Pea* m_peas;
	  StudentWorld* m_world;
	  std::vector<Pea*> totalPeas;
	  std::vector<Actor*> totalActors;
};


#endif // STUDENTWORLD_H_

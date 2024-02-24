#include "StudentWorld.h"
#include "Actor.h"
#include "GameConstants.h"
#include "Level.h"

#include <list>
#include <string>
#include <vector>

using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
    return new StudentWorld(assetPath);
}

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath), m_world(this)
{
}

int StudentWorld::renderLevel(string level, StudentWorld* world)
{
	string curLevel = level;
	Level lev(assetPath());
	Level::LoadResult result = lev.loadLevel(curLevel);
	if (result == Level::load_fail_file_not_found ||
		result == Level::load_fail_bad_format)
		return -1; // something bad happened!
	// otherwise the load was successful and you can access the
	// contents of the level – here’s an example 
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			Level::MazeEntry item = lev.getContentsOf(x, y);

			if (item == Level::player)
			{
				createPlayer(world, x, y);
			}
			else if (item == Level::wall)
			{
				createWall(world, x, y);
			}
			else if (item == Level::marble)
			{
				createMarble(world, x, y);
			}
			else if (item == Level::ammo)
			{
				createAmmoGoodie(this, x, y);
			}
			else if (item == Level::extra_life)
			{
				createExtraLifeGoodie(this, x, y);
			}
			else if (item == Level::restore_health)
			{
				createRestoreHealthGoodie(this, x, y);
			}
			else if (item == Level::mean_thiefbot_factory)
			{
				createMeanThiefBotFactory(world, x, y);
			}
			else if (item == Level::thiefbot_factory)
			{
				createThiefBotFactory(world, x, y);
			}
			else if (item == Level::exit)
			{
				createExit(world, x, y);
			}
			else if (item == Level::pit)
			{
				createPit(world, x, y);
			}
			else if (item == Level::crystal)
			{
				createCrystal(world, x, y);
			}
			else if (item == Level::horiz_ragebot)
			{
				createVerticalRageBot(world, x, y);
			}
			else if (item == Level::vert_ragebot)
			{
				createHorizontalRageBot(world, x, y);
			}
			//else if (item == Level::)
			//{
			//	create(world, x, y);
			//}
		}
	}


	return 0;
}

int StudentWorld::init()
{
	


	renderLevel("level03.txt", this);
	//----------------------------
	// m_valentine = new Valentine(this, VIEW_WIDTH/2, VIEW_HEIGHT/2);
	// m_player = new Player(this, IID_PLAYER , 3, 3);
	// m_wall = new Wall(this, IID_WALL, 3, 3);
	//

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
	// Are you only allowed to control one thing here????
	//m_valentine->doSomething();
	//m_player->doSomething();
	//m_wall->doSomething();
	//m_peas->doSomething();
	//m_actors->doSomething();


    return GWSTATUS_CONTINUE_GAME;
}

void purgeDead(list<Actor*> li)
{
	int length = li.size();
	for (int i = 0; i < length; i++)
	{
		if (!(li.back()->getAlive()))
		{
			li.pop_back();
		}
		else
		{
			li.push_front(li.back());
			li.pop_back();
		}
	}
}

void StudentWorld::cleanUp()
{
	int iActors = totalActors.size();
	for (int i = 0; i < iActors; i++)
	{
		//totalActors.pop_back();
		delete totalActors[i];
	}

	int iPeas = totalPeas.size();
	for (int n = 0; n < iPeas; n++)
	{
		delete totalPeas[n];
	}

}




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
: GameWorld(assetPath)
{
}

int StudentWorld::renderLevel(string level)
{
	string curLevel = level;
	Level lev(assetPath());
	Level::LoadResult result = lev.loadLevel(curLevel);
	if (result == Level::load_fail_file_not_found ||
		result == Level::load_fail_bad_format)
		return -1; // something bad happened!
	// otherwise the load was successful and you can access the
	// contents of the level – here’s an example 
	int x = 0;
	int y = 5;
	Level::MazeEntry item = lev.getContentsOf(x, y);
	if (item == Level::player)
		cout << "The player should be placed at 0,5 in the maze\n";
	x = 10;
	y = 7;

	item = lev.getContentsOf(x, y);
	if (item == Level::wall)
	{
		//cout << "There should be a wall at 10,7 in the maze\n:";
		
	}
	// etc
	return 0;
}

int StudentWorld::init()
{
	



	//----------------------------
	// m_valentine = new Valentine(this, VIEW_WIDTH/2, VIEW_HEIGHT/2);
	m_player = new Player(this, IID_PLAYER , 3, 3);
	m_wall = new Wall(this, IID_WALL, 3, 3);
	

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
	// Are you only allowed to control one thing here????
	//m_valentine->doSomething();
	m_player->doSomething();
	//m_wall->doSomething();
    return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
	int iActors = totalActors.size();
	for (int i = 0; i < iActors; i++)
	{
		totalActors.pop_back();
	}
	delete m_player;
	delete m_wall;
}

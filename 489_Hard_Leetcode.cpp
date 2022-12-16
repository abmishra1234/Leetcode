using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>

/*
    Complete this driver code as earliest as possible.
*/
//#define FORREF
#ifndef FORREF

// the below chunk is for movement
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };


class Robot {
public:
    int maxR, maxC;// Number of rows and cols in grid
    vector<vector<int>> room; // this si the room divided into grid form of cells
    vector<vector<bool>> visited; // this si the room divided into grid form of cells

    int currRow, currCol; // this is for starting the robot move 
    int dir; // this is for moving direction

    // the below chunk is for movement
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    // To maintain the freecell count covered or not?
    int freecellcnt;

    /*
        Completed but not verified the logic with dry run
    */
    bool valid(int x, int y) {
        if (x < 0 || x >= maxR) return false;
        if (y < 0 || y >= maxC) return false;

        return true;
    }

    /*
        Completed but not verified the logic with dry run
    */
    bool move() {
        int x = currRow + dx[dir];
        int y = currCol + dy[dir];

        if (!valid(x, y)) return false;
        if (!room[x][y]) return false;
        if (visited[x][y]) return false;
        
        currRow = x;
        currCol = y;
               
        return true;
    }
    /*
        Completed but not verified the logic with dry run
    */
    void clean() {
        // If already clean than don't don any thing just return
        if (!visited[currRow][currCol]) {
            --freecellcnt;
            visited[currRow][currCol] = 1;
        }
        else
            cout << "Cell is already cleaned so return without doing any thing..." << endl;
    }
    /*
        Completed but not verified the logic with dry run
    */
    void turnRight() {
        // turn right is clockwise move ment
        dir = (dir + 1) % 4;
    }
    /*
        Completed but not verified the logic with dry run
    */
    void turnLeft() {
        dir = ((dir - 1) < 0) ? ((dir - 1) + 4) : dir - 1;
    }
};

typedef pair<int, int> pii;
struct MyHash {
    auto operator()(const pii& p) const {
        return std::hash<int>{}(p.first) ^ std::hash<int>{}(p.second);
    }
};
typedef unordered_set<pii, MyHash> MySet;

class Solution {
public:
    Robot* rp;
    MySet visited;

    // the below chunk is for movement
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    void dfs(int x, int y, int dir, MySet& visited, Robot &robot) {
        visited.insert({ x,y });
        robot.clean();

        // check all the 04 direction
        for (int i = 0; i < 4; ++i) {
            int newdir = (dir + i) % 4;
            int newx = x + dx[newdir];
            int newy = y + dy[newdir];

            if (visited.find({ newx, newy }) == visited.end() && robot.move() ) {
                dfs(newx, newy, dir, visited, robot);
            }
            robot.turnRight();
        }
        // now the next set of call is for backtrack
        robot.turnLeft();
        robot.turnLeft();
        robot.move();
        robot.turnLeft();
        robot.turnLeft();
    }

    void cleanRoom(Robot& robot) {
        rp = &robot;
        visited.clear();

        // Since you are not sure the position from where you will start, so the only
        // Solution to this is backtrack approach
        dfs(0, 0, 0, visited, robot);
    }
};



int main(void)
{
    // Let write some verification test cases below
    vector<vector<int>> grid 
        = { {1,1,1,1,1,0,1,1},{1,1,1,1,1,0,1,1}, 
            {1,0,1,1,1,1,1,1}, {0,0,0,1,0,0,0,0}, 
            {1,1,1,1,1,1,1,1 } };
    int _sr = 1, _sc = 3, _dir = 0;

    Robot* rp = new Robot();
    Solution sln;
    sln.cleanRoom(*rp);
    delete rp;

    return 0;
}

#endif // FORREF
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

// U->R->D->L
int x_dir[4] = { -1, 0, 1, 0 }; 
int y_dir[4] = { 0, 1, 0, -1 };

// for maintaining the direction
// U->R->D->L
int dir[4] = { 0, 1, 2, 3 };

/*
    Complete the Driver code later.
*/
class Robot {

};

typedef pair<int, int> pii;
#define MP make_pair
class Solution {
public:
    int dx[4] = { 0, -1, 0, 1 };
    int dy[4] = { 1, 0, -1, 0 };

    void moveForward(Robot& robot, int x, int y, int direction, map<pii, bool>& visited) {
        // Try to move forward if possible
        if (!visited[MP(x + dx[direction], y + dy[direction])] && robot.move()) {
            visited[MP(x + dx[direction], y + dy[direction])] = 1;

            // Now do further depth first search
            DFS(robot, x + dx[direction], y + dy[direction], direction, visited);

            // Come back to your position
            robot.turnRight();
            robot.turnRight();
            robot.move();
            robot.turnRight();
            robot.turnRight();
        }
    }

    void DFS(Robot& robot, int x, int y, int direction, map<pii, bool>& visited) {
        // First clean
        robot.clean();

        // Then try moving foward in current direction and all other directions
        // N
        moveForward(robot, x, y, direction, visited);

        // W
        robot.turnRight();
        direction = (direction + 1) % 4;
        moveForward(robot, x, y, direction, visited);

        // S
        robot.turnRight();
        direction = (direction + 1) % 4;
        moveForward(robot, x, y, direction, visited);

        // E
        robot.turnRight();
        direction = (direction + 1) % 4;
        moveForward(robot, x, y, direction, visited);

        // N
        robot.turnRight();
        direction = (direction + 1) % 4;
    }

    void cleanRoom(Robot& robot) {
        map<pii, bool> visited;

        DFS(robot, 0, 0, 0, visited);
    }
};


Solution sln;

int main(void)
{

    return 0;
}

#endif // FORREF
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

//#define FORREF
#ifndef FORREF

int xDir[4] = {0,-1,0,1};
int yDir[4] = {-1,0,1,0};

struct Point {
    int r, c;
    Point(int rx, int cy) {
        r = rx, c = cy;
    }
};

class Solution {
    const int INF = 2147483647;
    queue<Point> pQueue;

public:

    bool valid(int x, int y, const int R, const int C) {
        if (x < 0 || x >= R)
            return false;

        if (y < 0 || y >= C)
            return false;

        return true;

    }

    // Source point is all the cells having gate
    // This method will populate the distance in each empty cell with minimum value from
    // the gate cell
    void bfs(vector<vector<int>>& rooms, int rSrc, int cSrc, vector<vector<int>> &visited) {
        int R = rooms.size();
        int C = rooms[0].size();

        pQueue.push(Point(rSrc, cSrc));
        visited[rSrc][cSrc] = true;
        rooms[rSrc][cSrc] = 0;

        while (pQueue.empty() == false) {

            Point pt = pQueue.front();
            pQueue.pop();

            int x, y;

            for (int i = 0; i < 4; ++i) {
                x = pt.r + xDir[i];
                y = pt.c + yDir[i];

                if (valid(x,y, R, C) && visited[x][y] == false && rooms[x][y] != -1 && rooms[x][y] != 0) {
                    pQueue.push(Point(x, y));
                    visited[x][y] = true;
                    rooms[x][y] = min(rooms[x][y], rooms[pt.r][pt.c] + 1);
                }
            }
        }
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        int R = rooms.size();
        int C = rooms[0].size();

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                vector<vector<int>> visited(R, vector<int>(C, 0));
                if (rooms[i][j] == 0) {
                    bfs(rooms, i, j, visited);
                }
            }
        }
    }
};

int main(void)
{
    vector<vector<int>> rooms = { {2147483647, -1, 0, 2147483647}, {2147483647, 2147483647, 2147483647, -1},
        {2147483647, -1, 2147483647, -1},{0, -1, 2147483647, 2147483647} };

    Solution sln;
    sln.wallsAndGates(rooms);
    return 0;
}

#endif // FORREF
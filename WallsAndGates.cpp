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

#define FORREF
#ifndef FORREF
#define INF 2147483647
/*
    Let's write your code one's again for handling this problem
    @Note or Precaution on the problem
    1. you can put the two source or all the gates into the queue one's
    2. How big and reallocate possibility with your container because
       container reallocation is putting very heavy panelty on performance

    3. Please see , do you really need any special another vising flag here ?
    4. Try to write the code iteratively as much as possible to avoid Stack overflow for system stack and 1MB limitation in Programming platform.
*/
/*
    Assumption here is that from every cell you can move in max 04 direction(L,U,R,D)
    Also, your movement is possible only if the upcoming cell is empty, meaning if it's value is INF
*/
int xr[4] = {0, -1, 0, 1};
int yc[] = {-1, 0, 1, 0};

class Point {
public:
    int r, c;
    Point(int x, int y) {
        r = x, c = y;
    }
};

bool Valid(int x, int y, const int &R, const int &C) {
    if (x < 0 || x >= R) return false;
    if (y < 0 || y >= C) return false;

    return true;
}
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        auto* q = new std::list<Point>();

        int R = rooms.size();
        int C = rooms[0].size();

        // So in below chunk of code, you just have colected all the 
        // gate position from where bfs will start
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (rooms[i][j] == 0) {
                    q->push_back(Point(i, j));
                }
            }
        }

        // iterate it until your queue become empty?
        while (q->empty() == false) {
            Point pt = q->front();
            q->pop_front();

            int x, y;
            for (int i = 0; i < 4; ++i) {
                x = pt.r + xr[i];
                y = pt.c + yc[i];

                if (Valid(x, y, R, C) && rooms[x][y] == INF) {
                    rooms[x][y] = min(rooms[x][y], 1 + rooms[pt.r][pt.c]);
                    q->push_back(Point(x, y));
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
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

// As discussed in the problem, our 04 directions are,
// [ L, U, R, D]
int xDir[4] = {0, -1, 0, 1};
int yDir[4] = { -1, 0, 1, 0 };

class Solution {
protected:
    bool Valid(int x, int y, const int& R, const int& C) {
        if (x < 0 || x >= R) return false;
        if (y < 0 || y >= C) return false;

        return true;
    }

    // Off-course first target is to finish the problem than we will see , can we do it by using the dfs also?
    void bfs(vector<vector<char>>& grid, int xSrc, int ySrc, vector<vector<bool>>& visited) {
        int R = grid.size();
        int C = grid[0].size();

        queue<pair<int, int>> q;
        q.push({ xSrc, ySrc });
        visited[xSrc][ySrc] = true;

        while (q.empty() == false) {
            pair<int, int> p = q.front();
            q.pop();

            int x, y;
            for (int i = 0; i < 4; ++i) {
                x = p.first + xDir[i];
                y = p.second + yDir[i];

                if (Valid(x, y, R, C) && visited[x][y] == false && grid[x][y] == '1') {
                    q.push({ x,y });
                    visited[x][y] = true;
                }
            }
        }
    }

public:
    // Write bfs for finding the connected component
    // Yes here you should not that you can use dfs instead of bfs for finding the connected component
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        int islandCnt = 0;

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (visited[i][j] == false && grid[i][j] == '1') {
                    bfs(grid, i, j, visited);
                    ++islandCnt;
                }
            }
        }
        return islandCnt;
    }
};

int main(void)
{





    return 0;
}

#endif // FORREF
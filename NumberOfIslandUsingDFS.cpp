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
    Constraints:
    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.
*/

#define FORREF
#ifndef FORREF

class Solution {
    /*
        For manging the all four direction in grid for
        moving path
        LURD
    */
    const int x_r[4] = {0, -1, 0, 1};
    const int y_c[4] = {-1, 0, 1, 0};

    bool isValid(int x, int y, const int &R, const int &C) {
        if (x < 0 || x >= R) return false;
        if (y < 0 || y >= C) return false;

        return true;
    }


    /*
        Write one recursive method to handle the 
        dfs traversal within grid to find the connected 
        componenets or parts
    */
    void dfs(const vector<vector<char>> &grid, pair<int, int> cur, const int &R, const int &C, vector<vector<bool>>& visited) {
        visited[cur.first][cur.second] = true;
        int xr, yc;
        for (int i = 0; i < 4; ++i) {
            xr = cur.first + x_r[i];
            yc = cur.second + y_c[i];
            // here in below code you should be visilent for the condition otherwise infinite loop
            if (isValid(xr, yc, R, C) && grid[xr][yc] == '1' && !visited[xr][yc]) {
                visited[xr][yc] = true;
                dfs(grid, { xr,yc }, R, C, visited);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // The count of islands 
        int nIslands = 0;

        int R = grid.size();
        int C = grid[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                // careful for the value you are comparing in below conditional code
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    dfs(grid, { i,j }, R, C, visited);
                    ++nIslands;
                }
            }
        }
        return nIslands;
    }
};


Solution sln;

int main() {
    // testing and verification method for your logic
    vector<vector<char>> input;
    int ans = 0;

    input = { 
                {'1','1','1','1','0'}, {'1','1','0','1','0'},
                {'1','1','0','0','0'}, {'1','1','0','0','0'} 
            };
    ans = sln.numIslands(input);
    if (ans == 1) cout << "1. PASS" << endl;

    input = {
                {'1','1','0','0','0'}, {'1','1','0','0','0'},
                {'0','0','1','0','0'}, {'0','0','0','1','1'}
    };
    ans = sln.numIslands(input);
    if (ans == 3) cout << "2. PASS" << endl;
}

#endif // FORREF
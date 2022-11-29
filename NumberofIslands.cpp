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

class Solution {
protected:
    // Off-course first target is to finish the problem than we will see , can we do it by using the dfs also?
    void bfs(vector<vector<char>>& grid, int xSrc, int ySrc, vector<vector<bool>>& visited) {


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



            }
        }
    }
};

int main(void)
{


    return 0;
}

#endif // FORREF
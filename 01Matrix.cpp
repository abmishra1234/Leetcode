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
    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.
*/

#define FORREF
#ifndef FORREF
// L U R B
int xr[4] = { 0, -1, 0, 1 };
int yc[4] = { -1, 0, 1, 0 };

class Solution {
public:

    bool Valid(int x, int y, const int& R, const int& C) {
        if (x < 0 || x >= R) return false;
        if (y < 0 || y >= C) return false;

        return true;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int R = mat.size();
        int C = mat[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        // { r,{c,val}}
        queue<pair<int, int>> q;

        /*
            one guiding factor, I can see here that your problem
            is to fill 0 at all places which is non zero as of now

            And so it is also indicating that your filling zero's should start at all places 
            where you will find zero.
        */

        vector<vector<int>> dist(R, vector<int>(C, INT_MAX));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (mat[i][j] == 0) {
                    q.push({ i,j});
                    dist[i][j] = 0;
                }
            }
        }

        // until your queue becomes empty
        while (q.empty() == false) {
            pair<int, int> pi = q.front();
            q.pop();

            int x, y;
            for (int i = 0; i < 4; ++i) {
                x = pi.first + xr[i];
                y = pi.second + yc[i];

                if (Valid(x, y, R, C) && dist[x][y] == INT_MAX) {
                    dist[x][y] = min(dist[x][y], 1+dist[pi.first][pi.second]);
                    q.push({ x,y });
                }
            }
        }
        return dist;
    }
};

Solution sln;

int main(void)
{
    vector<vector<int>> input = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    vector<vector<int>> result = sln.updateMatrix(input);

    for (auto v : result) {
        for (auto elem : v) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

#endif // FORREF
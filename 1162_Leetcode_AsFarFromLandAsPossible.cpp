using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

//#define FORREF
#ifndef FORREF

class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    bool isValid(int i, int j, int R) {
        if (i < 0 || i >= R) return false;
        if (j < 0 || j >= R) return false;
        
        return true;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int R = (int) grid.size();
        vector<vector<int>> dist(R, vector<int>(R, INT_MAX));
        // {row index, {colind, distance}}
        typedef pair<int, pair<int, int>> P3i; 
        
        P3i p3i;
        deque<P3i> q;
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < R; ++j) {
                if (grid[i][j]) q.push_back({ i, {j, 0} });
            }
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second.first;
            int d = q.front().second.second;
            q.pop_front();

            for (int i = 0; i < 4; ++i) {
                int x = r + dx[i];
                int y = c + dy[i];

                if (isValid(x, y, R) && !grid[x][y] && ((d + 1) < (dist[x][y]))) {
                    dist[x][y] = (d + 1);
                    q.push_back({ x, {y, dist[x][y]} });
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < R; ++j) {
                if (!grid[i][j]) {
                    if (ans < dist[i][j]) ans = dist[i][j];
                }
            }
        }
        return (ans == INT_MIN) ? -1 : ans;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
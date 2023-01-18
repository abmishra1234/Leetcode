// GfG-Problem Link: https://bit.ly/3AsA08W

using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

//#define FORREF
#ifndef FORREF
/*
    Let's try to understand this problem, and also find the
    key concept and implementation expected in this porblem.

    1. Find the all possible connected components
        - Let's build this using the dfs approach
        
    2. How to store these connected component 
       in some data structure so that you will have 
       unique components only inside this data structure
*/

class Solution {
public:

    bool check(int x, int y, int R, int C) {
        if (x < 0 || x >= R) return false;
        if (y < 0 || y >= C) return false;
        return true;
    }

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    typedef vector<pair<int, int>> MyVec;

    struct MyHash {
        auto operator()(const MyVec& v) const {
            auto h = 0;
            for (auto p : v) {
                h ^= std::hash<int>{}(p.first);
                h ^= std::hash<int>{}(p.second);
            }
            return h;
        }
    };
    
    unordered_set<MyVec, MyHash> s;

    // normalize the path
    void normalize(MyVec& path) {
        int ps = path.size();

        for (int i = ps - 1; i >= 0; --i) {
            path[i].first = (path[i].first - path[0].first);
            path[i].second = (path[i].second - path[0].second);
        }
    }

    void dfs(int r, int c, vector<vector<int>>& vis, 
        MyVec &path, vector<vector<int>>& grid) {
        vis[r][c] = 1;
        path.push_back({ r,c });
        int x, y;

        for (int i = 0; i < 4; ++i) {
            x = r + dx[i];
            y = c + dy[i];

            if (check(x, y, grid.size(), grid[0].size())
                && !vis[x][y] && grid[x][y]) {
                dfs(x, y, vis, path, grid);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();

        vector<vector<int>> vis(R, vector<int>(C, 0));
        s.clear();

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (!vis[i][j] && grid[i][j]) {
                    MyVec path;
                    dfs(i, j, vis, path, grid);
                    // normalize the path
                    normalize(path);
                    s.insert(path);
                }
            }
        }
        return s.size();
    }
};

int main() {
    FILE* fp = nullptr;
    freopen_s(&fp, "g16.txt", "r", stdin);
    // ------------------------
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
#endif // FORREF
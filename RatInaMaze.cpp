// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030?source=youtube&campaign=Recursion_Fraz&utm_source=youtube&utm_medium=affiliate&utm_campaign=Recursion_Fraz

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

#define FORREF
#ifndef FORREF

class Solution {
public:
    /*
        Utility method
        - it is just a game of how to start from one cell and 
         reach to other cell
        
        - you should finds the all possible paths 
          to travel and reach the the destination
    
        Implement this using recursion ( DFS )

    */
    int dx[4] = { 1, 0, 0, -1 };
    int dy[4] = { 0, -1, 1, 0 };

    bool check(int r, int c, int& N) {
        if (r < 0 || r >= N) return false;
        if (c < 0 || c >= N) return false;
        return true;
    }

    void append(string& word, int i) {
        if (i == 0) word += "D";
        else if (i == 1) word += "L";
        else if (i == 2) word += "R";
        else word += "U";
    }

    void remove(string& out) {
        out = out.substr(0, out.size() - 1);
    }

    void solve(int xsrc, int ysrc, string out,
        vector<string>& ans, vector<vector<bool>>& visited,
        int N, vector < vector < int >>& arr)
    {
        if (!check(xsrc, ysrc, N)) return;
        if (xsrc == N - 1 && ysrc == N - 1) {
            ans.push_back(out);
            return;
        }


        visited[xsrc][ysrc] = true;
        // let's try to go to the all adjacent cell with possbilities
        int x, y;

        for (int i = 0; i < 4; ++i) {
            x = xsrc + dx[i];
            y = ysrc + dy[i];

            if (check(x, y, N) && arr[x][y] && !visited[x][y]) {
                visited[x][y] = true;
                append(out, i);
                solve(x, y, out, ans, visited, N, arr);
                visited[x][y] = false;
                remove(out);
            }
        }
        visited[xsrc][ysrc] = false;
    }

    vector < string > searchMaze(vector < vector < int >>& arr, int n) {
        vector<string> paths;
        string out = "";
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        if (arr[0][0] == 0) return {};
        solve(0, 0, out, paths, visited, n, arr);
        return paths;
    }
};

Solution sln;

int main(void)
{
    vector < vector < int >> arr;
    int n;
    vector<string> ans;

    arr = { {1,0,0,0 }, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    n = 4;
    ans = sln.searchMaze(arr, n);





    return 0;
}

#endif // FORREF

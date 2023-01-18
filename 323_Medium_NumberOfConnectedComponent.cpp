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
        I have to implement this method using bfs
        So, this basic feature of BFS or DFS is if
        you start from any vertex it will touch all the 
        subsequent connected vertex.
    */
    void dfs(int u, vector<int>& vis,
        vector<vector<int>>& adj) {
        vis[u] = 1;

        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v, vis, adj);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        // let's convert edges into adj list
        vector<vector<int>> adj;
        adj.resize(n, vector<int>());

        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, vis, adj);
                ++ans;
            }
        }

        return ans;
    }
};

Solution sln;

int main(void)
{
    int n;
    vector<vector<int>> edges;
    int ans;

    // For TC #1
    n = 5;
    edges = { {0,1}, {1,2}, {3,4} };
    ans = sln.countComponents(n, edges);
    cout << ans << endl; // 2

    // For TC #2
    n = 5;
    edges = { {0,1}, {1,2}, {2,3}, {3,4} };
    ans = sln.countComponents(n, edges);
    cout << ans << endl; // 1

    return 0;
}

#endif // FORREF
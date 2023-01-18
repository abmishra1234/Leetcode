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
    void dfs(int u, vector<int>& vis, stack<int>& s, vector<vector<int>> &adj) {
        vis[u] = 1;
        for (auto v : adj[u]) {
            if (!vis[v]) {
                dfs(v, vis, s, adj);
            }
        }
        s.push(u);
    }

    vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
        vector<int> vis(v, 0);
        stack<int> s;
        vector<vector<int>> adj(v, vector<int>());

        // prepare your adjacency list
        for (int i = 0; i < e; ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        // let's call the dfs for all the nodes, which is not visited
        for (int i = 0; i < v; ++i) {
            if (!vis[i]) {
                dfs(i, vis, s, adj);
            }
        }
        
        // let's build ans vector and return
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top()); s.pop();
        }
        return ans;
    }
};



int main(void)
{

    return 0;
}

#endif // FORREF
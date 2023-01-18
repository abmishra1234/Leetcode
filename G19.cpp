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
    // Utility method you should write here
    // Let's check cycle using DFS traversal
    /*
        @Note:
        Incase of un-directed graph, we learned that,
        if you reach at some node again without foloowing their parent
        meaning you visited this node earlier from some different path

        Hence, it proved that there is a Cycle.

        You also note here that, the same logic would not be valid in the case
        of directed graph.

        Than, we should try to undertsand that , how we will check it.
        For that we will check does you reach here again in the same path traversal?
        if yes than you will say that it has cycle otherwise won't.
    */
    bool dfs(int u, vector<int>& vis, vector<int>& path,
        vector<int> adj[]) {
        vis[u] = 1;
        path[u] = 1;

        // you check all the adjacent vertex for the path
        for (auto v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, vis, path, adj)) return true;
            }
            else if (vis[v] && path[v]) return true;
        }
        path[u] = 0;
        // no cycle found
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        vector<int> path(V, 0);

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                if (dfs(i, vis, path, adj)) return true;
            }
        }

        // no cycle you foiund 
        return false;
    }
};


int main(void)
{
    // below two line code is for 
    // reading the test data from the input file
    FILE* fp = nullptr;
    freopen_s(&fp, "g19.txt", "r", stdin);

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

#endif // FORREF
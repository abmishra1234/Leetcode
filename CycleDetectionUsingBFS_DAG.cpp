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
/*
    This approach is called Kahn's Algorithm
    and this is based on bfs traversal approach
*/

class Solution {
    int detectCycleInDirectedGraph(int n, vector < pair < int, int >>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> indegree(n, 0);

        // let's build the adj list
        for (int i = 0; i < edges.size(); ++i) {
            adj[edges[i].first-1].push_back(edges[i].second-1);
            indegree[edges[i].second-1] += 1;
        }

        deque<int> q;
        // find the vertex with indegree 0 and push them into queue
        for (int i = 0; i < n; ++i) if (!indegree[i]) q.push_back(i);

        // simply run the bfs and collect the ans
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front(); q.pop_front();
            ans.push_back(u);

            // for neighbours
            for (auto v : adj[u]) {
                indegree[v]--;
                if (!indegree[v]) {
                    q.push_back(v);
                }
            }
        }
        return (ans.size() == n) ? false : true;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
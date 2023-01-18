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
    vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
        vector<vector<int>> adj(v, vector<int>());
        vector<int> indegree(v, 0);

        // let's build the adj list
        for (int i = 0; i < e; ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]] += 1;
        }

        deque<int> q;
        // find the vertex with indegree 0 and push them into queue
        for (int i = 0; i < v; ++i) {
            if (!indegree[i]) 
            {
                q.push_back(i);
            }
        }

        // simply run the bfs and collect the ans
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop_front();
            ans.push_back(u);
            
            // for neighbours
            for (auto v : adj[u]) {
                indegree[v]--;
                if (!indegree[v]) {
                    q.push_back(v);
                }
            }
        }

        return ans;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
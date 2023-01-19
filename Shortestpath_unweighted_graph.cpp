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
		This problem statement is itself a 
		intution to solve this problem with
		BFS traversal of graph.
	*/
	vector<int> shortestPath(vector<pair<int, int>> edges, 
		int n, int m, int s, int t) {

		// let's build some adjacency list for the given graph / edges
		vector<vector<int>> adj(n+1, vector<int>());
		for (int i = 0; i < m; ++i) {
			adj[edges[i].first].push_back(edges[i].second);
			adj[edges[i].second].push_back(edges[i].first);
		}

		// push the starting city into the queue
		vector<int> dist(n+1, 20000);
		vector<int> parent(n + 1, -1);
		deque<int> q;

		dist[s] = 0;
		parent[s] = -1;
		q.push_back(s);

		while (!q.empty()) {
			int u = q.front(); q.pop_front();
			for (auto v : adj[u]) {
				if (dist[v] == 20000 || (dist[v] != 20000 && (dist[v] > (1 + dist[u])))) {
					dist[v] = min(dist[v], 1 + dist[u]);
					parent[v] = u;
					q.push_back(v);
				}
			}
		}
		
		stack<int> stk;
		int par = t;

		while (par != -1) {
			stk.push(par);
			par = parent[par];
		}

		vector<int> ans;
		while (!stk.empty()) {
			ans.push_back(stk.top()); stk.pop();
		}
		return ans;
	}
};

int main(void)
{

    return 0;
}

#endif // FORREF
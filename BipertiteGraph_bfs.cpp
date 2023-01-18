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
    // bfs
	bool bfs(int u, vector<int> &color,
		vector<vector<int>> &adj) {
		deque<int> q;
		
		q.push_back(u);
		color[u] = 0;

		while (!q.empty()) {
			int u = q.front();
			q.pop_front();
			int col = color[u];

			for (auto v : adj[u]) {
				if (color[v] == -1) {
					color[v] = 1-col;
					q.push_back(v);
				}
				else if (color[u] == color[v]) return false;
			}
		}
		// you don't find any violation of rule until now 
		return true;
	}

	// dfs


	// is this graph is bipertite?
	bool isBipartite(int V, vector<vector<int>>adj) {
		// Color value is -1 means not colored yet
		// value 0 and 1 for Black and white 
		vector<int> color(V, -1);
		for (int i = 0; i < V; ++i) {
			if (color[i] == -1) {
				if (!bfs(i, color, adj)) return false;
			}
		}

		return true;
	}
};

int main(void)
{
	FILE* fp = nullptr;
	freopen_s(&fp, "bp.txt", "r", stdin);

	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;
		vector<vector<int>>adj(V, vector<int>());
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);
		if (ans)cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}

#endif // FORREF
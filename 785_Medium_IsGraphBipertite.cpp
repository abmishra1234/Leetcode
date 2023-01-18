// 785. Is Graph Bipartite?
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
	bool bfs(int s, vector<int>& color,
		vector<vector<int>>& adj) {
		deque<int> q;

		q.push_back(s);
		color[s] = 0;

		while (!q.empty()) {
			int u = q.front();
			q.pop_front();
			int col = color[u];

			for (auto v : adj[u]) {
				if (color[v] == -1) {
					color[v] = 1 - col;
					q.push_back(v);
				}
				else if (col == color[v]) return false;
			}
		}
		// you don't find any violation of rule until now 
		return true;
	}
	bool isBipartite(vector<vector<int>>& graph) {
		// Color value is -1 means not colored yet
		// value 0 and 1 for Black and white 
		vector<int> color(graph.size(), -1);
		for (int i = 0; i < graph.size(); ++i) {
			if (color[i] == -1) {
				if (!bfs(i, color, graph)) return false;
			}
		}
		return true;
	}
};


int main(void)
{

    return 0;
}

#endif // FORREF
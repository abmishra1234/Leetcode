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
	bool dfs(int u, int col, vector<int>& color, vector<vector<int>>& graph) {
		color[u] = col;
		// let's color the adjacent vertex
		for (auto v : graph[u]) {
			if (color[v] == -1) {
				if (!dfs(v, 1 - col, color, graph)) return false;
			}
			else if (color[v] == col) return false;
		}
		return true;
	}

	bool isBipartite(vector<vector<int>>& graph) {
		// Color value is -1 means not colored yet
		// value 0 and 1 for Black and white 
		vector<int> color(graph.size(), -1);
		for (int i = 0; i < graph.size(); ++i) {
			if (color[i] == -1) {
				if (!dfs(i, 0, color, graph)) return false;
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
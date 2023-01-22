/* Question Link :
	https://www.codingninjas.com/codestudio/library/shortest-path-in-a-directed-acyclic-graph
*/

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

//#define FORREF
#ifndef FORREF
/*
	Pre-Condition here is
	1. Directed and Acyclic Graph
	2. you will be looking for shortest path from one src to n-1 destibnation vertex

	If the above pre - condition met in your problem than you are good to go for the 
	below type of solution approach

	Approach:
	As you know, in graph, there are two different traversing algorithm available

	BFS : using queue data structure
	DFS : using system stack or custom stack

	Usually, when you have large recursion depth possible, in that scenario
	might be BFS is better solution instead DFS but in general theoritically 
	BFS and DFS both will work in all the scenario with miner customisation
	in all graph problem.



*/

class ShortestPathWithBFS {
public:
	typedef pair<int, pair<int, int>> p3i; // u,v,w



	/*
		N - Number of vertex : { 0 ~ N-1 }
		graph : this is the collection of two vertex [u,v] as an edge 
	
	Approach:
		Find the topological ordering from the ‘src’ node
		Now traverse the vertices in the ordering one by one.
		If there are some nodes in the ordering before the ‘src’ node, they are not reachable from the ‘src’ node, hence no need to update their distances from the ‘src’ node.
		Now for each vertex from the ‘src’ node in the ordering, relax its connecting edges one by one and update the distances of the other vertex connecting the edge with the current vertex if their respective edges get relaxed.
		Once all edges get relaxed, return the list of distances.


	*/

	void toposort(int s, int N, vector<int> &order,vector<vector<pair<int, int>>> adj) {










	}


	vector<int> shortestpath(int s, int N, vector<p3i> graph) {
		// Step 01 : Create the topological sort order of vertex
		






	}
};

int main(void)
{

	return 0;
}

#endif // FORREF



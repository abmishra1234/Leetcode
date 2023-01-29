// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
// https://www.youtube.com/watch?v=i9ORlEy6EsI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=31

using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

#define FORREF
#ifndef FORREF

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
	typedef unordered_map<TreeNode*, TreeNode*> MyMap; // {node, parent}
public:
	// All the nodes value are unique, it is given in this problem
	void filltheparent(TreeNode* root, TreeNode* target, int k,
		MyMap &m) {
		deque<pair<TreeNode*, TreeNode*>> q;
		q.push_back({ root, nullptr }); // root have no parent and so this nullptr

		while (!q.empty()) {
			TreeNode* np = q.front().first;
			TreeNode* pp = q.front().second;
			q.pop_front();

			if (np->left) q.push_back({ np->left, np });
			if (np->right) q.push_back({ np->right, np });

			m.insert({ np, pp });
		}
	}

	/*
		Intution for the porblem
		1. In problem you have two requirement
		a. find the target node
		b. find the all nodes which having diatance K from the target node

		so, logically for requirement (a), kind of dfs traversal is ok
		and for requirement (b), best solution is bfs traversal

		Next point is, do we really need both algorithm in this problem,
		or one kind of traversal i.e, bfs is sufficient to handle both logic?

		As per the logical understanding one type of logic for ex: bfs is fair enough to
		handle the both requirement.

		Let's discuss the approach:
		1. Finding the target Node is not an issue at all,
		2. Issue is how to get the all possible node from the target node at
		   distance k, you may ask me , what is the challenge?, I can traverse....
		   the problem is Tree is hierarchical data structure and you will only move
		   from top to bottom. By default, tree is not going to support any traversing
		   from bottom to top becuse we have only link of child in tree, and it is
		   different from the graph here...
	*/
	vector<int> distanceK(TreeNode* root, 
		TreeNode* target, int k) {
		MyMap m;
		
		// step 01
		filltheparent(root, target, k, m);
		
		// Step 02 - you have to run the bfs and find the all possible nodes
		// at distance k
		// My source node is the target node

		// Node and their distance from source
		deque<pair<TreeNode*, int>> q; 
		
		// This is to track down the node is already visited?
		unordered_map<TreeNode*, bool> visited; 

		// the value of node to be collected and returned 
		vector<int> ans;

		q.push_back({ target, 0 });
		visited[target] = 1;

		while (!q.empty()) {
			TreeNode* np = q.front().first;
			int dist = q.front().second;
			q.pop_front();

			if (dist == k) {
				ans.push_back(np->val);
			}
			else
			{
				TreeNode* pp = m[np];
				
				if (pp && !visited[pp]) {
					visited[pp] = 1;
					q.push_back({ pp, dist + 1 });
				}
				
				if (np->left && !visited[np->left]) {
					visited[np->left] = 1;
					q.push_back({ np->left, dist + 1 });
				}

				if (np->right && !visited[np->right]) {
					visited[np->right] = 1;
					q.push_back({ np->right, dist + 1 });
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

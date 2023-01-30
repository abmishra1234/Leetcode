/*
1. https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563?source=youtube&amp;campaign=Striver_Tree_Videos&amp;utm_source=youtube&amp;utm_medium=affiliate&amp;utm_campaign=Striver_Tree_Videos
2. https://www.youtube.com/watch?v=2r5wLmQfD6g&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=32

	Note for yourself:


*/

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

template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

// {node->data, {node, parent}}
typedef unordered_map<int, pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*>> MyMap; 

// All the nodes value are unique, it is given in this problem
void filltheparent(BinaryTreeNode<int>* root, MyMap& m) {
	deque<pair<BinaryTreeNode<int>*, BinaryTreeNode<int>*>> q;
	q.push_back({ root, nullptr }); // root have no parent and so this nullptr

	while (!q.empty()) {
		BinaryTreeNode<int>* np = q.front().first;
		BinaryTreeNode<int>* pp = q.front().second;
		q.pop_front();

		if (np->left) q.push_back({ np->left, np });
		if (np->right) q.push_back({ np->right, np });

		m.insert({ np->data, {np, pp } });
	}
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
	// Step 01 : create the mapping of node vs parent for future traversal
	MyMap m;
	filltheparent(root, m);

	// Step 02 - run the bfs so that you can find the minimum time to burst all the
	// complete tree
	deque<pair<int, int>> q;
	// This is to track down the node is already visited?
	unordered_map<int, bool> visited;

	q.push_back({ start, 0 });
	visited[start] = 1; // marked

	int ans = 0;

	while (!q.empty()) {
		int n = q.front().first;
		BinaryTreeNode<int>* np = m[n].first;
		int time = q.front().second;
		q.pop_front();

		// update the time
		ans = max(ans, time);

		// now focus on child and parent
		BinaryTreeNode<int>* pp = m[n].second;

		if (pp && !visited[pp->data]) {
			visited[pp->data] = 1;
			q.push_back({ pp->data, time + 1 });
		}


		if (np->left && !visited[np->left->data]) {
			visited[np->left->data] = 1;
			q.push_back({ np->left->data, time + 1 });
		}

		if (np->right && !visited[np->right->data]) {
			visited[np->right->data] = 1;
			q.push_back({ np->right->data, time + 1 });
		}
	}
	return ans;
}

int main(void)
{

	return 0;
}

#endif // FORREF
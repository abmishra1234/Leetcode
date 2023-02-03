/*
	https://leetcode.com/problems/recover-binary-search-tree/description/
	https://www.youtube.com/watch?v=ZWGW7FminDM&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=53
*/
using namespace std;
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

//#define FORREF
#ifndef FORREF

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

/*
	This should be your algorithm:
	Let's find the optimal solution of this problem
	- What is intution here,
	
	The Intuition is, you will have to cover the two sopt while solving this 
	problem. One is Top to Down and Other is Bottom to Up

	So, I have to understand this in my approach to solve the problem

	Let's write the steps required to solve this problem,
	1. Prepare the parent child relationship
	2. Also to maintain the relationship as left child or right child
	3. Maintain the range in whcih your current node value should lie
	4. Incase you see any node is not falling under some category than
	   that is the violation place you found.
	5. Now you have to move backward and check from where this problem started.
	6. Once you identified both the node in BST, just swap the two node and that sit.
*/

class Solution {
	/*
		Key is the TreeNode*
		value is pair<parent node, child node is left child or right child>
		
		For Left child put 0 as value and for right child put 1 as value

	*/
	typedef unordered_map<TreeNode*, pair<TreeNode*, int>> MyMap;
	MyMap m;

	TreeNode* fnode;
	TreeNode* snode;
public:
	// Thumb rule is any thing which is not part of state 
	// as per the problem size than that wouldn't be part 
	// of recursion.
	bool solve(TreeNode* root, int lrange, int rrange) {
		// if you reach at this point means the complete 
		// BST have no violation in principal
		if (!root) return true;

		// the below ids the violation condition
		if (root->val < lrange || root->val > rrange) return false;
		
		m[root->left] = { root, 0 };
		if (!solve(root->left, lrange, min(rrange, root->val))) {
			fnode = root;
			return false;
		}

		m[root->right] = { root, 1 };
		if (!solve(root->right, max(root->val, lrange), rrange)) {
			fnode = root;
			return false;
		}
		
		return true;
	}

	void recoverTree(TreeNode* root) {
		m.clear();
		fnode = nullptr;
		snode = nullptr;


		if (!solve(root, INT_MIN, INT_MAX)) {
			// so you found one node for now and you
			// need to find the another node to swap their values to avoid the violation
			// As per the problem, we have only one violation...





		}




	}
};



int main(void)
{

	return 0;
}

#endif // FORREF
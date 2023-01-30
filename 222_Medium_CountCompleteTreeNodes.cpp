/*
	1. https://leetcode.com/problems/count-complete-tree-nodes/description/
	2. https://www.youtube.com/watch?v=i_r2uKbwHCU
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

//#define FORREF
#ifndef FORREF

struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
	int lheight(TreeNode* root) {
		if (!root) return 0;
		return 1 + lheight(root->left);
	}

	int rheight(TreeNode* root) {
		if (!root) return 0;
		return 1 + rheight(root->right);
	}

	/*
		The next point here is how to improve this approach?
	*/
	int countNodes(TreeNode* root) {
		if (!root) return 0;

		int lh = lheight(root);
		int rh = rheight(root);

		if (lh == rh) return pow(2, lh) - 1;

		int lcount = countNodes(root->left);
		int rcount = countNodes(root->right);
		return (1 + lcount + rcount);
	}
};

int main(void)
{

	return 0;
}

#endif // FORREF



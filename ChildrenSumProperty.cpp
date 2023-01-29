// https://www.youtube.com/watch?v=fnmisPM6cVo
// https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/

/*
	Self Notes:
	1. if both children sum is less than parent, make children's value to parent's value.
	2. if both children values sum is greater than or equal to parent, make parent's value to children's sum.
	3. recursively go left and right. Traversal type: DFS.
	4. when coming back up the tree, take children sum and replace it in parent.
	5. at any point we reach null, just return (base case)
	6. Intuition: while going down, increase the children values so we make sure to never fall short, then all we have to do is sum both children and replace it in parent.
*/

using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>s
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
public:
	int solve(TreeNode* root)
	{
		if (!root) return 0;
		if (!root->left && !root->right) return root->val;
		// next step, compute the node value and childrens value
		// update the left child atleast equal to par
		if (root->left && root->val >= root->left->val) {
			root->left->val = root->val;
		}

		if (root->right && root->val >= root->right->val) {
			root->right->val = root->val;
		}

		int lval = solve(root->left);
		int rval = solve(root->right);

		root->val = (lval+rval);

		return root->val;
	}
	void makechildrensumtree(TreeNode* root) {
		solve(root);
	}
};

Solution sln;

int main(void)
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(35);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(10);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(2);

	sln.makechildrensumtree(root);
	return 0;
}

#endif // FORREF
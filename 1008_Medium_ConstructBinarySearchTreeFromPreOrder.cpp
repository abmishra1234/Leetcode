/*
	https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
	https://www.youtube.com/watch?v=UmJT3j26t1I&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=49
	Intuitional Approach
	Time Complexity : O(nlogn)
	Space Complexity : System stack used in recursion

	Here are the intuitive approach of this problem
	=>
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
struct TreeNode {
	int val;
	TreeNode* left, * right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

class Solution {
public:
	// write one utility method to insert element into BST
	TreeNode* insert(TreeNode* root, int n) {
		if (!root) return new TreeNode(n);
		if (n < root->val) root->left = insert(root->left, n);
		else root->right = insert(root->right, n);
		return root;
	}

	TreeNode* bstFromPreorder(vector<int>& preorder) {
		TreeNode* root = nullptr;
		for (auto n : preorder) root = insert(root, n);
		return root;
	}
};

int main(void)
{


	return 0;
}

#endif // FORREF


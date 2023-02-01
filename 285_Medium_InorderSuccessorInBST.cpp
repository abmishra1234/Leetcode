/*
	https://leetcode.com/problems/inorder-successor-in-bst/description/
	https://www.youtube.com/watch?v=SXKAD2svfmI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=50

	Intuitive Approach:
	Will see the improvement later...
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

struct MySort {
	auto operator()(const TreeNode* a, const TreeNode* b) const {
		return a->val < b->val;
	}
};

typedef set<TreeNode*, MySort> MySet;

class Solution {
public:

	void inorder_util(TreeNode* root, MySet& s) {
		if (!root) return;
		inorder_util(root->left, s);
		s.insert(root);
		inorder_util(root->right, s);
	}

	TreeNode* inorderSuccessor(TreeNode* root, 
		TreeNode* p) {
		MySet s;
		inorder_util(root, s);
		auto it = s.find(p);
		++it;
		if (it == s.end()) return nullptr;
		return *it;
	}
};

Solution sln;

int main(void)
{
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);

	sln.inorderSuccessor(root, root->left);

	return 0;
}

#endif // FORREF
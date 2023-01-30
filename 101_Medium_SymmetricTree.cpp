// https://leetcode.com/problems/symmetric-tree/description/
// https://www.youtube.com/watch?v=nKggNAiEpBE&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=26

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

	bool isSymmetric(TreeNode* fnode, TreeNode* snode) {
		if (!fnode || !snode) return (fnode == snode);
		if (fnode->val != snode->val) return false;

		return isSymmetric(fnode->left, snode->right)
			&& isSymmetric(fnode->right, snode->left);
	}

    bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return isSymmetric(root->left, root->right);
	}
};

int main(void)
{

    return 0;
}

#endif // FORREF
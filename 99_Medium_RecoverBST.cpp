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
	vector<int> inorder;

public:
	void solve(TreeNode* root) {
		if (!root) return;
		solve(root->left);
		inorder.push_back(root->val);
		solve(root->right);
	}

	void custm_inorder(TreeNode* root, int &ind) {
		if (!root) return;
		custm_inorder(root->left, ind);
		if (root->val != inorder[ind]) {
			root->val = inorder[ind];
		}
		++ind;
		custm_inorder(root->right, ind);
	}

	void recoverTree(TreeNode* root) {
		sort(inorder.begin(), inorder.end());
		int ind = 0;
		custm_inorder(root, ind);
	}
};



int main(void)
{

	return 0;
}

#endif // FORREF
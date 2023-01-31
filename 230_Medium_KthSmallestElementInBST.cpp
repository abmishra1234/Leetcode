/*
  https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
  https://www.youtube.com/watch?v=9TJYWh0adfk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=47

  // Different type of Approach
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
	void solve(TreeNode* root, vector<int>& ans) {
		if (!root) return;
		solve(root->left, ans);
		ans.push_back(root->val);
		solve(root->right, ans);
	}

    int kthSmallest(TreeNode* root, int k) {
		vector<int> ans;
		solve(root, ans);
		return ans[k - 1];
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
/*
	https://leetcode.com/problems/validate-binary-search-tree/description/
	https://www.youtube.com/watch?v=f-sj7I5oXEI&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=48

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

    void solve(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        solve(root->left, nodes);
        nodes.push_back(root->val);
        solve(root->right, nodes);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        if (!root) return true;

        solve(root, nums);

        long long int val = LLONG_MIN;

        if (nums.size() == 1) return true;

        for (auto elem : nums) {
            if (val >= elem) return false;
            val = elem;
        }
        return true;
    }
};

int main(void)
{

	return 0;
}

#endif // FORREF
// 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
// https://www.youtube.com/watch?v=WszrfSwMz58&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=18

using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

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

    int solve(TreeNode* root, int& maxv) {
        if (!root) return 0;
        int lval = solve(root->left, maxv);
        if (lval < 0) lval = 0;
        int rval = solve(root->right, maxv);
        if (rval < 0) rval = 0;
        maxv = max(maxv, (lval + rval + root->val));
        return root->val + max(lval, rval);
    }

    int maxPathSum(TreeNode* root) {
        int maxv = INT_MIN;
        solve(root, maxv);
        return maxv;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF
using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>

#define FORREF
#ifndef FORREF

class TreeNode {
public:
    int val;
    TreeNode* left, * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

/*
    Any Tree is considered to be BST if they have following properties:
    1. Any node is present in left side of the current TreeNode should be less than the val of
    current TreeNode
    2. Any node is present in right side of the current TreeNode should be more than the val of
    current TreeNode
    3. Left and Right sub tree is also BST
*/

/*
    Approach - 02.
    Let's go by recursive approach
    1. Define the range in which your sub tree value should fall,
    and any node value is not falling in this range that means your binary tree is not valid.
*/
typedef long long int lli;

class Solution {
public:

    bool solve(TreeNode* root, long long int l, long long int r) {
        if (!root) return true;
        if (root->val <= l || root->val >= r) return false;

        bool lval = solve(root->left, l, root->val);
        bool rval = solve(root->right, root->val, r);
        
        return lval && rval;
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

Solution sln;

int main(void)
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);


    bool ans = sln.isValidBST(root);
    cout << ans << endl;

    return 0;
}

#endif // FORREF
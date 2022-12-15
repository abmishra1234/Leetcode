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
    TreeNode() : val(0), left(nullptr), right(nullptr){}
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
    Approach - 01.
    Simplest Approach is to traverse the inorder of BST and check the numbers 
    are in increasing order or not?
    @Note:
    return true if they are in increasing order otherwise return false.
*/
class Solution {
public:

    void solve(TreeNode* root, vector<int> &nodes) {
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
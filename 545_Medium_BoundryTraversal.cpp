// https://leetcode.com/problems/boundary-of-binary-tree/
// https://youtube.com/watch?v=0ca1nvR0be4&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=21
// https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/
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

/*
    As per concept:
    we have to collect the node like,
    1. Left most child of tree without leaf node
    2. Leaf Node inorder traversal
    3. Rightmost child of tree in reverse order without leaf node 
*/

class Solution {
public:
    // Write few utility method to support your algorithm
    void leftboundry(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        if (!root->left && !root->right) return;
        ans.push_back(root->val);
        if (root->left) leftboundry(root->left, ans);
        else leftboundry(root->right, ans);
    }

    void bottomboundry(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        bottomboundry(root->left, ans);
        if (!root->left && !root->right) {
            ans.push_back(root->val);
            return;
        }
        bottomboundry(root->right, ans);
    }

    void rightboundry(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        if (!root->left && !root->right) return;
        if (root->right) rightboundry(root->right, ans);
        else rightboundry(root->left, ans);
        // for maintaining the collection in reverese order
        ans.push_back(root->val);
    }
    //-----------------main logic------------------
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        // push the root here
        if (!root) return {};
        ans.push_back(root->val);
        if (!root->left && !root->right) return ans;

        // Go for Left Boundry
        leftboundry(root->left, ans);
        // Go for bottom boundry
        bottomboundry(root, ans);
        // Go for right boundry in reverse order
        rightboundry(root->right, ans);

        return ans;
    }
};
int main(void)
{

    return 0;
}

#endif // FORREF
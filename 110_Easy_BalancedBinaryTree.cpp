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
class TreeNode {
public:
    int val;
    TreeNode* left, * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        bool result = true;
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        
        if (lDepth < rDepth - 1 || rDepth < lDepth - 1) return false;

        result &= isBalanced(root->left);
        result &= isBalanced(root->right);

        if (!result) return false;
        
        return result;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF
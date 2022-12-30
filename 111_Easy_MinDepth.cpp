
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

//#define FORREF
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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        else if (root->left == nullptr && root->right) return 1 + minDepth(root->right);
        else if (root->right == nullptr && root->left) return 1 + minDepth(root->left);
        else return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF


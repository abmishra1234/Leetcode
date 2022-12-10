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
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int Util(TreeNode* root) {
        if (root == nullptr) return 0;
        int maxL = 0, maxR = 0;
        maxL = 1 + Util(root->left);
        maxR = 1 + Util(root->right);
        return max(maxL, maxR);
    }

    int maxDepth(TreeNode* root) {
        return Util(root);
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
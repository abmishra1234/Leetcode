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

    int depth(TreeNode* root, int& diam) {
        if (!root) return 0;
        int ld = 0, rd = 0;
        ld = depth(root->left, diam);
        rd = depth(root->right, diam);

        diam = max(diam, (ld + rd));
        return (1 + max(ld, rd));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        depth(root, diam);
        return diam;
    }
};

Solution sln;

int main(void)
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);

    int ans = sln.diameterOfBinaryTree(root);
    cout << ans << endl;

    return 0;
}

#endif // FORREF
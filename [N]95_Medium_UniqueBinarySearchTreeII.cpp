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
    TreeNode* left, * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(0), left(l), right(r) {}
};
class Solution {
public:
    // insert node into the BST
    TreeNode* insertnode(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        if (val < root->val) root->left = insertnode(root->left, val);
        else root->right = insertnode(root->right, val);
        return root;
    }

    void 


    // generate unique BST
    vector<TreeNode*> generateTrees(int n) {
        TreeNode* root = nullptr;
        solve(root, n);



    }
};

Solution sln;

int main(void)
{
    int n;
    vector<TreeNode*> ans;
    
    // For TC 1
    n = 1;
    ans = sln.generateTrees(n);
    cout << "The number of Unique BST : " << ans.size() << endl;

    // For TC 2
    n = 3;
    ans = sln.generateTrees(n);
    cout << "The number of Unique BST : " << ans.size() << endl;
    
    // For TC 2
    n = 2;
    ans = sln.generateTrees(n);
    cout << "The number of Unique BST : " << ans.size() << endl;

    // For TC 2
    n = 4;
    ans = sln.generateTrees(n);
    cout << "The number of Unique BST : " << ans.size() << endl;


    return 0;
}

#endif // FORREF
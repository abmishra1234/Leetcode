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

/*
    Approach 02 : Iterative Approach
*/

#define FORREF
#ifndef FORREF
struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// Define the TreeNode
class Solution {
    unordered_map<int, int> map;
    unordered_map<int, int>::iterator iter;

    TreeNode* buildTree_rec(vector<int>& inorder, int i1, int i2, vector<int>& postorder, int p1, int p2)
    {
        if (i1 >= i2 || p1 >= p2)
            return nullptr;

        int element = postorder[p2 - 1];
        TreeNode* root = new TreeNode(element);
        auto it = find(inorder.begin() + i1, inorder.begin() + i2, element);
        int diff = it - inorder.begin() - i1;

        root->left = buildTree_rec(inorder, i1, i1 + diff, postorder, p1, p1 + diff);
        root->right = buildTree_rec(inorder, i1 + diff + 1, i2, postorder, p1 + diff, p2 - 1);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int vsize = inorder.size();
        if (vsize <= 0)
            return nullptr;

        return buildTree_rec(inorder, 0, vsize, postorder, 0, vsize);
    }
};
int main(void)
{

    return 0;
}

#endif // FORREF
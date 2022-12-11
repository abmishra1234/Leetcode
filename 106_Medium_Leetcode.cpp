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
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

typedef unordered_map<int, int> umap;
umap m;

class Solution {
public:
    void createmap(vector<int>& inorder) {
        int index = 0;
        for (auto e : inorder) {
            m[e] = index++;
        }
    }

    TreeNode* solve(vector<int>& inorder,
        vector<int>& postorder, int &postind, int l, int r) {

        if (postind < 0 || l > r) return nullptr;

        TreeNode* root = new TreeNode(postorder[postind]);
        int pos = m[postorder[postind]];
        --postind;
        root->right = solve(inorder, postorder, postind, pos + 1, r);
        root->left = solve(inorder, postorder, postind, l, pos - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, 
        vector<int>& postorder) {
        // First point here is to create the map for marking the all position
        // from inorder array for later use
        m.clear();
        createmap(inorder);

        // get the position of last element from inorder
        int postind = postorder.size() - 1;
        return solve(inorder, postorder, postind, 0, postorder.size() - 1);
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
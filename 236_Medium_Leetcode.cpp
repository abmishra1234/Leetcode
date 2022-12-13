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

struct TreeNode {
    int val;
    TreeNode* left, * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};


class Solution {
public:
    TreeNode* root;
    Solution() {
        root = nullptr;
    }
    // optype = 1 means insert
    // optype = 2, means search into set 
    // result should hold the LCA Treenode*
    void Solve(TreeNode* root, TreeNode* p, unordered_set<TreeNode*> &s, int optype, TreeNode** result) {
        stack<TreeNode*> st;
        if (!root) {
            *result = nullptr;
            return;
        }

        st.push(root);

        if (optype == 1) {
            while (st.empty()) {



            }
            
            


        }
        else if (optype == 2) {


        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, 
        TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> s;
        TreeNode* result = nullptr;
        Solve(root, p, s, 1, &result);
        Solve(root, q, s, 2, &result);
        return result;
    }
};

Solution sln;

int main(void)
{
    // input = [3,5,1,6,2,0,8,null,null,7,4]
    // p = 5, q = 1

    TreeNode* p, *q, *ansnode;

    ansnode = sln.root = new TreeNode(3);
    p = sln.root->left = new TreeNode(5);
    q = sln.root->right = new TreeNode(1);
    sln.root->left->left = new TreeNode(6);
    sln.root->left->right = new TreeNode(2);
    sln.root->left->right->left = new TreeNode(7);
    sln.root->left->right->right = new TreeNode(4);
    sln.root->right->left = new TreeNode(0);
    sln.root->right->right = new TreeNode(8);

    // first tc #1 
    // outnode is equivalent to ansnode
    TreeNode *outnode = sln.lowestCommonAncestor(sln.root, p, q);
    if (outnode) {
        if (ansnode == outnode) cout << "1. PASS" << endl;
    }

/*
    // first tc #2 
    // outnode is equivalent to ansnode
    TreeNode* outnode = sln.lowestCommonAncestor(sln.root, p, q);
    if (outnode) {
        if (ansnode == outnode) cout << "2. PASS" << endl;
    }
*/

    return 0;
}

#endif // FORREF
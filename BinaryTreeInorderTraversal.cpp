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

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    /*
      Write your recursive solution first
    */
    void rinorder(TreeNode* root, vector<int>& out)
    {
        if (root == nullptr)
            return;
        rinorder(root->left, out);
        out.push_back(root->val);
        rinorder(root->right, out);
    }

    /*
      So, target here is to write the iterative solution using 
      our own custom stack instead of using system stack
    */
    void itinorder(TreeNode* root, vector<int>& out)
    {
        if (!root) return;

        stack<TreeNode*> nstack;
        TreeNode* curr = root;

        while (true) {
            
            // Left child
            while (curr) {
                nstack.push(curr);
                curr = curr->left;
            }
            
            // base condition for exiting the loop
            if (nstack.empty()) break;

            // push the curr->value into the result set
            curr = nstack.top();
            nstack.pop();
            out.push_back(curr->val);
            
            // right child
            curr = curr->right;
        } //End if while loop with stack empty
    }

    vector<int> out;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        out.clear();
        itinorder(root, out);

        return out;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF
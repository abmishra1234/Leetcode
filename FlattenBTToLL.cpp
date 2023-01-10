// 114. Flatten Binary Tree to Linked List
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
/*
    This is very good question and it is not easy to solve,
    until you have good grasp of recursion
    
    Below is my recursive code for the problem.    
  
    I want to write iterative code for this also, let's do it...
*/

#ifndef FORREF
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void util(TreeNode* root, TreeNode* &prev) {
        if (!root) return;
        util(root->right, prev);
        util(root->left, prev);
        
        // stack unwinding step
        if (prev == nullptr) {
            prev = root;
            root->left = nullptr;
            root->right = nullptr;
        }
        else
        {
            root->right = prev;
            root->left = nullptr;
            prev = root;
        }
    }

    void rflatten(TreeNode* root) {
        TreeNode* prev = nullptr;
        util(root, prev);
    }

    /*
        Let's try to Flatten the Binary Tree into 
        LinkedList 

        Solution - The below implementation is based on our own custom stack
        Meaning Iterative Solution of this problem
    */
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        if (!root) return;
        TreeNode* start = nullptr;
        s.push(root);

        while (false == s.empty()) {
            // create the recursion start point
            start = s.top(); s.pop();
            
            // This is for left and right recursion
            if (start->right) s.push(start->right);
            if (start->left) s.push(start->left);

            // This is Equivalent to stack unwinding step
            if (false  == s.empty()) {
                start->right = s.top(); s.pop();
                start->left = nullptr;
                s.push(start->right);
            }
        }
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
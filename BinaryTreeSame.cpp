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
/*
    Given two binary trees, write a function to check if they are the same or not.
    
    Two binary trees are considered the same if they are structurally 
    identical and the nodes have the same value.
*/

class TreeNode {
public:
    int val;
    TreeNode* left, * right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /*
        Approach 01: Recursive one
    */
    bool isSame_r(TreeNode* h1, TreeNode* h2) {
        if (!h1 && !h2) return true;
        else if (!h1 && h2) return false;
        else if (h1 && !h2) return false;
        else if (h1->val != h2->val) return false;
        
        // than start check for childs now
        return isSame_r(h1->left, h2->left) && isSame_r(h1->right, h2->right);
    }

    /*
        Approach 02: Iterative one
        Let's convert Recursive Approach to Iterative Approach,
        using this 

    */
    bool isSame(TreeNode* h1, TreeNode* h2) {
        






        return false;
    }

};

int main(void)
{

    return 0;
}
#endif // FORREF
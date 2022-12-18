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
        using support of your own stack
    */
    bool isSameTree(TreeNode* h1, TreeNode* h2) {
        // Step 01 is to validate the input
        // and same should be copied from above recursive code as it is...
        if (!h1 && !h2) return true;
        else if (h1 && !h2) return false;
        else if (!h1 && h2) return false;
        else if (h1->val != h2->val) return false;

        // Step 02 - Let's Simulate the same recursion case in your iterative approach also
        // Let's create one stack here,
        deque<TreeNode*> systemstk; // custom syste stack

        // Push the head into the stack as equivalent to call  = bool isSame(TreeNode* h1, TreeNode* h2)
        systemstk.push_back(h1);
        systemstk.push_back(h2);

        // Iterative version here
        bool result = true;

        while (result && false == systemstk.empty()) {
            // pop the two element from the system stack
            TreeNode* p1 = systemstk.front();
            systemstk.pop_front();
            TreeNode* p2 = systemstk.front();
            systemstk.pop_front();

            // The first thing you do the check, just you are doing in recursion method
            if (!p1 && !p2) result = true;
            else if (!p1 && p2) result = false;
            else if (p1 && !p2) result = false;
            else if (p1->val != p2->val) result = false;
            
            if (p1 && p2) {
                systemstk.push_back(p1->left);
                systemstk.push_back(p2->left);
                systemstk.push_back(p1->right);
                systemstk.push_back(p2->right);
            }
        }

        return result;
    }
};

Solution sln;

int main(void)
{
    TreeNode* h1 = new TreeNode(1);
    //h1->left = new TreeNode(2);
    //h1->right = new TreeNode(3);

    TreeNode* h2 = new TreeNode(1);
 //   h2->left = new TreeNode(2);
    h2->right = new TreeNode(3);

    cout << sln.isSameTree(h1, h2) << endl;



    return 0;
}
#endif // FORREF
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
/*
    How to analyze the given problem and specially it is very much required incase of recursion.
    The below problem is giving me sense that I was not understood the porblem well in our last attempt.

    this problem is only providing me the number of nodes.

    Let me try to make this problem little more understandable
    in BST there are certain properties to be followed
    1. It a Binary Tree with some additional atributes
    2. It means it has root and max two childs ( left, right)
    3. any thing belong left should be lesser and any thing belong to right should be greater

    1. Recursion
    2. Iteration

    1. Recursion Approach 
    a. base condition
    b. do the small task, here in this problem you need to select the root,
    c. Pass the remaining to recursion to follow the sub problem solution
    d. one's theuy come back with solution our job is to integerate/combine our part into their solution,
       return back as a final solution

    n = 3, 
    arr : [1, 2, 3]
    
    case 01: 
    select arr[0] in the small step and send the remaining into the recursion flow
    
    case 02:
    select arr[1] in the small step and pass rest two part for the recursion

    and so on so forth...

    Theoritically you understood now what we ahve to do here,
    let's try to implement the same in concept

    Let's create one utility method, which will help you to do the same
*/
class Solution {
public:

    vector<TreeNode*> solve(int l, int r) {
        if (l > r) return {}; // return empty list
        
        vector<TreeNode*> out;
        for (int i = l; i <= r; ++i) {
            vector<TreeNode*> right = solve(i + 1, r);
            vector<TreeNode*> left = solve(l, i - 1);

            // integerate your small part into the sub part solved by recursion.
            TreeNode* root = new TreeNode(i);
            // add left and right part one by one
            // case 01 : where left is empty and right is also empty
            if (left.empty() && right.empty()) {
                root->left = nullptr;
                root->right = nullptr;
                out.push_back(root);
            }
            else if (left.empty()) {
                for (int j = 0; j < right.size(); ++j) {
                    root->left = nullptr;
                    root->right = right[j];
                    out.push_back(root);
                }
            }
            else if (right.empty()) {
                for (int j = 0; j < left.size(); ++j) {
                    root->left = left[j];
                    root->right = nullptr;
                    out.push_back(root);
                }
            }
            else {
                // both left && right are not empty
                for (int j = 0; j < left.size(); ++j) {
                    for (int k = 0; k < right.size(); ++k) {
                        root->left = left[j];
                        root->right = right[k];
                        out.push_back(root);
                    }
                }
            }
        }

        return out;
    }

    vector<TreeNode*> generateTrees(int n) {
//        cout << "The number of nodes arranged to produce the Unique BST : " << n << endl;
        vector<TreeNode*> result;
        result = solve(1, n);
        return result;
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
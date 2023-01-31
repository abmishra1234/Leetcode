/*
    https://www.youtube.com/watch?v=cX_kPV_foZc&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=48
    https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

    Intuition is to traverse the both node given as Node P, Q
    Than you just have to put these nodes into some map data structure 
    and count the frequency of these nodes inside your map.
    here the traversal order of node with freq 2 is maintained.
    
    So, your answer is iterate these elements in order until to the last
    node having frequence 2, and that would be the LCA required in this problem.
*/

using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

#define FORREF
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
    // BST so search is O(logn)
    void traverse_tree(TreeNode* root, TreeNode* target, 
        unordered_map<TreeNode*, int> &tmap, 
        vector<unordered_map<TreeNode*, int>::iterator> &traversed) {
        if (!root) return;

        auto it = tmap.find(root);
        if (it == tmap.end()) {
            tmap[root] = 1;
            traversed.push_back(tmap.find(root));
        }
        else
            tmap[root]++;

        if (target == root) {
            return;
        }
        else if (target->val < root->val) {
            traverse_tree(root->left, target, tmap, traversed);
        }
        else
            traverse_tree(root->right, target, tmap, traversed);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, 
        TreeNode* p, TreeNode* q) {

        vector<unordered_map<TreeNode*, int>::iterator> traversed;
        unordered_map<TreeNode*, int> tmap;

        traverse_tree(root, p, tmap, traversed);
        traverse_tree(root, q, tmap, traversed);

        auto it = traversed.begin();
        TreeNode* ans = nullptr;

        while (it != traversed.end()) {
            if ((*it)->second == 1)
                break;
            ans = (*it)->first;
            ++it;
        }
        
        return ans;
    }
};

int main(void)
{



    return 0;
}

#endif // FORREF
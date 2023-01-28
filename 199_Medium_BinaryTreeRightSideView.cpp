// https://leetcode.com/problems/binary-tree-right-side-view/description/
// https://www.youtube.com/watch?v=KV4mRzTjlAk&list=PLgUwDviBIf0q8Hkd7bK2Bpryj2xVJk8Vk&index=25

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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode*> q;
        q.push_back(root);
        
        // for collecting the level order data
        vector<vector<int>> ldata; // level by level data

        while (!q.empty()) {
            int qs = q.size();
            vector<int> v;
            for (int i = 0; i < qs; ++i) {
                TreeNode* np = q.front();
                q.pop_front();

                if (np->left) q.push_back(np->left);
                if (np->right) q.push_back(np->right);

                v.push_back(np->val);
            }
            ldata.push_back(v);
        }

        vector<int> ans;
        for (auto v : ldata) {
            ans.push_back(v[v.size() - 1]);
        }
        return ans;
    }
};

#endif // FORREF
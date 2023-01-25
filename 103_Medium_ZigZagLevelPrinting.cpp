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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        
        int order = 1; // 1 means L to R otherwise R to L
        vector<vector<int>> ans;
        while (!q.empty()) {
            int qs = q.size();
            TreeNode* np = nullptr;
            stack<TreeNode*> s;
            vector<int> level;

            if (order) {
                for (int i = 0; i < qs; ++i) {
                    np = q.front(); q.pop_front();
                    if (np->left) q.push_back(np->left);
                    if (np->right) q.push_back(np->right);
                    level.push_back(np->val);
                }
                order = (1 - order);
            }
            else
            {
                for (int i = 0; i < qs; ++i) {
                    np = q.front(); q.pop_front();
                    s.push(np);
                    if (np->left) q.push_back(np->left);
                    if (np->right) q.push_back(np->right);
                }
                while (!s.empty()) {
                    level.push_back(s.top()->val);
                    s.pop();
                }
                order = (1 - order);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
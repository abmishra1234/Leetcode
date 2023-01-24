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

/*
    The number of nodes in the tree will be in the range [0, 10^4].
    -231 <= Node.val <= 231 - 1
*/

class Solution {
public:
    void solve(TreeNode* root, int level, vector<long long int>& ans) {
        if (!root) return;
        solve(root->left, level + 1, ans);
        solve(root->right, level + 1, ans);
        if (ans[level] < root->val)
            ans[level] = root->val;
    }

    vector<int> largestValues(TreeNode* root) {
        vector<long long int> ans(10000, LONG_MIN);
        int level = 0;
        solve(root, level, ans);
        vector<int> out;
        for (int i = 0; i < 10000; ++i) {
            if (ans[i] == LONG_MIN) break;
            out.push_back(ans[i]);
        }
        return out;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
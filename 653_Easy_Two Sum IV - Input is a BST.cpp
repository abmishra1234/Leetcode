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
    
    void solve(TreeNode* root, vector<int> &nums) {
        if (!root) return;
        solve(root->left, nums);
        nums.push_back(root->val);
        solve(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        solve(root, nums);

        for (int i = 0, j = nums.size() - 1; i < j;)
        {
            if ((nums[i] + nums[j]) == k) return true;
            else if ((nums[i] + nums[j]) > k) --j;
            else ++i;
        }
        return false;
    }
};



int main(void)
{

    return 0;
}

#endif // FORREF
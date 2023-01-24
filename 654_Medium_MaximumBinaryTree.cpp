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
    TreeNode* solve(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) return new TreeNode(nums[l]);
        
        // Find the maximum value
        int maxv = INT_MIN;
        int maxv_ind = -1;
        for (int i = l; i <= r; ++i) {
            if (nums[i] > maxv) {
                maxv = nums[i];
                maxv_ind = i;
            }
        }

        TreeNode* le = solve(nums, l, maxv_ind - 1);
        TreeNode* ri = solve(nums, maxv_ind+1, r);
        TreeNode* root = new TreeNode(maxv, le, ri);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = solve(nums, 0, nums.size() - 1);
        return root;
    }
};

Solution sln;

int main(void)
{
    vector<int> nums;

    // #TC 1
    nums = { 3,2,1,6,0,5 };
    TreeNode* root = sln.constructMaximumBinaryTree(nums);

    return 0;
}

#endif // FORREF
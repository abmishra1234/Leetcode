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
class Solution {
public:
    /*
 
        https://www.codingninjas.com/codestudio/problems/combination-sum-iii_5038357?source=youtube&campaign=Recursion_Fraz&utm_source=youtube&utm_medium=affiliate&utm_campaign=Recursion_Fraz
        Every Recursion have 04 steps
        1. Identify the problem category and check does it fall under
           simillar category?
        2. Do the small task
        3. Ask recursion to do the heavy task
        4. Put the base condition
    */

    void Solve(vector<int>& nums, int i, vector<int>& subset, int k, int n, vector<vector<int>>& ans)
    {
        if (k == 0 && n == 0) {
            ans.push_back(subset);
            return;
        }

        if (i >= nums.size()) return;

        if (k == 0 && n != 0) return;

        if (n == 0 && k != 0) return;

        // let's pick the element
        subset.push_back(nums[i]);
        Solve(nums, i + 1, subset, k - 1, n - nums[i], ans);
        // let's skip the element
        subset.pop_back();
        Solve(nums, i + 1, subset, k, n, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
        vector<int> subset;
        vector<vector<int>> ans;

        Solve(nums, 0, subset, k, n, ans);
        return ans;
    }
};

Solution sln;

int main(void)
{

    return 0;
}

#endif // FORREF
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

class Solution {
public:
    /*
        This solve method is a utility method 
        to solve the actual problem.
        count <<-- this is the output parameter 
    */
    void solve(vector<int> nums, const int& target, int nums_ind, string& expression, int sum, 
        int &count, unordered_set<string> &visited) {
        // the below is the exit condition for recursion
        // and you are considering two case here 1. success and another failed

        if (nums_ind >= nums.size()) {
            // The success case is when your sum == target and the expression is unique
            if (sum == target && visited.find(expression) == visited.end()) {
                ++count;
                visited.insert(expression);
            }
            return;
        }

        string expr_bkp;

        expr_bkp = expression;
        expression = expression + '+' + to_string(nums[nums_ind]);
        // +value case
        solve(nums, target, nums_ind + 1, expression, sum + nums[nums_ind], count, visited);
        expression = expr_bkp; // backtrack
        
        // -value case
        expr_bkp = expression;
        expression = expression + '-' + to_string(nums[nums_ind]);
        // +value case
        solve(nums, target, nums_ind + 1, expression, sum - nums[nums_ind], count, visited);
        expression = expr_bkp; // backtrack
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        string expr = "";
        unordered_set<string> visited;
        solve(nums, target, 0, expr, 0, ans, visited);
        return ans;
    }
};

Solution sln;

/*
    Outcome of this approach is TLE
    Why this TLE??

    So, how to improve this problem from the brute force approach ???
    whenever Brute Force approach is not working, check does any optimisation will help us?

    For that purpose, we always have to proceed with the recursion tree and see any optimisation you can view over their ??



*/

int main() {
    vector<int> nums;
    int target, ans;

    // TC #1
    nums = { 1,1,1,1,1 }, target = 3;
    ans = sln.findTargetSumWays(nums, target);
    if (ans == 5) cout << "1. PASS" << endl;

    // TC #2
    nums = { 1 }, target = 1;
    ans = sln.findTargetSumWays(nums, target);
    if (ans == 1) cout << "2. PASS" << endl;

    return 0;
}

#endif // FORREF
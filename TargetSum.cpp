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

typedef unordered_map<string, int> UMap;

class Solution {
public:

    /*
        This is memoization approach of this problem.
    */
    int solve(vector<int>& nums, int target, int pos, UMap& memo) {
        if (pos >= nums.size()) {
            if (target == 0) return 1;
            else return 0;
        }
        
        string expression = to_string(pos) + '_' + to_string(target);
        auto it = memo.find(expression);
        if (it != memo.end()) return it->second;

        int posi = solve(nums, target - nums[pos], pos + 1, memo);
        int neg = solve(nums, target + nums[pos], pos + 1, memo);

        memo[expression] = (posi + neg);
        return memo.find(expression)->second;
    }
 
    int findTargetSumWays(vector<int>& nums, int target) {
        UMap memo;
        return solve(nums, target, 0, memo);
    }
};

Solution sln;

/*
    Outcome of this approach is TLE
    Why this TLE??

    So, how to improve this problem from the brute force approach ???
    whenever Brute Force approach is not working, check does any optimisation will help us?

    For that purpose, we always have to proceed with the recursion tree and see any optimization you can view over their ??



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

    // TC #3




    return 0;
}

#endif // FORREF
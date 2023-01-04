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

//#define FORREF
#ifndef FORREF
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // first sort this 
        sort(nums.begin(), nums.end());
        // Merge the element together of same value

        int val = nums[0];
        int sum = 0;

        vector<int> merged;

        for (int i = 0; i < nums.size(); ++i) {
            if (val == nums[i]) {
                sum += nums[i];
            }
            else
            {
                merged.push_back(sum);
                val = nums[i];
                sum = val;
            }

            if (i == nums.size() - 1) {
                merged.push_back(sum);
            }
        }

        int maxv = 0;

        int ns = merged.size();
        if (ns == 1) return merged[0];
        else if (ns == 2) return max(merged[0], merged[1]);
        else {
            vector<int> dp;
            dp.resize(ns, 0);

            dp[0] = merged[0];
            dp[1] = max(merged[0], merged[1]);

            for (int i = 2; i < ns; ++i) {
                dp[i] = max(merged[i] + dp[i - 2], dp[i - 1]);
                maxv = max(maxv, dp[i]);
            }
        }
        return maxv;
    }
};

Solution sln;

int main(void)
{
    vector<int> nums;
    int ans;


    nums = { 2,2,3,3,3,4 };
    ans = sln.deleteAndEarn(nums);
    if (ans == 9) cout << "1. PASS" << endl;

    nums = { 3,3,3,3,3,4,4,4,4,5,5,5,6,6,7,8,8 };
    ans = sln.deleteAndEarn(nums);
    if (ans == 46) cout << "2. PASS" << endl;



    return 0;
}

#endif // FORREF
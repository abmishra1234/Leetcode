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
        max value F(n) = max( nums[n] + max(n-2), max(n-1));
    */
    int rob(vector<int>& nums) {
        int ns = nums.size();
        if (ns == 1) return nums[0];
        if (ns == 2) return max(nums[0], nums[1]);

        vector<int> dp;
        dp.resize(ns + 1, INT_MIN);

        int maxval = INT_MIN;

        if (ns >= 3) {
            dp[0] = nums[0];
            dp[1] = max(nums[1], nums[0]);
            maxval = dp[2] = max(nums[2] + dp[0], dp[1]);
            for (int i = 3; i < ns; ++i) {
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
                maxval = max(maxval, dp[i]);
            }
        }
        return maxval;
    }
};


int main(void)
{



    return 0;
}

#endif // FORREF
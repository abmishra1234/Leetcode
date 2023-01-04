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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp;
        dp.resize(n + 1, -1);

        dp[0] = 0;
        dp[1] = 0;

        for (auto i = 2; i <= n; ++i)
        {
            dp[i] = min((cost[i - 1] + dp[i - 1]), (cost[i - 2] + dp[i - 2]));
        }
        return dp[n];
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF

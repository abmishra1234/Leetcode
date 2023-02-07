using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

//#define FORREF
#ifndef FORREF

class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        vector<int> dp(n + 1, 0);
        dp[1] = dp[0] = 1;
        dp[2] = 2;

        // recursive relation is like 
        // for all i = 1 to n you should multiple f(i-1) * f(n-i)
        int ans = 0;

        for (int i = 3; i <= n; ++i) {
            ans = 0;
            for (int j = 1; j <= i; ++j) {
                ans += (dp[j - 1] * dp[i - j]);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};

Solution sln;

int main(void)
{
    cout << sln.numTrees(1) << endl;
    cout << sln.numTrees(3) << endl;
    cout << sln.numTrees(19) << endl;

    return 0;
}

#endif // FORREF
// DP Problem
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
/*
    Approach to solve this problem,

    So, Let's Write your won logic to cater the below code
        auto digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    // replicate the above logic in your own implementation
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        auto digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};

Solution sln;

int main(void)
{
    int num = 2147483476;
    int ans = sln.nextGreaterElement(num);
    cout << ans << endl;
    return 0;
}

#endif // FORREF
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
    Two step process
    1. First fetch the digit from the number
    2. Swap two number by moving digits from right to left to produce bigger number 





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
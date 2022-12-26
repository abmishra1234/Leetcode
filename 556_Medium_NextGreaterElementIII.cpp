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

#define FORREF
#ifndef FORREF
/*
    Approach to solve this problem,

    So, Let's Write your won logic to cater the below code
        auto digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    // replicate the above logic in your own implementation
    TODO...
*/

class Solution {
public:
    string ToString(int n) {
        stack<int> s;
        while (n > 0) {
            s.push(n % 10);
            n /= 10;
        }
        string out = "";
        while (false == s.empty()) {
            out += ('0' + s.top());
            s.pop();
        }
        return out;
    }

    int nextGreaterElement(int n) {
        auto digits = ToString(n);
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
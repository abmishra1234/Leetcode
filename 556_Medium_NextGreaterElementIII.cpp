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

class Solution {
public:

    int nextGreaterElement(int n) {
        int bkp = n;
        deque<int> digits;
        while (n > 0) {
            digits.push_front(n % 10);
            n /= 10;
        }
        //sort(digits.begin(), digits.end());
        auto it = digits.begin();
        int sum = 0;

        int sz = digits.size();

        for (int i = sz - 2; i >= 0; --i) {
            if (digits[i] >= digits[i+1]) {
                continue;
            }
            else {
                swap(digits[i], digits[i+1]);
                break;
            }
        }

        while (it != digits.end()) {
            sum *= 10;
            sum += *it;
            ++it;
        }

        if (sum > bkp) return sum;
        else return -1;
    }
};

Solution sln;

int main(void)
{
    int num = 230241;
    int ans = sln.nextGreaterElement(num);
    cout << ans << endl;
    return 0;
}

#endif // FORREF
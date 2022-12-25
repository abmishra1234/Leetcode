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

#define FORREF
#ifndef FORREF

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        vector<int> result;
        int sz = nums.size();

        for (int i = sz - 2; i >= 0; --i) {
            // you are moving from right to left
            s.push(nums[i]);
        }

        for (int i = sz - 1; i >= 0; --i) {
            // you are moving from right to left
            while (!s.empty() && s.top() <= nums[i]) s.pop();
            if (s.empty()) result[i] = -1;
            else {
                result[i] = s.top();
                s.push(nums[i]);
            }
        }

        return result;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF
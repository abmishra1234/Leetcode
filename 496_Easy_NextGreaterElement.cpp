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
    typedef unordered_map<int, int> MyMap;
public:
    // Write one utility method for building the pre-computed map
    void solve(vector<int>& nums2, MyMap& m) {
        // I will write my logic from right to left
        stack<int> s;
        int sz = nums2.size();
        for (int i = sz - 1; i >= 0; --i) {
            if (s.empty()) {
                m[nums2[i]] = -1;
                s.push(nums2[i]);
            }
            else
            {
                if (s.top() > nums2[i]) {
                    m[nums2[i]] = s.top();
                }
                else // equal case is not the part of test cases
                {
                    while (!s.empty() && s.top() < nums2[i]) {
                        s.pop();
                    }

                    m[nums2[i]] = (s.empty()) ? -1 : s.top();
                }
                s.push(nums2[i]);
            }
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // let's build the pre computed map with nums2 array
        MyMap m;
        // the below will populate the map < value vs next greater element>
        solve(nums2, m);

        vector<int> out;
        for (int i = 0; i < nums1.size(); ++i) {
            out.push_back(m[nums1[i]]);
        }

        return out;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF
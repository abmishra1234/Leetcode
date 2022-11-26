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
    // This is the method to find the min sub array len for the condition  
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int ns = nums.size();
        int l = 0;
        int r = 0;
        int lsum = 0;

        bool done = false;

        while (l < ns && r < ns) {
            // sliding window with Expanding
            while (r < ns) {
                lsum += nums[r];
                ++r;

                if (lsum >= target) {
                    min_len = min(min_len, (r - l));
                    break;
                }
            }

            // Contracting Window
            while (l < ns && l < r) {
                if (l == r) {
                    if (lsum >= target) {
                        min_len = min(min_len, (r - l));
                    }
                    done = true;
                }

                lsum -= nums[l];
                ++l;
                if (lsum >= target) {
                    min_len = min(min_len, (r - l));
                    continue;
                }
                else
                    break;

            }
            if (done) break;
        }

        return (min_len != INT_MAX) ? min_len : 0;
    }
};


int main(void)
{
    Solution sln;
    
    // 2
    vector<int> nums2 = { 1,4,4 };
    int target = 4;
    int subArrLen = sln.minSubArrayLen(target, nums2);
    cout << "subArrLen = " << subArrLen << endl; // 1

    
    // 1
    vector<int> nums1 = { 2,3,1,2,4,3 };
    target = 7;
    subArrLen = sln.minSubArrayLen(target, nums1);
    cout << "subArrLen = " << subArrLen << endl; // 2
    
       // 3
    vector<int> nums3 = { 1,1,1,1,1,1,1,1 };
    target = 11;
    subArrLen = sln.minSubArrayLen(target, nums3);
    cout << "subArrLen = " << subArrLen << endl; // 0

    return 0;
}

#endif // FORREF
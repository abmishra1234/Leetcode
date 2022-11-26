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
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int ns = nums.size();

        int minSubArrLen = INT_MAX;

        // Sliding window cobcept need to be applied
        // i is representing the start point of slide window
        // j is the end point of sliding window
        while (i < ns) { // you are making sure that your window start index is not going beyond the nums array last index
            
            // Expanding window
            int tsum = 0; // window temp sum value
            int tlen = 0;
            while (true) {
                ++tlen;
                tsum += nums[j];
                ++j;
                if (tsum < target)
                    continue;
                else
                {
                    minSubArrLen = min(minSubArrLen, tlen);
                    break;
                }
            }

            // Contracting window


            



        }


        



    }
};


int main(void)
{
    Solution sln;
    // 1
    vector<int> nums1 = { 2,3,1,2,4,3 };
    int target = 7;
    int subArrLen = sln.minSubArrayLen(target, nums1);
    cout << "subArrLen = " << subArrLen << endl; // 2
    
    // 2
    vector<int> nums2 = { 1,4,4 };
    target = 4;
    subArrLen = sln.minSubArrayLen(target, nums2);
    cout << "subArrLen = " << subArrLen << endl; // 1
    
    // 3
    vector<int> nums3 = { 1,1,1,1,1,1,1,1 };
    target = 11;
    subArrLen = sln.minSubArrayLen(target, nums3);
    cout << "subArrLen = " << subArrLen << endl; // 0



    return 0;
}

#endif // FORREF
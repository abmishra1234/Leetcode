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
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int ns = nums.size();

        int i = 0;
        int ones_count = 0;
        while (i < ns) {
            if (nums[i] == 0) {
                if (ones_count > 0) {
                    ans = max(ans, ones_count);
                    ones_count = 0;
                }
            }
            else
                ++ones_count;
            if (i == ns - 1) // last element
            {
                if (ones_count > 0) {
                    ans = max(ans, ones_count);
                    ones_count = 0;
                }
            }
            ++i;
        }
        return ans;
    }
};


int main(void)
{
    Solution sln;
    vector<int> nums1 = { 1,1,0,1,1,1 };
    int result = sln.findMaxConsecutiveOnes(nums1);
    cout << result << endl; // 3

    vector<int> nums2 = { 1,0,1,1,0,1 };
    result = sln.findMaxConsecutiveOnes(nums2);
    cout << result << endl; // 2


    return 0;
}

#endif // FORREF
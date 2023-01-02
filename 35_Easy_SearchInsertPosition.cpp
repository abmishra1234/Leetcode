using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

#define FORREF
#ifndef FORREF
class Solution {
public:
    /*
        Algorithm:
        - Given, array is sorted
        - So, this is indicating that something is binary search could be hint here
        - So, in this problem, you just have to squeez the range 
          where you can push the element in your array.
        - leftrange = 0, rightrange = nums.size()-1;
    */
    int searchInsert(vector<int>& nums, 
        int target) {
        int ns = nums.size();

        if (target < nums[0]) return 0;
        else if (target > nums[ns-1]) return ns;

        int l = 0;
        int r = ns - 1;
        int m, ans = 0;

        while (l <= r) {
            if (l == r) {
                if (target > nums[l]) return l + 1;
                else if (target <= nums[l]) return l;
            }

            m = l + ((r - l) / 2);
            if (target == nums[m]) return m;
            else if (target > nums[m]) {
                ans = m + 1;
                l = m + 1;
            }
            else {
                ans = m - 1;
                r = m - 1;
            }
        }

        return ans;
    }
};

Solution sln;

int main(void)
{
    vector<int> nums;
    int target;
    int ans = -1;

    // TC #1
    nums = { 1,3,5,6 };
    target = 5;
    ans = sln.searchInsert(nums, target);
    if (ans == 2) cout << "1. PASS" << endl;

    // TC #2
    nums = { 1,3,5,6 };
    target = 2;
    ans = sln.searchInsert(nums, target);
    if (ans == 1) cout << "2. PASS" << endl;

    // TC #3
    nums = { 1,3,5,6 };
    target = 7;
    ans = sln.searchInsert(nums, target);
    if (ans == 4) cout << "3. PASS" << endl;


    return 0;
}

#endif // FORREF
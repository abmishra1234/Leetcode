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
    int splitArray(vector<int>& nums, int k) {
        // nums is the list of numbers given
        // the pieces or sub series possible, min = 1, max nums.size() 
        // the target solution is here in the range of (max out of nums, sum of nums number)

        int maxNum = 0;
        int sum = 0;

        // O(n) : where n is the number of element
        for (int num : nums) {
            maxNum = std::max(maxNum, num);
            sum += num;
        }

        int lo = maxNum;
        int hi = sum;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int pieces = split(nums, mid);
            if (pieces > k) {
                lo = mid + 1;
            }
            else
                hi = mid;
        }
        return lo;
    }

    int split(vector<int>& nums, int maxSumOfSplit)
    {
        int tsum = 0;
        int pieces = 1;
        
        for (int num : nums) {
            if ((tsum+num) > maxSumOfSplit) {
                tsum = num;
                pieces++;
            }
            else
                tsum += num;
        }

        return pieces;
    }
};


int main()
{



    return 0;
}



#endif
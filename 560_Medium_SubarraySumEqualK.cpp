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

//#define FORREF
#ifndef FORREF
/*
    Constraints:

    1 <= nums.length <= 2 * 104
    -1000 <= nums[i] <= 1000
    -107 <= k <= 107
    
    1. Any solution which is O(N^2) is not working
    2. Value is positive and negative both, 
       so the possibility of adding or 
       not adding have 


*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) {
                    count++;
                }
            }
            sum = 0;
        }
        return count;
    }
};

Solution sln;

int main(void)
{
    vector<int> nums = { 1,1,1 }; int k = 2;
    cout << sln.subarraySum(nums, k) << endl;

    return 0;
}

#endif // FORREF
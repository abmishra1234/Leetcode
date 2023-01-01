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
    unordered_map<int, int> m;
    int subarraySum(vector<int>& nums, int k) {
        int ns = nums.size();
        if (ns == 0) return 0;
        int count = 0;
        int prefix_sum = 0;
        m.clear();
        
        for (int i = 0; i < ns; ++i) {
            prefix_sum += nums[i];
            if (prefix_sum == k) count++;

            if (m.find(prefix_sum - k) != m.end()) {
                count += m[prefix_sum - k];
            }

            if (m.find(prefix_sum) != m.end())
                m[prefix_sum] += 1;
            else
                m[prefix_sum] = 1;
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
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
#include<climits>

#define FORREF
#ifndef FORREF

class Solution {
public:
    /*
        2 <= nums.length <= 500  
        1 <= nums[i] <= 10^3
    */
    int maxProduct(vector<int>& nums) {
        int max = 0, secmax = 0;
        if (nums[0] == nums[1]) {
            max = secmax = nums[0];
        }
        else if (nums[0] > nums[1]) {
            max = nums[0];
            secmax = nums[1];
        }
        else
        {
            max = nums[1];
            secmax = nums[0];
        }

        for (int i = 2; i < nums.size(); ++i) {
            if (max < nums[i]) {
                secmax = max;
                max = nums[i];
            }
            else if (secmax < nums[i]) {
                secmax = nums[i];
            }
        }

        return ((max - 1) * (secmax - 1));
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
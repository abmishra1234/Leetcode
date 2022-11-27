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
    // [0,0,1,1,1,2,2,3,3,4]
    int removeDuplicates(vector<int>& nums) {
        int s = nums.size();
        if (s == 0)
            return s;

        int val = nums[0];
        int len = 1;

        int i = 1;
        int j = 1;


        for (; i < s; ++i)
        {
            if (val == nums[i])
                continue;
            else
            {
                val = nums[i];
                nums[j++] = nums[i];
                ++len;
            }
        }
        return len;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
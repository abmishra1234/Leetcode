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
    int removeElement(vector<int>& nums, int val) {
        int ns = nums.size();
        int i = 0, j = ns - 1;

        int val_cnt = 0;
        for (auto v : nums) {
            if (v == val)
                val_cnt++;
        }

        if (ns == val_cnt)
            return 0;

        if (val_cnt == 0)
            return ns;


        while (i < j) {
            while (j >= 0 && nums[j] == val) {
                --j;
            }

            while (i < ns && nums[i] != val)
                ++i;
            if (i != j && i < j)
                swap(nums[i], nums[j]);
            ++i, --j;
        }
        return ns - val_cnt;
    }
};

int main(void)
{
    vector<int> nums = { 1 }; int val = 1;
    Solution sln;
    int res = sln.removeElement(nums, val);
    
    for (int i = 0; i < res; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

#endif // FORREF
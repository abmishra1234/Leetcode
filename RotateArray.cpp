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
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (k == 0 || size == k)
            return;

        if (k >= size)
            k = (k % size);

        Reverse(nums, 0, size - k - 1);
        Reverse(nums, size - k, size - 1);
        Reverse(nums, 0, size - 1);
    }

    void Reverse(vector<int>& nums, int sind, int eind) {
        if (sind >= eind)
            return;

        int temp;
        for (int i = sind, j = eind; i < j; ++i, --j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF
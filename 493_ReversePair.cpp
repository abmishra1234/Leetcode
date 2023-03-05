//--------------------------------
using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
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
private:
    void merge(vector<int>& nums, int low, int mid, int high, int& reversePairsCount) {
        // this is my custom step for this problem requirement
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2 * (long long)nums[j]) {
                j++;
            }
            reversePairsCount += (j - (mid + 1));
        }
        // below is the standard method of merge
        int size = high - low + 1;
        vector<int> temp(size, 0);
        int left = low, right = mid + 1, k = 0;
        while (left <= mid && right <= high) {
            if (nums[left] < nums[right]) {
                temp[k++] = nums[left++];
            }
            else {
                temp[k++] = nums[right++];
            }
        }
        while (left <= mid) {
            temp[k++] = nums[left++];
        }
        while (right <= high) {
            temp[k++] = nums[right++];
        }
        int m = 0;
        for (int i = low; i <= high; i++) {
            nums[i] = temp[m++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& reversePairsCount) {
        if (low < high) {
            int mid = low + ((high - low) >> 1);
            mergeSort(nums, low, mid, reversePairsCount);
            mergeSort(nums, mid + 1, high, reversePairsCount);
            merge(nums, low, mid, high, reversePairsCount);
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        int reversePairsCount = 0;
        mergeSort(nums, 0, nums.size() - 1, reversePairsCount);
        return reversePairsCount;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
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
/*
    In this implementation, we define the permute function as a public member function of the Solution class, which takes a vector of distinct integers nums and returns a vector of vectors containing all possible permutations of the elements in nums.

    To implement the permutation algorithm, we use a helper function permuteHelper that takes a vector of integers nums, a starting index start, and a vector of vectors result to store the permutations. The start index indicates the current position in the nums vector where we are swapping elements to generate permutations. If start is equal to the size of the nums vector, then we have generated a permutation and add it to the result vector.

    To generate all possible permutations, we use a for loop that iterates over the indices from start to the end of the nums vector. At each iteration, we swap the element at the start index with the element at the current index i, and then recursively call permuteHelper with start + 1 as the new starting index. After the recursive call, we swap the elements back to their original positions to backtrack and generate the next permutation.

    Finally, we call the permuteHelper function with the initial start index of 0 and an empty result vector to generate all possible permutations of the nums vector. We then return the result vector containing all the permutations.

*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteHelper(nums, 0, result);
        return result;
    }

private:
    void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            permuteHelper(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1, 2, 3 };
    vector<vector<int>> permutations = s.permute(nums);
    for (auto p : permutations) {
        for (auto num : p) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}


#endif // FORREF
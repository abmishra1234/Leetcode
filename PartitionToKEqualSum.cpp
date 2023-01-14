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
    Problem statement:
    you are given N integers and a positive integer K.
    you need to determine if it possible to divide the array
    into K non empty subsets such that the sum of elements of
    each subset is equal.

    @Note:
    1. Array might have duplicate elements
    2. Each of the array elements must belong to exactly one of the 'K' subsets.
    3. The elements chosen for a subset may not be contiguous in the array.

    @Constraints:
    1 <= T <= 10
    1 <= N <= 15
    0 <= NUMS[i] <= 10^3
    1 <= K <= N

    This is the recursion solution and by now this is giving     
    
*/

class Solution
{
public:
    bool util(int i, int bucnum, int bucsum, vector<bool>used,
        int trgsum, int K, vector<int>& nums) {
        if (bucnum >= K) return true;

        if (bucsum == trgsum) return util(0, bucnum + 1, 0, used, trgsum, K, nums);

        if (bucsum > trgsum) return false;
        if (i >= nums.size()) return false;

        if (used[i]) {
            // this perticular element is already picked
            return util(i + 1, bucnum, bucsum, used, trgsum, K, nums);
        }
        else
        {
            // there are two cases possible here for this
            //Pick the element
            used[i] = true;
            bucsum += nums[i];
            bool opt1 = util(i + 1, bucnum, bucsum, used, trgsum, K, nums);
            // redo the change done
            used[i] = false;
            bucsum -= nums[i];
            // don't pick the element
            bool opt2 = util(i + 1, bucnum, bucsum, used, trgsum, K, nums);
            return (opt1 || opt2);
        }
    }

    /*
        currently i am trying to use here
        recursion and backtrace so that you will see
        all the possibilities and than confirm, this is
        possible or not?
    */
    bool canPartitionKSubsets(vector<int>& nums, int n, int K)
    {
        int sum = 0;
        for (auto elem : nums) sum += elem;
        if (sum % K != 0) return false;

        int trgsum = sum / K;
        vector<bool> used(n, false);
        return util(0, 0, 0, used, trgsum, K, nums);
    }

};

Solution sln;

int main(void)
{

    return 0;
}

#endif // FORREF
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
class Solution {
public:
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end(), greater<int>());

        int ans = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            ans += (nums1[i] * nums2[i]);
        }

        return ans;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
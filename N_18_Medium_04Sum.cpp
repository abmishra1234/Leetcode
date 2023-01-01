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

/*
    1 <= nums.length <= 200
    -109 <= nums[i] <= 109
    -109 <= target <= 109
*/

#ifndef FORREF

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return {};
    }

    /*
        Let's build two sum problem with all the indices are unique and 
        the pair value's also Unique

        you have to  do something better than O(N^2)

        Better than O(N^2) is O(NlogN), O(N) and so on 

        Let's first try for O(NlogN) approach


    */
    vector<vector<int>> twosum(vector<int> nums, int target) {
        typedef pair<int, int> p2i;
        struct MyHash {
            auto operator()(const p2i& a) const {
                return hash<int>{}(a.first) ^ hash<int>{}(a.second);
            }

        };

        unordered_set<p2i, MyHash> uniquepair   ;

        int ns = (int) nums.size();

        if (ns == 0) return {};
        // sort the given array
        sort(nums.begin(), nums.end());
        
        int i = 0; int j = ns - 1;
        vector<vector<int>> result;
        while (i < j) {
            vector<int> v;
            if (target == (nums[i] + nums[j])) {
                if (uniquepair.find({ nums[i] , nums[j] }) == uniquepair.end()) {
                    v.push_back(nums[i]); v.push_back(nums[j]);
                    result.push_back(v);
                    v.clear();
                    uniquepair.insert({ nums[i] , nums[j] });
                }
                ++i, --j;
            }
            else if (target > (nums[i] + nums[j])) ++i;
            else --j;
        }

        return result;
    }

    vector<vector<int>> threesum(vector<int> nums, int target) {
        typedef pair<int, pair<int, int>> p3i;
        struct MyHash {
            auto operator()(const p3i& a) const {
                return hash<int>{}(a.first) 
                    ^ hash<int>{}(a.second.first)
                    ^ hash<int>{}(a.second.second);
            }
        };

        unordered_set<p3i, MyHash> uniquepair;
        int ns = (int)nums.size();

        if (ns == 0) return {};
        // sort the given array
        sort(nums.begin(), nums.end()); // nlogn

        int i = 0; int j = ns - 1;
        vector<vector<int>> result;

        // The fundamental logic required here to use the twosum solution in threesum
        // problem, but how??








        return result;
    }

};

Solution sln;

int main(void)
{
    vector<int> nums;
    int target;
    vector<vector<int>> ans;

    // TC 1
    nums = { 1,0,-1,0,0,-2,0,2 };
    target = 0;
    //ans = sln.fourSum(nums, target);
    ans = sln.twosum(nums, target);

    for (auto& v : ans) {
        for (auto& elem : v) cout << elem << " ";
        cout << endl;
    }

    // TC 2
    nums = { 0,2,2,2,2,2,4 };
    target = 4;
//    ans = sln.fourSum(nums, target);
    ans = sln.twosum(nums, target);

    for (auto& v : ans) {
        for (auto& elem : v) cout << elem << " ";
        cout << endl;
    }

    return 0;
}

#endif // FORREF
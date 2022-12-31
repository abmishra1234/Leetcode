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
    typedef pair<int, pair<int, pair<int, int>>> p4i;
    struct MyHash {
        auto operator()(const p4i& a) const {
            return hash<int>{}(a.first) 
                ^ hash<int>{}(a.second.first)
                ^ hash<int>{}(a.second.second.first) 
                ^ hash<int>{}(a.second.second.second);
        }
    };

    typedef unordered_set<p4i> UniqueValidator;
    UniqueValidator uvset;
//---------------------------------

//---------------------------------

    vector<vector<int>> fourSum(vector<int>& nums, 
        int target) {
        uvset.clear();

        /*
            4 sum -> Extension over 3sum problem
            3 sum -> Extension over 2sum problem
            2 sum -> pick any two different element from given array and their sum 
                     should be same as target element                    
        */



        


        return {};
    }
};

Solution sln;

int main(void)
{
    vector<int> nums;
    int target;
    vector<vector<int>> ans;

    // TC 1
    nums = { 1,0,-1,0,-2,2 };
    target = 0;
    ans = sln.fourSum(nums, target);

    for (auto& v : ans) {
        for (auto& elem : v) cout << elem << " ";
        cout << endl;
    }

    // TC 2
    nums = { 2,2,2,2,2 };
    target = 8;
    ans = sln.fourSum(nums, target);

    for (auto& v : ans) {
        for (auto& elem : v) cout << elem << " ";
        cout << endl;
    }

    return 0;
}

#endif // FORREF
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

    int maximumWealth(vector<vector<int>>& accounts) {
        int maxwealth = 0;
        for (auto account : accounts)
        {
            int wealth = 0;
            for (auto money : account) {
                wealth += money;
            }
            maxwealth = max(maxwealth, wealth);
        }

        return maxwealth;
    }
};



#endif 
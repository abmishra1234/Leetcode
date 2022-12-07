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

typedef pair<int, int> pii;
struct MyCmp {
    auto operator()(const pii& a, const pii& b) const {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};

typedef set<pii, MyCmp> RowSet;
RowSet rs;


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        rs.clear();

        int ri = 0;
        for (auto v : mat) {
            int one_cnt = 0;
            for (auto elem : v) {
                if (elem) ++one_cnt;
            }
            rs.insert({ one_cnt, ri });
            ++ri;
        }
        
        vector<int> result;

        while (k > 0 && !rs.empty()) {
            auto it = rs.begin();
            result.push_back(it->second);
            rs.erase(it);
            --k;
        }

        return result;
    }
};

int main(void)
{


    return 0;
}

#endif // FORREF
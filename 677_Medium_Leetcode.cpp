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
/*
    Multiple Approach possible here
    Approach 01: Using the standard set STL
*/
typedef pair<string, int> pis;
struct MyCmp {
    auto operator() (const pis& a, const pis& b) const {
        return a.first < b.first;
    }
};

typedef set<pis, MyCmp> MySet;
MySet s;

class MapSum {
public:
    MapSum() {
        s.clear();
    }

    void insert(string key, int val) {
        if (s.find({ key,0 }) != s.end()) {
            s.erase({ key,0 });
        }
        s.insert({ key, val });
    }

    int sum(string prefix) {
        int sl = prefix.length();
        auto it1 = s.lower_bound({prefix, 0});
        prefix[sl - 1]++;
        auto it2 = s.lower_bound({ prefix, 0 });

        int result = 0;
        while (it1 != it2) {
            result += it1->second;
            ++it1;
        }
        return result;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
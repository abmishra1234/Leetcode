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

class MRUQueue {
    typedef set<pair<int, int>> MySet;
    MySet s;
    int timestamp;
public:
    MRUQueue(int n) {
        timestamp = 1;
        s.clear();
        for (int i = 1; i <= n; ++i) {
            s.insert({ timestamp++, i });
        }
    }

    int fetch(int k) {
        int ans = -1;
        auto it = s.begin();
        int i = 1;
        while (i <= k && it != s.end()) {
            if (i == k) {
                ans = it->second;
                s.erase(it);// invalidated the it, so you should exit
                s.insert({ timestamp++, ans });
                break;
            }
            ++i, ++it;
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
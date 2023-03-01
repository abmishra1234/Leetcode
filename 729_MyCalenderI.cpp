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
#ifndef FORREF

typedef pair<int, int> pii;
struct MyCmp {
    auto operator()(const pii& a, const pii& b) const {
        return a.first <= b.first;
    }
};

typedef set<pii, MyCmp> MySet;

class MyCalendar {
public:
    MySet org_int;

    bool isOverlap(pii in1, pii in2) {
        int diff = min(in1.second, in2.second) - max(in1.first, in2.first);
        return (diff > 0) ? true : false;
    }

    MyCalendar() {
        org_int.clear();
    }

    bool book(int start, int end) {
        if (org_int.size() == 0) {
            org_int.insert({ start, end });
            return true;
        }

        int n = org_int.size();
        
        bool flag = false;

        auto it = org_int.begin();

        for (; it != org_int.end(); ++it) {
            flag = isOverlap({it->first, it->second}, { start, end });
            if (flag) break;
        }

        if (!flag) org_int.insert({ start, end });
        return !flag;
    }
};

int main(void)
{
    MyCalendar cal;
    bool res = cal.book(10, 20);
    cout << res << endl;

    res = cal.book(15, 25);
    cout << res << endl;


    return 0;
}

#endif // FORREF
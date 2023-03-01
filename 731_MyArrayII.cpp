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
        return a.first < b.first;
    }
};

typedef set<pii, MyCmp> MySet;
MySet calender;
MySet overlap;

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        calender.clear();
        overlap.clear();
    }

    bool isOverlap(pii in1, pii in2) {
        int diff = min(in1.second, in2.second) - max(in1.first, in2.first);
        return (diff > 0) ? true : false;
    }


    bool book(int start, int end) {
        // just check does this start and end is overlapping with the
        // member variable inside the overlap?
        for (auto it = overlap.begin(); it != overlap.end(); ++it) {
            if (isOverlap({ it->first, it->second }, { start, end })) return false;
        }

        // check into the calender
        for (auto it = calender.begin(); it != calender.end(); ++it) {
            if (isOverlap({ it->first, it->second }, { start, end })) {
                overlap.insert({ max(it->first, start), min(it->second, end) });
                return true;
            }
        }

        calender.insert({ start, end });
        return true;
    }
};



int main(void)
{
    MyCalendarTwo cal;



    return 0;
}

#endif // FORREF
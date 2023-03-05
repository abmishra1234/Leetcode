//--------------------------------
using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

// TBD
/*
    Your this problem is not yet completed, 
    please complete this problem as soon as possible.

    you probably completed your logic and now time is to complete your code
*/


#define FORREF
#ifndef FORREF

// <int, <int, int>>
// <start_time, <end_time, frequency>>
typedef pair<int, pair<int, int>> p3i;
vector<p3i> intervalArr(402);
int interval_ind;

struct srt1 {
    auto operator()(const int& ind1, const int& ind2) const {
        return intervalArr[ind1].first < intervalArr[ind2].first;
    }
};
struct srt2 {
    auto operator()(const int& ind1, const int& ind2) const {
        return intervalArr[ind1].second.second < intervalArr[ind2].second.second;
    }
};
typedef set<int, srt1> SortedSet_Start;
typedef set<int, srt2> SortedSet_Freq;



class MyCalendarThree {
    SortedSet_Start s1; // ssorted based one start time
    SortedSet_Freq s2; // sorted based ob frequency

public:
    MyCalendarThree() {
        interval_ind = 0;
        s1.clear();
        s2.clear();
    }

    void overlap(int s, int e) {
        auto it = s1.begin();
        while (it != s1.end()) {
            p3i p = intervalArr[*it];

            if()







        }







    }

    int book(int startTime, int endTime) {





    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
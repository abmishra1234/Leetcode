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

//#define FORREF
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
    
    /*
        Algorithm:
        1. Let's check the overlapping case with existing
           schedule

        2. a. NO OVERLAP ??
        you need to add new interval in
        - interval array
        - you need to insert interval into s1
        - you need to insert interval into s2

        2. b. OVERLAP ??
        different type of overlapping is possible right?

                

    
    
    */
    int book(int startTime, int endTime) {
        


    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
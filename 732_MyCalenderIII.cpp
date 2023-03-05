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

#define FORREF
#ifndef FORREF

class MyCalendarThree {
private:
    map<int, int> mp;


public:
    MyCalendarThree() {
        mp.clear();

    }

    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int kbooking = 0; int sum = 0;

        for (auto pi : mp) {
            sum += pi.second;
            kbooking = max(kbooking, sum);
        }

        return kbooking;
    }
};



int main(void)
{

    return 0;
}

#endif // FORREF

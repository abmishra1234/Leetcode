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

class Solution {
public:
    // check the overlapping
    bool isOverlap(vector<int> &in1, vector<int> &in2) {
        int diff = min(in1[1], in2[1]) - max(in1[0], in2[0]);
        return (diff >= 0) ? true : false;
    }
    vector<int> merge_interval(const vector<int> &in1, const vector<int> &in2) {
        return { min(in1[0], in2[0]), max(in1[1], in2[1]) };
    }

    // For now i am going through the linear search
    // TBD  - later change this with binary search 
    void insert_interval(vector<vector<int>>& org_int, vector<int> new_interval) {
        int n = (int)org_int.size();
        int i = 0;
        for (; i < n; ++i) {
            if (new_interval[0] < org_int[i][0]) break;
        }
        org_int.insert(org_int.begin() + i, new_interval);
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, 
        vector<int>& newInterval) {
        // the first thing is to insert the new interval in the given
        // list of intervals
        insert_interval(intervals, newInterval);

        vector<vector<int>> output;
        if (intervals.empty()) {
            output.push_back(newInterval);
            return output;
        }

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> current;
            current.push_back(start);
            current.push_back(end);
            if (isOverlap(current, intervals[i]) == false) {
                // no overlap case
                output.push_back(current);
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else {
                end = max(end, intervals[i][1]);
            }
        }

        output.push_back({start, end});

        return output;
    }
};


int main(void)
{
    Solution sln;
    
    return 0;
}

#endif // FORREF
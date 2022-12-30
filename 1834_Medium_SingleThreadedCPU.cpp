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
    In this problem, they haven't given clarity on
    index, so I am assuming here that 
    index means the task order in the tasks input task list
*/
typedef pair<int, pair<int, int>> p3i; // {index, {enqueue time, processing time}} 
/*
    sorted set vs priority queue
    So, for now I ams just taking sorted set 
    in this problem instead of priority queue.
*/
class Cmp {
public:
    auto operator()(const p3i& a, const p3i& b) const {
        if (a.second.second == b.second.second) return a.first < b.first;
        return a.second.second < b.second.second;
    }
};

/*
    @note : this is simply for sorting the tasks as per the enquetime
    Next thing, I have to ask myself that , 
    is it possible to push multiple task with same enque time?
    The answer is , for now assume that at one timestamp we do have 
    one and only task to be issued in test cases

*/
class Cmp01 {
public:
    auto operator()(const p3i& a, const p3i& b) const {
        return a.second.first < b.second.first;
    }
};


class Solution {
public:

    int curts;
    int available_from;


    void init() {
        curts = 0;
        available_from = 1;

    }

    // Method impl in progres
    /*
        Algorithm:
        Run this mehtod until the all tasks is finished.
        so if task finsihed is equal to the task planned than stop and exit from this method
        and return the order of task execution as an output

        1. start rolling the timestamp and infinite execution belt
        2. check the tasks enquetime and if this is exactly matched or 
           smaller than current time stamp, than push this task into the tasks set
           by following the proper order of processing time and index
        3. check the execution belt and if this vacant 
           or empty or ready to take new job, than pick the new job from task set and start 
           processing, also block the execution belt availability until the time(current time stamp 
           + processing time)
        4. Continue all these 03 steps one by one and stop or exit when all the tasks are finished

        5. return the order execution list to the main program
    */
    void doProcessing(const vector<vector<int>>& tasks, vector<int> &output) {
        init();
        // Sort the tasks according to the enque time of tasks
        int index = 0;
        vector<p3i> s1;
        for (auto& v : tasks) s1.push_back({ index++, {v[0], v[1]} });
        sort(s1.begin(), s1.end(), Cmp01());
        vector<p3i>::iterator it1;
        
        // the below set is the tasks in order with processing time and index based sorting
        typedef set<p3i, Cmp> OrderedTasks; OrderedTasks s2;
        OrderedTasks::iterator it2;

        int processed_cnt = 0;

        while (true) {
            ++curts;
            it1 = s1.begin();

            // This is the base condition or terminating condition for your 
            // iterative method
            if (processed_cnt == tasks.size()) break;

            while (it1 != s1.end() && it1->second.first <= curts) {
                s2.insert(*it1);
                s1.erase(it1);
                it1 = s1.begin();
            }

            // now check , the condition of execution belt availability??
            if (curts >= available_from) {
                // your execution belt available
                it2 = s2.begin();
                if (it2 == s2.end()) continue;
                // do the bunch of activity below
                {
                    // 1. push the index into the output
                    output.push_back(it2->first);
                    // 2. update the availability of execution belt, clean this task
                    available_from = (curts + it2->second.second);
                    curts += it2->second.first;
                    s2.erase(it2);
                    // update the processing count 
                    processed_cnt += 1;
                }
            }
            else
                continue; // no need to proceed further in this direction,
        }
    }

    // Method completed
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> output;
        doProcessing(tasks, output);
        return output;
    }
};

Solution sln;

int main(void)
{
    vector<vector<int>> tasks;
    vector<int> ans;

    tasks = { {1,2}, {2,4}, {3,2}, {4,1} };
    ans = sln.getOrder(tasks);
    for (auto& n : ans) cout << n << " ";
    cout << endl;

    // tc 2
    tasks = { {7,10}, {7,12}, {7,5}, {7,4}, {7,2} };
    ans = sln.getOrder(tasks);
    for (auto& n : ans) cout << n << " ";
    cout << endl;

    /*
        [[46,9],[46,42],[30,46],[30,13],[30,24],
        [30,5],[30,21],[29,46],[29,41],[29,18],
        [29,16],[29,17],[29,5],[22,15],[22,13],
        [22,25],[22,49],[22,44]]

        your output : [14,13,12,5,3,0,10,11,9,6,4,15,8,1,17,2,7,16]
        Expected    : [14,5,12,3,0,13,10,11,9,6,4,15,8,1,17,2,7,16]
    */
    // tc 3
    tasks = { {46,9}, {46,42}, {30,46}, {30,13}, {30,24},
            {30,5}, {30,21}, {29,46}, {29,41}, {29,18},
            {29,16}, {29,17}, {29,5}, {22,15}, {22,13},
            {22,25}, {22,49}, {22,44}};
    ans = sln.getOrder(tasks);
    for (auto& n : ans) cout << n << " ";
    cout << endl;



    return 0;
}

#endif // FORREF
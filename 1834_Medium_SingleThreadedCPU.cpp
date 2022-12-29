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

//#define FORREF
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
    auto operator()(const p3i& a, const p3i& b) {
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
    auto operator()(const p3i& a, const p3i& b) {
        return a.second.first < b.second.first;
    }
};


class Solution {
public:

    int curts;


    void init() {
        curts = 0;

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
        typedef set<p3i, Cmp01> SortedWithEnqTime;  SortedWithEnqTime s1;
        for (auto& v : tasks) s1.insert({ index, {v[0], v[1]} });
        SortedWithEnqTime::iterator it1 = s1.begin();
        
        // the below set is the tasks in order with processing time and index based sorting
        typedef set<p3i, Cmp> OrderedTasks; OrderedTasks s2;
        OrderedTasks::iterator it2;

        int processed_cnt = 0;

        while (true) {
            ++curts;
            // This is the base condition or terminating condition for your 
            // iterative method
            if (processed_cnt == tasks.size()) break;
            if (it1->second.first <= curts) {
                s2.insert(*it1);
                s1.erase(it1);
            }
            
            // now check , the condition of execution belt availability??
                




        }






    }

    // Method completed
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> output;
        doProcessing(tasks, output);
        return output;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
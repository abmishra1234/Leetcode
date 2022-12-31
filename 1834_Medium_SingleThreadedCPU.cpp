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

class Solution {
public:
    typedef long long int lli;
    typedef pair<int, pair<lli, lli>> p3i;
    struct Cmp_EnqueTime {
        auto operator()(const p3i& a, const p3i& b) const {
            return a.second.first < b.second.first;
        }
    };

    struct Cmp_ProcessingTime {
        auto operator()(const p3i& a, const p3i& b) const {
            if (a.second.second == b.second.second) return a.first < b.first;
            return a.second.second < b.second.second;
        }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<p3i> taskset;
        int index = 0;
        for (auto& v : tasks) {
            taskset.push_back({ index++, {v[0], v[1]} });
        }
        
        sort(taskset.begin(), taskset.end(), Cmp_EnqueTime());
        set<p3i, Cmp_ProcessingTime> processed;

        lli curts = taskset[0].second.first;
        // So you are running an Execution belt to process the task,
        // It would run until any task is available for execution
        int ts_ind = 0;
        vector<int> order;
        while (true) {
            // the block where you will find the tasks which is available for processed;
            for (; ts_ind < taskset.size() && curts >= taskset[ts_ind].second.first; 
                ++ts_ind) {
                processed.insert(taskset[ts_ind]);
            }

            if (ts_ind < taskset.size() && processed.empty()) {
                curts = taskset[ts_ind].second.first;
                continue;
            }

            if (processed.empty()) break;
            auto it = processed.begin();
            order.push_back(it->first);
            curts += it->second.second;
            processed.erase(it);
        }
        return order;
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

    // tc 3
    tasks = { {46,9}, {46,42}, {30,46}, {30,13}, {30,24},
            {30,5}, {30,21}, {29,46}, {29,41}, {29,18},
            {29,16}, {29,17}, {29,5}, {22,15}, {22,13},
            {22,25}, {22,49}, {22,44}};
    ans = sln.getOrder(tasks);
    for (auto& n : ans) cout << n << " ";
    cout << endl;

    // tc 4
    tasks = { {5,2}, {7,2}, {9,4}, {6,3}, {5,10},{1,1} };
    ans = sln.getOrder(tasks);
    for (auto& n : ans) cout << n << " ";
    cout << endl;


    return 0;
}

#endif // FORREF
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

class Solution {
public:
    int findMaximizedCapital(int k, int w, 
        vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> projects;

        for (int i = 0; i < n; ++i) {
            projects.push_back({ capital[i], profits[i] });
        }

        sort(projects.begin(), projects.end());

        int pind = 0;

        priority_queue<int> q;

        for (int i = 0; i < k; ++i) {
            while (pind < n && projects[pind++].first <= w) {
                q.push(projects[pind].second);
            }

            if (q.empty()) break;

            w += q.top();
            q.pop();
        }
        
        return w;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF

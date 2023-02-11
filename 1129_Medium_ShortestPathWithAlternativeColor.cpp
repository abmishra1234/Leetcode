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
/*
    So in this problem your graph is represented with edges
*/
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges) {
        
        // Let's prepare the adjacency list first
        // this is corresponding to red 
        vector<vector<int>> redadjlist(n, vector<int>());
        vector<vector<int>> blueadjlist(n, vector<int>());

        for (int i = 0; i < redEdges.size(); ++i) {
            redadjlist[redEdges[i][0]].push_back(redEdges[i][1]);
        }

        for (int i = 0; i < blueEdges.size(); ++i) {
            blueadjlist[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }

        // {u,{v,0}} - 0 means red
        // {u,{v,1}} - 1 means blue
        
        typedef pair<int, pair<int, int>> P3i;
        P3i p3i;
        deque<P3i> q;

        







    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
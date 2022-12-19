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
    bool solve(int n, vector<vector<int>>& adjlist,
        int source, int destination, vector<bool>& visited) {
        if (source == destination) return true;
        visited[source] = true;
        for (auto v : adjlist[source]) {
            if (visited[v] == false) {
                visited[v] == true;
                if (solve(n, adjlist, v, destination, visited)) return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, 
        int source, int destination) {
        // prepare the adjacency list from given edges
        vector<vector<int>> adjlist(n, vector<int>());

        for (auto v : edges) {
            adjlist[v[0]].push_back(v[1]);
            adjlist[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        return solve(n, adjlist, source, destination, visited);
    }
};

Solution sln;

/*
    Let's write some verification code below to test
    your implemenattion
*/
int main(void)
{

    




    return 0;
}

#endif // FORREF
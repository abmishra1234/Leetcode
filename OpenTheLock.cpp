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
    For now just concentrate on bfs but the all problem which we are able to solve through bfs 
    can also be solved from dfs, the only difference to choose of one over another is the relevance 
    with problem statement...
*/

class Solution {
    unordered_set<string> deadEndSet;
    // For bfs implementation, you have to use the queue for maintaining the order
    std::list<vector<int>>* q;
    unordered_set<string> visited;

protected:
    string GenerateString(const vector<int> &lock) {
        string out = "";
        out += to_string(lock[0]);
        out += to_string(lock[1]);
        out += to_string(lock[2]);
        out += to_string(lock[3]);

        //cout << lock[0] << " " << lock[1] << " " << lock[2] << " " << lock[3] << " " << endl;
        //cout << "Out string is : " << out << endl;

        return out;
    }
    pair<int, int> getPair(int val) {
        pair<int, int> out;
        if (val == 0) {
            out.first = 9;
            out.second = 1;
        }
        else if (val == 1) {
            out.first = 0;
            out.second = 2;
        }
        else if (val == 2) {
            out.first = 1;
            out.second = 3;
        }
        else if (val == 3) {
            out.first = 2;
            out.second = 4;
        }
        else if (val == 4) {
            out.first = 3;
            out.second = 5;
        }
        else if (val == 5) {
            out.first = 4;
            out.second = 6;
        }
        else if (val == 6) {
            out.first = 5;
            out.second = 7;
        }
        else if (val == 7) {
            out.first = 6;
            out.second = 8;
        }
        else if (val == 8) {
            out.first = 7;
            out.second = 9;
        }
        else if (val == 9) {
            out.first = 8;
            out.second = 0;
        }
        return out;
    }

public:
    /*
        minimum total number of turns required to open the lock, or -1 if it is impossible.
    */
    int openLock(vector<string>& deadends, string target) {
        deadEndSet.clear();
        visited.clear();

        /*
            You need to generate the deadend set here for searching the invalid combination
            in O(1) or const time complexity, which will help you to achieve better time
            complexity overall
        */
        for (auto s : deadends) deadEndSet.insert(s);
        if ("0000" == target) return 0;
        q = new list<vector<int>>(); // queue created for maintaining the intermediate lock state before reaching the target
        // it is holding the value in terms of number representing lock wheels
        vector<int> lock;
        // your lock initial state
        lock.resize(4, 0); 
        //GenerateString(lock); Added method for debugging the code...
     
        // push this initial lock state into queue to start with
        q->push_back(lock);
        visited.insert(GenerateString(lock));


        /*
        * Repeat until your queue is not empty??
        */

        int chngCnt = 0;

        while (q->empty() == false) {
            // pop the first element 
            vector<int> v = q->front(); // this will give you first element from linklist
            q->pop_front();

            string currStr = GenerateString(v);
            if (currStr == target) {
                cout << "Match Found!!!" << endl;
                return chngCnt;
            }

            if (deadEndSet.find(currStr) != deadEndSet.end())
                continue;

            for (int i = 0; i < 4; ++i) {
                int bkp = v[i];
                pair<int, int> pi = getPair(bkp);
                v[i] = pi.first;
                string tStr = GenerateString(v);
                if (visited.find(tStr) == visited.end()) {
                    q->push_back(v);
                    visited.insert(tStr);
                }

                v[i] = pi.second;
                tStr = GenerateString(v);
                if (visited.find(tStr) == visited.end()) {
                    q->push_back(v);
                    visited.insert(tStr);
                }
                v[i] = bkp;
            }
        }
        
        // This is the case when you don't find any possibility of reaching the target lock state        
        return -1; 
    }
};

Solution sln;

int main(void)
{
    vector<string> deadends = { "0201", "0101", "0102", "1212", "2002" };
    string target = "0202";

    cout << sln.openLock(deadends, target) << endl;

    deadends = { "8888" }, target = "0009";
    cout << sln.openLock(deadends, target) << endl;

    // ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
    deadends = { "8887","8889","8878","8898","8788","8988","7888","9888" }, target = "8888";
    cout << sln.openLock(deadends, target) << endl;

      return 0;
}

#endif // FORREF
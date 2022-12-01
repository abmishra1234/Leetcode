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
protected:
public:
    int numSquares(int n) {
        queue<pair<int, int>> q;
        vector<int> steps;
        steps.resize(n + 1, INT_MAX);
        q.push({ n,0 });
        steps[n] = 0;
        
        int ans = INT_MAX;

        while (q.empty() == false) {
            pair<int, int> pi = q.front();
            q.pop();

            if (pi.first == 0) return pi.second;

            for (int x = sqrt(pi.first); x >= 1; --x) {
                // validity check is required and optimisation is required here...
                if ((pi.first - (x * x)) >= 0 && (1 + pi.second) < steps[pi.first - (x * x)]) { 
                    steps[pi.first - (x * x)] = min(1 + pi.second, steps[pi.first - (x * x)]);
                    q.push({ pi.first - (x * x), steps[pi.first - (x * x)] });
                }
            }
        }

        return 0;
    }
};




Solution sln;


int main(void)
{   
    cout << sln.numSquares(13) << endl;
    cout << sln.numSquares(12) << endl;
    cout << sln.numSquares(11) << endl;
    cout << sln.numSquares(4) << endl;

    return 0;
}

#endif // FORREF
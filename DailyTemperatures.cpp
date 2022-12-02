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
#define DISABLE
#ifndef FORREF

class Solution {
public:
#ifndef DISABLE
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        stack<int> stk; // to maintain the higher value from back
        
        int ns = temperatures.size();
        result.resize(ns, 0);

        int i = ns - 1;
        
        while (i >= 0) {
            if (stk.empty()) result[i] = 0;
            else
            {
                if (temperatures[i] < temperatures[stk.top()]) result[i] = stk.top() - i;
                else {
                    // pop the element from stack until top element is greater in value
                    // or stk become empty
                    while (stk.empty() == false && temperatures[i] >= temperatures[stk.top()]) stk.pop();
                    continue;
                }
            }
            stk.push(i);
            --i;
        }
        return result;
    }
#endif // DISABLE

    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> result;
        int ns = temp.size();
        result.resize(ns, -1);

        int i = ns - 1;
        while ( i >= 0) {
            if (i == ns - 1) result[i] = 0;
            else
            {
                if (temp[i] < temp[i + 1]) result[i] = 1;
                else
                {
                    int tind = i+1;
                    while (tind < ns && result[tind] != 0 && temp[i] >= temp[tind]) tind += result[tind];
                    result[i] = (tind == (i+1) || temp[i] >= temp[tind]) ? 0 : (tind - i);
                }
            }
            --i;
        }
        return result;
    }
};

Solution sln;

int main() {
    vector<int> input;
    vector<int> result;
    
    input = { 55,38,53,81,61,93,97,32,43,78 };
    result = sln.dailyTemperatures(input); // 1,1,4,2,1,1,0,0
    
    if (result == vector<int>({ 3,1,1,2,1,1,0,1,1,0 })) cout << "1. PASS" << endl;




}

#endif // FORREF
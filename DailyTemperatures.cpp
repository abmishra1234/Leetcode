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

class Solution {
public:
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
};

Solution sln;

int main() {
    vector<int> input;
    vector<int> result;
    
    input = { 73,74,75,71,69,72,76,73 };
    result = sln.dailyTemperatures(input); // 1,1,4,2,1,1,0,0
    
    if (result == vector<int>({ 1, 1, 4, 2, 1, 1, 0, 0 })) cout << "1. PASS" << endl;

    input = { 30,40,50,60 };
    result = sln.dailyTemperatures(input); // 1,1,1,0

    if (result == vector<int>({ 1,1,1,0 })) cout << "2. PASS" << endl;

    input = { 30,60,90 };
    result = sln.dailyTemperatures(input); // 1,1,0

    if (result == vector<int>({ 1,1,0 })) cout << "3. PASS" << endl;



}

#endif // FORREF
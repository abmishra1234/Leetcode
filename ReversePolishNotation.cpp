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
    bool isOperator(string str) {
        if (str == "+" || str == "-" || str == "*" || str == "/") return true;
        return false;
    }
    int str2int(string str) {
        int pi = 0;
        int res = 0;
        int sl = str.length();

        if (sl == 0) return 0;

        for (int i = sl - 1; i >= 0; --i) {
            if (str.at(i) == '-') return (-1 * res);
            else
                res = res + ((int) pow(10,pi) * (str.at(i) - '0'));
            ++pi;
        }

        return res;
    }

public:
    /*
        Selection of data type instead of int is one key note here in problem,
        otherwise you will get overflow issue in your solution.
    */
    long long int evalRPN(vector<string>& tokens) {
        stack<long long int> stk;
        for (auto s : tokens) {
            if (isOperator(s)) {
                long long int oper1 = stk.top();
                stk.pop();
                long long int oper2 = stk.top();
                stk.pop();

                if (s == "+") stk.push(oper2 + oper1);
                else if(s == "-") stk.push(oper2 - oper1);
                else if (s == "*") stk.push(oper2 * oper1);
                else if (s == "/") stk.push(oper2 / oper1);
            }
            else
            {
                long long int oper = str2int(s);
                stk.push(oper);
            }
        }
        return stk.top();
    }
};

Solution sln;

int main() {

    vector<string> input;
    long long int ans;

    input = { "2","1","+","3","*" };
    ans = sln.evalRPN(input);
    if (ans == 9) cout << "1. PASS" << endl;

    input = { "4","13","5","/","+" };
    ans = sln.evalRPN(input);
    if (ans == 6) cout << "2. PASS" << endl;

    input = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    ans = sln.evalRPN(input);
    if (ans == 22) cout << "3. PASS" << endl;



}

#endif // FORREF
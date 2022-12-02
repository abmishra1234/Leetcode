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
    bool isValid(string s) {
        stack<char> stk;

        for (auto c : s) {
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            else
            {
                if (stk.empty()) return false;
                char ch = stk.top();
                stk.pop();

                if (c == ')' && ch != '(') return false;
                else if (c == '}' && ch != '{') return false;
                else if (c == ']' && ch != '[') return false;
            }
        }

        return (stk.empty()) ? true : false;
    }
};

Solution sln;

int main(void)
{
    cout << sln.isValid("()") << endl;
    cout << sln.isValid("()[]{}") << endl;
    cout << sln.isValid("(]") << endl;

    return 0;
}

#endif // FORREF
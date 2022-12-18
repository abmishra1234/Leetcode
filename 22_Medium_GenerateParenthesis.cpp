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

/*
    So our task is to write solution using both approach
    ==>> start with recursive and complete with iterative 
*/

//#define FORREF
#ifndef FORREF
/*
    Let's try first approach with recursion.
*/
class Solution {
public:

    void solve(int openparen, int closeparen, string &output, vector<string> &ans)
    {
        if(openparen == closeparen && openparen == 0) {
            ans.push_back(output);
            return;
        }

        if (openparen == closeparen && openparen != 0) {
            output += '(';
            solve(openparen - 1, closeparen, output, ans);
        }

        if (openparen < closeparen) {
            if (openparen == 0) {
                output += ')';
                solve(openparen, closeparen - 1, output, ans);
            }
            else if(openparen > 0) {
                string temp = output;
                output += '(';
                solve(openparen - 1, closeparen, output, ans);
                output = temp;
                output += ')';
                solve(openparen, closeparen - 1, output, ans);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        // n means here, you have n number of open and close parenthesis here.
        int openparen = n;
        int closeparen = n;

        string output = "";
        vector<string> ans;

        solve(openparen, closeparen, output, ans);
        return ans;
    }
};

Solution sln;

int main(void)
{
    int n = 2;
    vector<string> ans = sln.generateParenthesis(n);
    
    for (auto s : ans) {
        cout << s << " ";
    }
    cout << endl;


    return 0;
}

#endif // FORREF
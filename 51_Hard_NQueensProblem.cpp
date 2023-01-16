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
    /*
        Let's implement this solution using DFS and backtrack
    */

    typedef vector<vector<char>> v2c;

    void solve(v2c &board, int row, int nqueen, vector<v2c> &ans, 
        vector<int> &col, vector<int> &tl, vector<int> &tr) {
        if (row >= board.size()) {
            if (nqueen == 0) ans.push_back(board);
            return;
        }
        
        // by this time, you have row number and now you just have to find the
        // col number in grid to place the queen
        for (int i = 0; i < board[0].size(); ++i) {
            /*
                valid means here with the plaing of queen at [row, i] is valid
                and don't attacking by any existing queen [on row, col and diagonal]
            */
            if (!col[i] && !tl[row-i+ board.size() - 1] && !tr[row + i]) {
                board[row][i] = 'Q';
                col[i] = tl[row - i + board.size() - 1] = tr[i + row] = 1;
                solve(board, row + 1, nqueen-1, ans, col, tl, tr);
                // backtrace step
                board[row][i] = '.';
                col[i] = tl[row - i + board.size() - 1] = tr[i + row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        v2c board(n, vector<char>(n, '.'));
        vector<v2c> ans;
        
        // for optimisation of validity check
        vector<int> col(n, 0);
        vector<int> tl(2 * n+1, 0);
        vector<int> tr(2 * n+1, 0);

        solve(board, 0, n, ans, col, tl, tr);
        vector<vector<string>> result;
        
        for (v2c item : ans) {
            vector<string> vs;
            for (vector<char> v : item) {
                string out = "";
                for (char c : v) {
                    out += c;
                }
                vs.push_back(out);
            }
            result.push_back(vs);
        }
        return result;
    }
};

// - 
Solution sln;

int main(void)
{
    int n = 4;

    vector<vector<string>> ans = sln.solveNQueens(n);
    cout << ans.size() << endl << endl;

    for (auto vs : ans) {
        for (auto s : vs) {
            cout << s << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

#endif // FORREF
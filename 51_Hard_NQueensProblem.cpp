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

    bool valid(v2c& board, int r, int c) {
        int R = board.size();
        int C = board[0].size();

        if (r < 0 || r >= R) return false;
        // @Note: Col might not be out of range in anycase so
        // you might remove later. For now leave this as it is...
        if (c < 0 || c >= C) return false;

        // diagonal d1
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }

        // vertical up
        for (int i = r - 1; i >= 0; --i) {
            if (board[i][c] == 'Q') return false;
        }

        // diagonal d2
        for (int i = r - 1, j = c + 1; i >= 0 && j < C; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }

    void solve(v2c &board, int row, int nqueen, vector<v2c> &ans) {
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
            if (valid(board, row, i)) {
                board[row][i] = 'Q';
                solve(board, row + 1, nqueen - 1, ans);
                // backtrace step
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        v2c board(n, vector<char>(n, '.'));
        vector<v2c> ans;
        solve(board, 0, n, ans);

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
    int n = 5;

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
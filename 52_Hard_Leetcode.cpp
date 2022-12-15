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
    Note in this problem is for you to first
    solve problem by own and later check the other solution also 
    and compare your solution with other's best solution and see'
    the gap if any and improve on that case handling here in this 
    problem.
*/

//#define FORREF
#ifndef FORREF

class Solution {
public:
    bool check_vert(vector<vector<int>>& matrix, int row, int col) {
        for (int x = row; x >= 0; --x) {
            if (matrix[x][col]) return false;
        }
        return true;
    }

    bool check_d1(vector<vector<int>>& matrix, int row, int col) {
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j) {
            if (matrix[i][j]) return false;
        }
        return true;
    }

    bool check_d2(vector<vector<int>>& matrix, int row, int col) {
        for (int i = row - 1, j = col + 1; i >= 0 && j < matrix[0].size(); --i, ++j) {
            if (matrix[i][j]) return false;
        }
        return true;
    }

    // Utility method
    void solve(vector<vector<int>> &matrix, int n, int row, int& ans) {
        if (n == 0) {
            ans++;
            return;
        }
        if (row >= matrix.size()) return;

        for (int x = 0; x < matrix[0].size(); ++x) {
            bool chk_v = check_vert(matrix, row, x);
            bool chk_d1 = check_d1(matrix, row, x);
            bool chk_d2 = check_d2(matrix, row, x);

            if (chk_v && chk_d1 && chk_d2) {
                // set the queen
                matrix[row][x] = 1;
                solve(matrix, n - 1, row + 1, ans);
                // reset the queen pos
                matrix[row][x] = 0; // backtrack step
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int ans = 0;
        solve(matrix, n, 0, ans);
        return ans;
    }
};

Solution sln;

int main(void)
{
    int n;
    int ans;

    // tc #1
    n = 4;
    ans = sln.totalNQueens(n);
    if (ans == 2) cout << "1. PASS" << endl;

    // tc #2
    n = 1;
    ans = sln.totalNQueens(n);
    if (ans == 1) cout << "2. PASS" << endl;

    // tc #3
    n = 9;
    ans = sln.totalNQueens(n);
    if (ans == 352) cout << "3. PASS" << endl;

    return 0;
}

#endif // FORREF
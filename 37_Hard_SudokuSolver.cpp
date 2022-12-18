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
#define MAXN 9
class Solution {
    unordered_set<int> rows[9];
    unordered_set<int> cols[9];
public:
    Solution() {
        for (int i = 0; i < MAXN; ++i) {
            rows[i].clear();
            cols[i].clear();
        }
    }

    void solve()


    void solveSudoku(vector<vector<char>>& board) {
        // So you are setting the value into the perticular set
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                if (board[i][j] != '.') {
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                }
            }
        }






    }
};




int main(void)
{

    return 0;
}

#endif // FORREF
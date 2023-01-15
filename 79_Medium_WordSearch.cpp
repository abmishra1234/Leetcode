// https://leetcode.com/problems/word-search/
//  Recursion & backtracing is the key to Practice here
using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

#define FORREF
#ifndef FORREF
class Solution {
public:
    bool check(int r, int c, int R, int C) {
        if (r < 0 || r >= R) return false;
        if (c < 0 || c >= C) return false;
        return true;
    }

    bool solve(int r, int c, int strind, vector<vector<bool>>& visited,
        vector<vector<char>>& board, string word) {

        if (strind == word.length()) return true;
        if (check(r, c, board.size(), board[0].size()) == false) return false;
        if (board[r][c] != word[strind]) return false;
        if (visited[r][c]) return false;

        // assuming that this cell is holding the character same as word[strind]
        visited[r][c] = true;

        // let's explore all the possible path
        bool lsearch = false, usearch = false, rsearch = false, dsearch = false;

        // for left
        lsearch = solve(r, c - 1, strind + 1, visited, board, word);
        if (lsearch) return true;

        // for up
        usearch = solve(r - 1, c, strind + 1, visited, board, word);
        if (usearch) return true;

        // for right
        rsearch = solve(r, c + 1, strind + 1, visited, board, word);
        if (rsearch) return true;

        // for down
        dsearch = solve(r + 1, c, strind + 1, visited, board, word);
        if (dsearch) return true;

        visited[r][c] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int R = board.size();
        int C = board[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        bool result = false;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (board[i][j] == word[0]) {
                    result = solve(0, 0, 0, visited, board, word);
                    if (result) return true;
                }
            }
        }
        return false;
    }
};

Solution sln;

int main(void)
{
    vector<vector<char>> board;
    string word;
    bool res = false;

    board = { {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} };
    word = "ABCCED";
    res = sln.exist(board, word);

    return 0;
}

#endif // FORREF
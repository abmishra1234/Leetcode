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
    #define f(i,m,n) for(int i=m; i<n; i+=1)
    typedef pair<int, int> pii;

    // So to manage the validity you need three set like below to check
    typedef unordered_set<char> MySet;
    

//----------------------------------
    void precache(vector<pii>& emptyplaces, vector<vector<char>>& board, 
        MySet rowset[], MySet colset[], MySet set3X3[]) {
        f(i, 0, board.size()) {
            f(j, 0, board[0].size()) {
                if (board[i][j] == '.') emptyplaces.push_back({ i,j });
                else {
                    rowset[i].insert(board[i][j]);
                    colset[j].insert(board[i][j]);
                    set3X3[3 * (i / 3) + (j / 3)].insert(board[i][j]);
                }
            }
        }
    }

    bool valid(MySet rowset[], MySet colset[], MySet set3X3[], int row, int col, int num) {
        // the same number is already present in this row
        if (rowset[row].find(num) != rowset[row].end()) return false;

        // the same number is already present in this col
        if (colset[col].find(num) != colset[col].end()) return false;

        // the same check will be used here for verifying the 3X3 square position and validation
        if (set3X3[3*(row/3) + (col/3)].find(num) != set3X3[3 * (row / 3) + (col / 3)].end()) return false;
    
        // if all these check passed than you should allow this insertion and so return true
        return true;
    }

    /*
        Write one recursive method for handling the backtrack,
        This method is primarily two responsibility, dfs and backtrack
        So, how you will deal this concept here in code,
    */
    bool solve(vector<vector<char>>& board, vector<pii>& emptyplaces, int pos,
        MySet rowset[], MySet colset[], MySet set3X3[]) {
        
        // first base condition - when you filled all the values at all empty places, your game is over
        if (pos >= emptyplaces.size()) return true;

        bool result = false;

        for (int num = '1'; num <= '9'; ++num) {
            if (valid(rowset, colset, set3X3, emptyplaces[pos].first, emptyplaces[pos].second, num)) {
                board[emptyplaces[pos].first][emptyplaces[pos].second] = num;
                rowset[emptyplaces[pos].first].insert(num);
                colset[emptyplaces[pos].second].insert(num);
                set3X3[3 * (emptyplaces[pos].first / 3) + (emptyplaces[pos].second / 3)].insert(num);
                pos++;
                
                result = solve(board, emptyplaces, pos, rowset, colset, set3X3);
                if (result) return true;

                // below four line is backtrack steps
                --pos;
                board[emptyplaces[pos].first][emptyplaces[pos].second] = '.';
                rowset[emptyplaces[pos].first].erase(num);
                colset[emptyplaces[pos].second].erase(num);
                set3X3[3 * (emptyplaces[pos].first / 3) + (emptyplaces[pos].second / 3)].erase(num);
            }
        }
        
        return result;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<pii> emptyplaces;
        MySet rowset[9];
        MySet colset[9];
        MySet set3X3[9];
       
        // Step 01, precache the empty places, and existing row, col, 3X3 board state
        precache(emptyplaces, board, rowset, colset, set3X3);
        
        // step 02
        solve(board, emptyplaces, 0, rowset, colset, set3X3);
    }
};

Solution sln;

int main(void)
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    for (auto v : board) {
        for (auto elem : v) {
            cout << elem << " ";
        }
        cout << endl;
    }


    sln.solveSudoku(board);

    for (auto v : board) {
        for (auto elem : v) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

#endif // FORREF
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

enum DIRS {
    RI = 0,
    DO = 1,
    LE = 2,
    TO = 3
};

class Solution {
public:
    // Print the matrix in spiral order
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nr = (int) matrix.size();
        int mc = (int) matrix[0].size();

        vector<int> result;
        int nElem = nr * mc;
        int dir = 0;

        int stRow = 0;
        int endRow = nr - 1;
        int stCol = 0;
        int endCol = mc - 1;

        int r = stRow, c = stCol;

        while (nElem > 0) {

            if (dir % 4 == DIRS::RI) {
                for (; c <= endCol; ++c) {
                    result.push_back(matrix[r][c]);
                    --nElem;
                }
                ++stRow;
                r = stRow;
                c = endCol;
                dir++;
                continue;
            }

            if (dir % 4 == DIRS::DO) {
                for (; r <= endRow; ++r) {
                    result.push_back(matrix[r][c]);
                    --nElem;
                }
                --endCol;
                c = endCol;
                r = endRow;
                dir++;
                continue;
            }

            if (dir % 4 == DIRS::LE) {
                for (; c >= stCol; --c) {
                    result.push_back(matrix[r][c]);
                    --nElem;
                }

                --endRow;
                r = endRow;
                c = stCol;
                dir++;
                continue;
            }

            if (dir % 4 == DIRS::TO) {
                for (; r >= stRow; --r) {
                    result.push_back(matrix[r][c]);
                    --nElem;
                }

                ++stCol;
                r = stRow;
                c = stCol;
                dir++;
                continue;
            }
        }
        return result;
    }
};

int main(void)
{
    Solution sln;
    vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result = sln.spiralOrder(matrix);

    for (int elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}

#endif // FORREF
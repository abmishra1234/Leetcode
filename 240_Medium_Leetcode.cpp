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
    bool bsearch(vector<vector<int>>& matrix, int row, const int maxC, int target) {
        int l = 0;
        int r = maxC;
        while (l <= r) {
            if (l == r) {
                if (matrix[row][l] == target) return true;
                else return false;
            }
            int m = l + ((r - l) >> 1);
            if (matrix[row][m] == target) return true;
            else if (matrix[row][m] < target) l = m + 1;
            else r = m - 1;
        }
        return false;
    }

    /*
        In this problem my time complexity will be O((m+n)*log(m+n))
        O(NlogN) // N = m+n
    */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size();
        int C = matrix[0].size();

        // This is the case when it is better to check the binary search in all rows
        int l = 0, r = R-1;
        while (l <= r) {
            if(bsearch(matrix, l, C-1, target)) return true;
            ++l;
        }
        return false;
    }
};

Solution sln;

int main(void)
{
    vector<vector<int>> matrix = { {1,4,7,11,15}, {2,5,8,12,19}, 
        {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30} };

    int target = 5;
    bool ans = sln.searchMatrix(matrix, target);
    if (ans == true) cout << "1. PASS" << endl;

    target = 20;
    ans = sln.searchMatrix(matrix, target);
    if (ans == false) cout << "2. PASS" << endl;


    return 0;
}

#endif // FORREF
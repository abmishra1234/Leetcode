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

// Diagonal Traversing  
#define FORREF
#ifndef FORREF
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int i = 0, j = 0, n = mat.size(), m = mat[0].size(), add = -1;
        res.push_back(mat[i][j]);
        while (i < n - 1 || j < m - 1) {
            if (j < m - 1 && ((i == 0 && add == -1) || (i == n - 1 && add == 1))) {
                ++j;
                add = -add;
            }
            else if ((j == 0 && add == 1) || (j == m - 1 && add == -1)) {
                ++i;
                add = -add;
            }
            else {
                i += add;
                j -= add;
            }
            res.push_back(mat[i][j]);
        }
        return res;
    }
};

Solution sln;

int main() {
    cout << "Lets begin..." << endl;
    vector<vector<int>> mat = { {1,2,3}, {4,5,6}, {7,8,9} };
    vector<int> result = sln.findDiagonalOrder(mat);
    
    // print the result below for verification
    for (auto elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}




#endif // FORREF
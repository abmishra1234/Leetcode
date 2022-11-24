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
//#define FORREF
#ifndef FORREF

class Solution {
public:
    void printMatrix(vector<vector<int>>& mat) {
        for (auto v : mat) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    // What is the Dynamic Array Elements here
    void printDynamicArray(vector<int> arr) {
        for (int elem : arr) {
            cout << elem << " ";
        }
        cout << endl;
    }

public:
    // nr is the number of rows in grid or matrix
    // nc is the number of cols in grid or matrix
    bool isValidPosition(int r, int c, int nr, int mc) {
        // @Note : Considering that r and c is the 0 based index here.
        if (r < 0 || r >= nr)
            return false;

        if (c < 0 || c >= mc)
            return false;

        return true;
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // to collect your answer in this vector
        vector<int> out;

        // starting from diagonal up





        return out;
    }




};

Solution sln;


int main() {
    vector<vector<int>> mat = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };
    // for making your ansewer
    sln.printMatrix(mat);
    vector<int> answer;
    answer = sln.findDiagonalOrder(mat);



    return 0;
}



#endif // FORREF
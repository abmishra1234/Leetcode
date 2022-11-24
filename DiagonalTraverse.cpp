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
    // move method for moving the forward direction
    void move(bool forward, int& r, int& c) {
        if (forward) {
            r--;
            c++;
        }
        else
        {
            r++;
            c--;
        }
    }
    void check(int& r, int& c, const int nr, const int nc, bool &forward) {
        bool change = false;
        // for row
        if (r < 0) {
            r = 0;
            forward = !forward;
        }
        
        if (r >= nr) {
            r = nr - 1;
            c++;
            forward = !forward;
            check(r, c, nr, nc, forward);
        }

        // for column
        if (c < 0) {
            c = 0;
            change = true;
        }
        
        if (c >= nc) {
            c = nc - 1;
            r++;
            forward = !forward;
            check(r, c, nr, nc, forward);
        }
    }
public:
    /*
        TODO : DO the dry run of the code

    */
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        int nr = (int) mat.size();
        cout << "nr = " << nr << endl; // 3
        
        if (nr == 0) {
            cout << "Matrix dimension is wrong, please takecare!!!" << endl;
            return result;
        }

        int nc = (int) mat[0].size();
        cout << "nc = " << nc << endl; // 3

        int elementCnt = nr * nc;
        cout << "elementCnt = " << elementCnt << endl; // 9


        int r = 0;
        int c = 0;
        bool forward = true;

        while (elementCnt > 0) {
            check(r, c, nr, nc, forward); // {-1, 1}
            result.push_back(mat[r][c]); // the element pushed : 1, 2
            --elementCnt;
            move(forward, r, c); // r = -1, c = 1
        }
        return result;
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
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
/*
    Let's print the pascal triangle below
    Let's give number of row is 5
    rowInd will be 0,1,2,3,4

*/
class PascalTriangleII {
    int nRow; // number of Row assigned while creating the object
    vector<vector<int>> pascalVact;
public:
    PascalTriangleII(int nr) {
        nRow = nr;

    }

    void Prepare() {
        cout << "Print the pascal Triangle below" << endl;


        for (int r = 0; r < nRow; ++r) {
            vector<int> prow;
            for (int c = 0; c < r + 1; ++c) {
                if (c == 0 || c == r) {
                    //cout << 1 << " ";
                    prow.push_back(1);
                }
                else
                {
                    prow.push_back(pascalVact[r - 1][c - 1] + pascalVact[r - 1][c]);
                    //cout << pascal[r - 1][c - 1] + pascal[r - 1][c] << " ";
                }
            }
            //cout << endl;
            pascalVact.push_back(prow);
        }
        //cout << endl;
    }

    vector<int> getRow(int rowIndex) {
        return pascalVact[rowIndex];
    }

};

PascalTriangleII p2(34);

int main(void)
{
    p2.Prepare();

    vector<int> result = p2.getRow(3);
    for (auto elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    result = p2.getRow(0);
    for (auto elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    result = p2.getRow(1);
    for (auto elem : result) {
        cout << elem << " ";
    }
    cout << endl;



    return 0;
}

#endif // FORREF
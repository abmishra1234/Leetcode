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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        for (int i = 1; i <= numRows; ++i) {
            pascal[i - 1] = vector<int>(i, 1);
        }

        for (int i = 2; i < numRows; ++i) {
            for (int j = 1; j < i; ++j) {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }

        return pascal;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
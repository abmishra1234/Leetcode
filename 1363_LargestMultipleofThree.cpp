using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<climits>

#define FORREF
#ifndef FORREF
class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        string res = "";
        int m1[] = { 1,4,7,2,5,8 };
        int m2[] = { 2,5,8,1,4,7 };

        int sum = 0;

        // this array is going to hold the digit count  
        // 0 ~ 9
        int ds[10] = {0};

        for (auto d : digits) {
            ds[d]++;
            sum += d;
        }

        while (sum % 3 != 0) {
            for (auto i : sum % 3 == 1 ? m1 : m2) {
                if (ds[i]) {
                    --ds[i];
                    sum -= i;
                    break;
                }
            }
        }
        
        for (int i = 9; i >= 0; --i) {
            res += string(ds[i], ('0' + i));
        }

        return res.size() && res[0] == '0' ? "0" : res;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
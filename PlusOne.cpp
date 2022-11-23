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
    vector<int> plusOne(vector<int>& digits) {
        int ns = digits.size();

        vector<int> out(ns + 1, 0);
        int sum = 0;
        int rem = 0;

        for (int i = ns - 1; i >= 0; --i) {
            if (i == ns - 1) {
                sum = 1;
            }
            sum = sum + rem + digits[i];
            rem = 0;
            if (sum >= 10) {
                rem = sum / 10;
                out[i + 1] = sum % 10;
            }
            else
                out[i + 1] = sum;
            sum = 0;

            if (i == 0) {
                if (rem > 0) {
                    out[0] = rem;
                }
                else
                {
                    for (int i = 1; i <= ns; i++) {
                        out[i - 1] = out[i];
                    }
                    out.pop_back();
                }
            }
        }
        return out;
    }
};

int main() {



    return 0;
}



#endif // FORREF
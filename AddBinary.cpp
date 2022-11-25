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
    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }
        if (carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(void)
{
    string a = "11";
    string b = "1";
    Solution sln;
    string out = sln.addBinary(a, b);
    cout << "Final Output string : " << out << endl;

    return 0;
}

#endif // FORREF
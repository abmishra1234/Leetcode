using namespace std;
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<list>
#include<forward_list>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>

#define FORREF
#ifndef FORREF
class Solution {
public:
    // You should reverse the character btn l and r inclusive inside string s
    void revstr(string& s, int l, int r) {
        while (l < r) {
            char ch = s.at(r);
            s[r] = s[l];
            s[l] = ch;
            ++l, --r;
        }
    }
    string reverseStr(string s, int k) {
        int sl = (int) s.size();

        int l = 0;
        int r = sl - 1;

        while (l < r) {
            if ((r - l + 1) < k) {
                revstr(s, l, min(r, l + k - 1));
                break;
            }
            else if ((r - l + 1) < (2 * k) && ((r - l + 1) >= k)) {
                revstr(s, l, l + k - 1);
                break;
            }
            else
            {
                revstr(s, l, l + k - 1);
                l = l + (2 * k);
            }
        }
        return s;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
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
    void convert(string s, string &outstr) {
        for (auto& ch : s) {
            if (ch >= 'A' && ch <= 'Z') outstr += (ch + 32);
            else if(ch >= 'a' && ch <= 'z') outstr += ch;
            else if (ch >= '0' && ch <= '9') outstr += ch;
        }
        //cout << outstr << endl;
    }

    bool isPalindrome(string s) {
        string outstr = "";
        convert(s, outstr);
        int i = 0, j = outstr.length() - 1;
        while (i < j) {
            if (outstr.at(i) != outstr.at(j)) return false;
            ++i, --j;
        }

        return true;
    }
};

Solution sln;

int main(void)
{
    cout << sln.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sln.isPalindrome("race a car") << endl;

    return 0;
}

#endif // FORREF
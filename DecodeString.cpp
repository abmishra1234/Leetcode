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

/*
    Constraints:
    1 <= s.length <= 30
    s consists of lowercase English letters, digits, and square brackets '[]'.
    s is guaranteed to be a valid input.
    All the integers in s are in the range [1, 300].
*/

#define FORREF
#ifndef FORREF

class Solution {
public:
    string decodeString(string s) {
        string output = "";
        stack<char> charStk;
        stack<int> intStk;

        int n = s.length();
        int factor = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] >= 0 && s[i] <= '9') {
                factor = (factor * 10) + (s[i] - '0');
            }
            else if (s[i] == '[') {
                intStk.push(factor);
                factor = 0;
                charStk.push(s[i]);
            }
            else if (s[i] == ']') {
                string tstr = "";
                while (charStk.top() != '[') {
                    tstr = charStk.top() + tstr;
                    charStk.pop();
                }
                charStk.pop();

                int mult = intStk.top();
                intStk.pop();
                for (int i = 0; i < mult; ++i) {
                    for (int j = 0; j < tstr.length(); ++j) {
                        charStk.push(tstr[j]);
                    }
                }
            }
            else {
                charStk.push(s[i]);
            }
        }

        while (charStk.empty() == false) {
            output = charStk.top() + output;
            charStk.pop();
        }
        return output;
    }
};

Solution sln;

int main(void)
{
    string s, out;

    s = "3[a]2[bc]";
    out = sln.decodeString(s);
    if (out == "aaabcbc") cout << "1. PASS" << endl;

    s = "3[a2[c]]";
    out = sln.decodeString(s);
    if (out == "accaccacc") cout << "2. PASS" << endl;

    s = "2[abc]3[cd]ef";
    out = sln.decodeString(s);
    if (out == "abcabccdcdcdef") cout << "3. PASS" << endl;

    return 0;
}

#endif // FORREF
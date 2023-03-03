//--------------------------------
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
    int compress(vector<char>& chars) {
        int nc = chars.size();
        // nc = 1
        if (nc == 1) {
            return nc;
        }

        // nc > 1
        char ch = chars[0];
        int ch_cnt = 1;
        int i = 1;

        string out = "";

        for (; i < nc; ++i) {
            if (ch == chars[i]) ch_cnt++;
            else {
                // first thing you should include in output
                if (ch_cnt == 1) {
                    out += ch;
                }
                else if (ch_cnt > 1 && ch_cnt <= 9) {
                    out += ch;
                    out += (ch_cnt + '0');
                }
                else if (ch_cnt > 9) {
                    out += ch;
                    int cnt[4] = { -1, -1, -1, -1 };
                    int i = 4;
                    while (ch_cnt > 0) {
                        cnt[--i] = (ch_cnt % 10);
                        ch_cnt /= 10;
                    }

                    for (int i = 0; i < 4; ++i) {
                        if (cnt[i] != -1) {
                            out += (cnt[i] + '0');
                        }
                    }
                }
                ch = chars[i];
                ch_cnt = 1;
            }

            if (i == nc - 1) {
                if (ch_cnt == 1) {
                    out += ch;
                }
                else if (ch_cnt > 1 && ch_cnt <= 9) {
                    out += ch;
                    out += (ch_cnt + '0');
                }
                else if (ch_cnt > 9) {
                    out += ch;
                    int cnt[4] = { -1, -1, -1, -1 };
                    int i = 4;
                    while (ch_cnt > 0) {
                        cnt[--i] = ch_cnt % 10;
                        ch_cnt /= 10;
                    }

                    for (int i = 0; i < 4; ++i) {
                        if (cnt[i] != -1) {
                            out += (cnt[i] + '0');
                        }
                    }
                }
            }
        }

        for (int i = 0; i < out.size(); ++i) {
            chars[i] = out[i];
        }
        return out.length();
    }
};

Solution sln;

int main(void)
{
    vector<char> chars;
    int len;

    chars = { 'a','a','b','b','c','c','c' };
    len = sln.compress(chars);
    cout << len << endl;
    for (int i = 0; i < chars.size(); ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;
    //----------------------
    chars = { 'a' };
    len = sln.compress(chars);
    cout << len << endl;
    for (int i = 0; i < chars.size(); ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;

    //----------------------
    chars = { 'a','b','b','b','b','b','b','b','b','b','b','b','b' };
    len = sln.compress(chars);
    cout << len << endl;
    for (int i = 0; i < chars.size(); ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;

    //----------------------
    // ["a","a","b","b","c","c","c","a","a","a"]
    chars = { 'a','a','b','b','c','c','c','a','a','a' };
    len = sln.compress(chars);
    cout << len << endl;
    for (int i = 0; i < chars.size(); ++i) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}

#endif // FORREF
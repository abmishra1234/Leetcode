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
    // string object ws not getting updated
    void StringUtil(string& s, int l, int r)
    {
        for (int i = l, j = r; i < j; ++i, --j)
        {
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;
        }
    }

    void StringUtil01(string& s) {
        int len = s.length();
        int ws = 0;
        int we = 0;

        bool nwc_flag = false;

        for (int i = 0; i < len; ++i)
        {
            if (s[i] == ' ')
            {
                if (nwc_flag) {
                    we = i - 1;
                    StringUtil(s, ws, we); // for reversing word
                    ws = 0;
                    we = 0;
                    nwc_flag = false;
                }
            }
            else
            {
                if (nwc_flag == false)
                {
                    we = ws = i;
                }
                else
                    we += 1;
                nwc_flag = true;
            }
        }

        if (ws > 0 || we > 0)
        {
            StringUtil(s, ws, we); // for reversing word
        }

        StringUtil02(s);
    }

    void StringUtil02(string& s) {
        //        cout << s << endl;

        // remove all leading white spaces
        int i = 0;
        while (s[i] == ' ') {
            ++i;
        }
        s = s.substr(i);

        // remove the white spaces betewwn the words
        bool ws_cons = true;
        string tstr = "";
        for (int i = 0, j = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ')
            {
                if (ws_cons)
                {
                    tstr += s[i];
                    ws_cons = false;
                }
            }
            else
            {
                ws_cons = true;
                tstr += s[i];
            }
        }
        s = tstr;

        // remove all trainiling white spaces
        i = s.length() - 1;
        while (s[i] == ' ') {
            --i;
        }
        s = s.substr(0, i + 1);
        //        cout << s << endl;



    }

    string reverseWords(string s) {
        // for verify
        int lind = s.length() - 1;
        StringUtil(s, 0, lind);

        // remove the leading, trailing and in between shite spaces
        StringUtil01(s);
        return s;
    }
};


int main(void)
{

    return 0;
}

#endif // FORREF
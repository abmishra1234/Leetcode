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

    void ReverseString(string& input) {
        int ss = (int) input.length(); // C- typecast 
        int i = 0;
        int j = ss - 1;

        while (i < j) {
            swap(input.at(i), input.at(j));
            ++i, --j;
        }
    }


    string reverseWords(string s) {
        string outStr = "";
        string tempStr = "";

        for (int i = 0; i < s.length(); ++i) {
            if (s.at(i) == ' ') // if space , means word completed
            {
                if (false == tempStr.empty()) {
                    ReverseString(tempStr);
                    outStr += tempStr;
                    outStr += ' ';
                    tempStr = "";
                }
                continue;
            }
            else
                tempStr += s.at(i);

            if (i == s.length() - 1) {
                if (false == tempStr.empty()) {
                    ReverseString(tempStr);
                    outStr += tempStr;
                }
                break;
            }
        }

        return outStr;
    }
};


int main(void)
{
    Solution sln;
    string input = "Abinash";
    sln.ReverseString(input);
    cout << input << endl;

    return 0;
}

#endif // FORREF
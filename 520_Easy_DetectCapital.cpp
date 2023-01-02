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
/*
    Algorithm:
    All the cases are valid and return true if
    1. All the letters are capital
    2. All the letters are small
    3. First Letter is capital and rest all letters are small
    
    let's count the number of capital and small letters
    
    if count of small letters or capital letters are equal to size of string
    than return true

    if only one letter is capital and this is the first letter than valid otherwise not valid

    if more than one letter is capital and it is less than equal to the total length
    than it is invalid

    So, done the analysis now. Let's implement it
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int smallcnt = 0;
        int capitalcnt = 0;

        int wl;

        for (auto& ch : word) {
            if (ch >= 'a' && ch <= 'z') smallcnt++;
            else if (ch >= 'A' && ch <= 'Z') capitalcnt++;
            ++wl;
        }

        if (smallcnt == wl || capitalcnt == wl) return true;
        else if (wl <= 1) return true;
        else if (capitalcnt == 1 && (word[0] >= 'A' && word[0] <= 'Z')) return true;

        return false;
    }
};



int main(void)
{

    return 0;
}

#endif // FORREF
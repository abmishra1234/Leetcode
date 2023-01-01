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
#include<sstream>

#define FORREF
#ifndef FORREF
class Solution {
public:
    /*
        Algorithm:
        you have to make the mapping between char vs word in such a way that
        these mapping should be uniform , if not return false otherwise return true

        Q. How do you make sure the mapping is uniform or not?
        Ans: To validate the mapping is uniform you have to makesure the bidirectional mapping 
        To handle this scenario you should have two mapping 
        a) <char, string>
        b) <string, char>
    */

    bool wordPattern(string pattern, string s) {
        typedef unordered_map<char, string> Char2String;
        typedef unordered_map<string, char> String2Char;
        
        Char2String c2smap;
        String2Char s2cmap;

        istringstream ss(s);
        string word;
        int i = 0;

        while (ss >> word && (i < pattern.size())) {
            char ch = pattern.at(i);
            if (c2smap.find(ch) == c2smap.end() && s2cmap.find(word) == s2cmap.end()) {
                // both are not existing
                c2smap[ch] = word;
                s2cmap[word] = ch;
                ++i;
                continue;
            }
            else if (c2smap.find(ch) == c2smap.end() && s2cmap.find(word) != s2cmap.end()) {
                // it is refering in logic that, the character is not the part of map but the corresponding word is
                // the part of map
                return s2cmap[word] == ch;
            }
            else if (c2smap.find(ch) != c2smap.end() && s2cmap.find(word) == s2cmap.end()) {
                // it is refering in logic that, the character is not the part of map but the corresponding word is
                // the part of map
                return c2smap[ch] == word;
            }
            else if (false == (s2cmap[word] == ch && (c2smap[ch] == word))) return false;
            ++i;
        }

        if ((word.empty() && i < pattern.size()) || (!word.empty() && i == pattern.size())) return false;

        return true;
    }
};

Solution sln;

int main(void)
{
    string pattern = "abba";
    string s = "dog cat cat dog";

    bool ans = sln.wordPattern(pattern, s);
    cout << ans << endl;

    return 0;
}

#endif // FORREF
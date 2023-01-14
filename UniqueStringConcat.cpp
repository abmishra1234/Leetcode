// Maximum Length of a Concatenated String with Unique Characters
// Problem link https : https://bit.ly/3x6cnBt

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

    bool check(vector<int> freq, string s) {
        for (auto c : s) {
            if (freq[c - 'a'] > 0) return false;
            else freq[c - 'a'] += 1;
        }
        return true;
    }

    int solve(int strind, vector<int>& freq, vector<string>& arr)
    {
        if (strind >= arr.size()) return 0;
        
        // Either you pick this string or you don't pick the string
        int wlen = 0, wilen = 0;
        
        if (check(freq, arr[strind])) {
            // add this string
            for (auto ch : arr[strind]) freq[ch - 'a'] += 1;
            wlen = arr[strind].length() + solve(strind + 1, freq, arr);
            for (auto ch : arr[strind]) freq[ch - 'a'] -= 1;
        }
        
        wilen = solve(strind + 1, freq, arr);
        return max(wlen, wilen);
    }

    int stringConcatenation(vector<string>& arr)
    {
        vector<int> freq(26, 0);
        return solve(0, freq, arr);
    }
};

Solution sln;

/*
    2
    cha r act ers
    abcdefghijklmnopqrstuvwxyz
*/

int main(void)
{
    vector<string> arr;
    int maxlen = 0;

    // #TC 1
    arr = {"cha", "r", "act", "ers"};
    maxlen = sln.stringConcatenation(arr);
    if (maxlen == 6) cout << "1. PASS" << endl;

    // #TC 2
    arr = { "abcdefghijklmnopqrstuvwxyz" };
    maxlen = sln.stringConcatenation(arr);
    if (maxlen == 26) cout << "2. PASS" << endl;

    return 0;
}

#endif // FORREF
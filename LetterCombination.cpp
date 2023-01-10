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
    typedef unordered_map<int, string> DigitVsCharsMap;
    DigitVsCharsMap map;
    vector<string> results;

    // prepare map for digits vs alphabets
    void PrepareData()
    {
        // Kind of pre setup method for your solution

        map.insert(make_pair(2, "abc"));
        map.insert(make_pair(3, "def"));
        map.insert(make_pair(4, "ghi"));
        map.insert(make_pair(5, "jkl"));
        map.insert(make_pair(6, "mno"));
        map.insert(make_pair(7, "pqrs"));
        map.insert(make_pair(8, "tuv"));
        map.insert(make_pair(9, "wxyz"));

        // This is for 
        results.clear(); // clear the old data
    }

    // write utility method recursive for finding all possible strings
    void dfs(string digits, int ind, string output)
    {
        // base case
        if (ind == digits.length())
        {
            if (output.length() > 0)
            {
                // this is the case where you found the final combinations
                // push the output string into the 
                results.push_back(output);
            }
            return;
        }

        // find the digit at the index
        int dig = (digits[ind] - '0');
        string str = map[dig]; // fetched the corresponding string

        for (int i = 0; i < str.length(); ++i)
        {
            // add the character into output
            dfs(digits, ind + 1, output + str[i]);
        }
    }

    vector<string> combinations(string s) {
        // Write your code here
        PrepareData();
        dfs(s, 0, "");
        return results;
    }
};

Solution sln;

int main(void)
{

    return 0;
}

#endif // FORREF

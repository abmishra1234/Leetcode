/*
    https://leetcode.com/problems/permutation-in-string/
*/
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

/*
    How to proceed?
    Multiple level of intution is needed, and the first level of intution
    is to start with Brute Force Approach, discuss this approach with your
    interviewer first with time & space complexity. 
    
    Hopefully your interviewer is not satisfied with this approach, ans so he 
    will ask you to share the optimised approach.

    But you chocked over their and you couldn't find anyway to proceed?
    what should you do over their?

    until now we have not explored the constraint, and so we should go to the 
    constraint validation to check the appropriate approach

    Constraints:
    1 <= s1.length, s2.length <= 10^4
    s1 and s2 consist of lowercase English letters.
*/

#define FORREF
#ifndef FORREF

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1freq(26, 0);
        vector<int> s2freq(26, 0);

        for (auto ch : s1) {
            s1freq[ch - 'a'] += 1;
        }

        // you should write the sliding window logic next and verify that
        // any freq matching happening?
        // If so than that would be the end of your logic and return true
        // else if you haven't found any such frequency, meaning your
        // match is not successful and so you should return false
        // While matching of frequency also , comparing the by using 26 iteration
        // will fail the timeline in porblem so you need some better approach
        // and that will come by using the concept of bitset

        int s1_len = s1.length();
        int s2_len = s2.length();

        if (s2_len < s1_len) return false;

        // so from now onward , it is obvious that 





        return false;
    }
};


int main(void)
{



    return 0;
}

#endif // FORREF
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
/*
    So, on seeing this problem, it is very difficult to think the right 
    approach. With intuition, it is very much sure that any solution
    of O(N^2) is not going to work here, since N = 10^5 range

    So brute force is completely out of question.
    
    So, than think about the other approach??

    Another approach after little exploring the internet found using trie and
    bit manipulation concept might be helpful in reching the required solution.


*/

struct TrieNode {

};



class Solution {
    vector<string> bset;

public:

    /*
        Approach or Algorithm Steps
        1. convert each decimal number as binary number string
        2. push this string into Trie DS
        3. (i) let's iterate the number array one's again
        3. (ii) convert decimal into the binary number string
        3. (iii) also prepare the number with opposit bit's string for getting maximized value possible
        3. (iv) start searching the string in step (iii) into trie DS
        3. (v) start searching the string in step (iii) into trie DS, if match than copy the character into 
               the final maximized output string
        3. (vi) incase it is not matching than copy the rest of the character into the output string
        4. Convert this output string into the decimal
        5. Update the maximum value found until now
        6. One's the iteration for all the numbers of an array complete, your final max value would be the ans here.
    */
    int findMaximumXOR(vector<int>& nums) {
        // clean the slate
        bset.clear();

        int maxval = INT_MIN;
        for (auto n : nums) {
            string temp = ""; // converted into binary from decimal
            string temp1 = ""; // negative of binary number as a string
            d2bstring(n, temp, temp1);
            bset.push_back(temp);
        }

        // push the all these string into the trie





        return maxval;
    }

    // Let's create some utility method
    void d2bstring(int dec, string &converted, string &nconverted) {
        vector<char> bins(32, '0');
        vector<char> nbins(32, '1');

        if (dec == 0) {
            converted += '0';
            nconverted += '1';
            return;
        }
        
        int rem, fact;
        stack<int> s;
        int i = 31;
        while (dec > 0) {
            rem = dec % 2;
            fact = dec / 2;
            
            // set the right char below
            bins[i] = (rem + '0');
            if (bins[i] == '0') nbins[i] = '1';
            else nbins[i] = '0';
            --i;
            dec = fact;
        }

        for (int i = 0; i < 32; ++i) {
            converted += bins[i];
            nconverted += nbins[i];
        }
    }
};

Solution sln;

int main(void)
{
    // let's take some example here
    string orgconverted = "", negconverted = "";
    sln.d2bstring(5, orgconverted, negconverted);
    cout << orgconverted << " | " << negconverted << endl;

    sln.d2bstring(28, orgconverted, negconverted);
    cout << orgconverted << " | " << negconverted << endl;




    return 0;
}

#endif // FORREF
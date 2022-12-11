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

#define _CRT_SECURE_NO_WARNINGS
/*
    This is not completed yet, Please complete this in sometime...
*/
// Approach 01
#define FORREF
#ifndef FORREF

class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {

    }

    vector<string> input(char c) {
        return {};
    }
};

/*
    Your TC are not strong enough, please build some of your own TC
    to verify your logic and complete it.
    This is your learning, to get the right motivation over the quick coding 
*/
int main(void)
{
    // write some verification code first
    vector<string> sentence;
    vector<int> times;
    char ch;
    vector<string> output;

    sentence = { "i love you", "island", "ironman", "i love leetcode" };
    times = { 5, 3, 2, 2 };

    AutocompleteSystem sln(sentence, times);
    // #tc 1
    ch = 'i';

    output = sln.input(ch);
    if (output.size() == 3) {
        if (output[0] == "i love you"
            && output[1] == "island" && output[2] == "i love leetcode") 
            cout << "1. PASS" << endl;
    }

    // #tc 2
    ch = ' ';

    output = sln.input(ch);
    if (output.size() == 2) {
        if (output[0] == "i love you"
            && output[1] == "i love leetcode")
            cout << "2. PASS" << endl;
    }

    // #tc 3
    ch = 'a';

    output = sln.input(ch);
    if (output.size() == 0) {
       cout << "3. PASS" << endl;
    }

    ch = '#';
    output = sln.input(ch);
    // Exit with empty recommendation

    return 0;
}

#endif // FORREF
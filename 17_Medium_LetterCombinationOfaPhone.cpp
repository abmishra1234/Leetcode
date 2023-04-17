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
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        vector<string> mappings = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        string combination(digits.size(), ' ');
        letterCombinationsHelper(digits, 0, mappings, combination, result);
        return result;
    }

private:
    void letterCombinationsHelper(string digits, int index, vector<string>& mappings, string& combination, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(combination);
            return;
        }
        string letters = mappings[digits[index] - '0'];
        for (char c : letters) {
            combination[index] = c;
            letterCombinationsHelper(digits, index + 1, mappings, combination, result);
        }
    }
};

/*
    In this implementation, we define the letterCombinations function as a public 
    member function of the Solution class, which takes a string digits containing digits 
    from 2-9 inclusive and returns a vector of strings containing all possible letter combinations 
    that the number could represent.

    To implement the letter combination algorithm, we use a helper function letter
    CombinationsHelper that takes a string digits, an index index, a vector of strings mappings 
    containing the mappings of digits to letters, a string combination to store the current 
    combination of letters, and a vector of strings result to store all the combinations.
    The index parameter indicates the current position in the digits string where we are adding
    letters to generate combinations.

    If the index parameter is equal to the length of the digits string, we have generated a 
    complete combination and add it to the result vector. Otherwise, we get the letters 
    corresponding to the current digit from the mappings vector and loop through each
    letter to generate all possible combinations. We add each letter to the current position in 
    the combination string and recursively call letterCombinationsHelper with the index + 1 as 
    the new index. After the recursive call, we remove the added letter from the combination 
    string to backtrack and generate the next combination.

    Finally, we call the letterCombinationsHelper function with the initial index parameter of 0, 
    a mappings vector containing the mappings of digits to letters, an empty string combination, 
    and an empty result vector to generate all possible letter combinations of the digits string. 
    We then return the result vector containing all the combinations.

*/

int main() {
    Solution s;
    string digits = "23";
    vector<string> combinations = s.letterCombinations(digits);
    for (auto c : combinations) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}


#endif // FORREF
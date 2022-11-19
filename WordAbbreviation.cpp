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

//#define FORREF
#ifndef FORREF

class ValidWordAbbr {


protected:
    /*
        The abbreviation of a word is a concatenation of its first letter, 
        the number of characters between the first and last letter, and its last letter. 
        If a word has only two characters, then it is an abbreviation of itself.

        Let's Concentrate on, how to do the things in the best way
        - I can realised that sometime your current situation is little dicey and you might be 
          going through the phase which is problematic for you and yoor growth, 

        - 



    */
    string Abbreviation(string& word)
    {
        int wl = word.length();

        if (wl == 1 || wl == 2) {
            return word;
        }

        string out = "";

        if (wl > 2) {
            out += word.at(0);
            out += to_string(wl - 2);
            out += word.at(wl - 1);
        }
        
        if (out.empty()) {
            // To make sure the Error message will help you while debugging
            cout << "Something Wrong happened while creating Abbreviation!!!" << endl;
        }

        return out;
    }


public:
    ValidWordAbbr(vector<string>& dictionary) {

    }

    bool isUnique(string word) {

    }
};






int main()
{
	cout << "Hello !!" << endl;

	return 0;
}


#endif // FORREF




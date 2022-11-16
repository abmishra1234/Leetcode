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
    */
    string Abbreviation(string& word)
    {
        int wl = word.length();
        if (wl == 1 || wl == 2) {
            return word;
        }

        string out = "";
        out += word.at(0);
        out += to_string(wl - 2);
        out += word.at(wl - 1);

        // 


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




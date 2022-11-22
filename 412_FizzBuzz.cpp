/*
	Solve the below problem.
*/

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

class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> output;

        for (int i = 1; i <= n; ++i) {
            bool div_by3 = (i % 3 == 0);
            bool div_by5 = (i % 5 == 0);

            if (div_by3 && div_by5) {
                output.push_back("FizzBuzz");
            }
            else if (div_by3) {
                output.push_back("Fizz");

            }
            else if (div_by5) {
                output.push_back("Buzz");

            }
            else
                output.push_back(to_string(i));
        }
        return output;
     }
};






int main() {


	return 0;
}


#endif // End of File
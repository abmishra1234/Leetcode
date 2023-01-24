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

// Revise this problem again for undertsanding this...

#define FORREF
#ifndef FORREF
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int k = 0; k < input.length(); k++) {
            if (input[k] == '*' || input[k] == '-' || input[k] == '+') {
                vector<int> a = diffWaysToCompute(input.substr(0, k));
                vector<int> b = diffWaysToCompute(input.substr(k + 1));
                for (int i = 0; i < a.size(); i++) {
                    for (int j = 0; j < b.size(); j++) {
                        if (input[k] == '+') {
                            result.push_back(a[i] + b[j]);
                        }
                        else if (input[k] == '-') {
                            result.push_back(a[i] - b[j]);
                        }
                        else {
                            result.push_back(a[i] * b[j]);
                        }
                    }
                }

            }
        }
        if (result.size() == 0) {
            result.push_back(stoi(input));
        }
        return result;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
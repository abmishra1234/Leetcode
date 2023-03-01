//--------------------------------
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
    const int SIZE = 100005;
    const int OFF = 50000;
    vector<int> sortArray(vector<int>& nums) {
        vector<int> present(SIZE, 0);

        /*
            you algorithm should be here like,
            Implement the count sorting here to get the time complexity of O(n)

            one thing to be noted here that you have negative number also in this series

            So, what I am suggesting here that, since even after considering all
            the negative and positive number, I am still position hold all number in positive range

            by adding some positive offset to each number

            let me go through the example

            suppose you want to store
            -20 <= num <= 20

            the above can be transformed to
            0 <= num <= 40

            by just adding 20 on each number
        */

        for (auto n : nums) {
            present[n + OFF] += 1;
        }

        vector<int> result;

        for (int i = 0; i < SIZE; ++i) {
            while (present[i] > 0) {
                result.push_back(i - OFF);
                present[i]--;
            }
        }
        return result;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
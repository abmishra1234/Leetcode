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
class Solution{
public:

    bool check(vector<int>&piles, int h, int cand) {
        int hr = 0;
        for (auto i : piles) {
            hr += (i % cand == 0) ? i / cand : (1 + i / cand);
        }
        return (hr <= h);
    }

    int minEatingSpeed(vector<int>&piles, int h) {
        long long int sum = 0;
        int maxi = 0;
        for (auto i : piles) {
            if (maxi < i) maxi = i;
            sum += i;
        }

        int min = (sum % h == 0) ? sum / h : (1 + sum / h);

        int ans = maxi;

        while (min <= maxi) {
            if (min == maxi) {
                if (check(piles, h, min)) return min;
                return ans;
            }
            int mid = min + (maxi - min) / 2;
            if (check(piles, h, mid)) {
                ans = mid;
                maxi = mid - 1;
            }
            else
            {
                min = mid + 1;
            }
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
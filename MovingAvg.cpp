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

class MovingAverage {
    const static int maxsize = 10000;
    int arr[maxsize + 5];
    int h, t;
    int s;
    double sum;
    int window;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        h = t = 0;
        sum = 0.0;
        window = size;
    }

    double next(int val) {
        arr[t++] = val;
        int s = (t - h);
        if (s > window)
        {
            sum -= arr[h++];
        }
        sum += val;
        int nelem = (s > window) ? window : s;
        return (sum / nelem);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

int main(void)
{


    return 0;
}

#endif // FORREF
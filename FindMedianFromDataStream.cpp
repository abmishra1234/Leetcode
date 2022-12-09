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
    In this problem, we have to build the elements in order using the DS
    such that you will able to access the middle element/s ( one or two) depends 
    on the number of element either odd or even
    So, how you will do the same?
*/
class Solution {
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    int max_size, min_size;

public:
    Solution() {
        max_size = min_size = 0;
    }

    void addNum(int num) {
        if (max_size == 0) {
            maxheap.push(num);
            ++max_size;
        }
        else if (max_size == 1 + min_size) {
            if (num <= maxheap.top()) {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
                min_size++;
            }
            else {
                minheap.push(num);
                min_size++;
            }
        }
        else if (max_size == min_size)
        {
            if (num >= minheap.top()) {
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
                max_size++;
            }
            else {
                maxheap.push(num);
                max_size++;
            }
        }
    }

    double findMedian() {
        if ((min_size + max_size) % 2 == 0) 
            return (maxheap.top() + minheap.top()) / 2.0;
        return maxheap.top();
    }
};
Solution sln;
int main(void)
{
    int num;
    double ans;

    num = 1;
    sln.addNum(num);
    ans = sln.findMedian(); // 1.0
    if (ans == 1.0) cout << "1. PASS" << endl;

    num = 2;
    sln.addNum(num);
    ans = sln.findMedian(); // 1.5
    if (ans == 1.5) cout << "2. PASS" << endl;

    num = 3;
    sln.addNum(num);
    ans = sln.findMedian(); // 2.0
    if (ans == 2.0) cout << "3. PASS" << endl;

    return 0;
}
#endif // FORREF
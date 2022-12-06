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
class Solution {
    priority_queue<int, vector<int>, less<int>> *pMaxHeap;
    priority_queue<int, vector<int>, greater<int>> *pMinHeap;
public:
    Solution() {
        pMaxHeap = new priority_queue<int, vector<int>, less<int>>();
        pMinHeap = new priority_queue<int, vector<int>, greater<int>>();
    
    }
    
    // Let's write one Add method for your max nad min heap
    void Add(int elem) {
        pMaxHeap->push(elem);
        pMinHeap->push(elem);
    }

    void Top(int &maxval, int &minval) {
        maxval = pMaxHeap->top();
        minval = pMinHeap->top();

    }

    // Delete
    void Delete() {
        pMaxHeap->pop();
        pMinHeap->pop();
    }

    

};

Solution sln;

int main(void)
{
    sln.Add(5);
    sln.Add(2);
    sln.Add(8);
    sln.Add(7);
    sln.Add(6);
    sln.Add(15);
    sln.Add(12);

    int max = 0;
    int min = 0; 

    sln.Top(max, min);
    cout << "max = " << max << ", min = " << min << endl;

    sln.Delete();
    sln.Top(max, min);
    cout << "max = " << max << ", min = " << min << endl;


    return 0;
}

#endif // FORREF
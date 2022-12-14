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

/*
    In this coding exercise, we have to implement the 
    merge sort using top down approach

    meaning, implement using recursion.
*/

#define FORREF
#ifndef FORREF
#define MAXN 100000

// These are global scope, so we should take care of global scope
typedef vector<int> MyVect;
MyVect v;
int vs; // This is the actual vector size

// For merging step, you might need temp array to hold 
// intermediate steps in merging process
MyVect tvec;

/* 
    This class is designed for the handling of
    merge sort 
*/
class Solution {
public:
    void merge(MyVect& v, int l, int mid, int r) {
        tvec.clear();
        
        int i = l, j = mid + 1;

        while (i <= mid && j <= r) {
            if (v[i] <= v[j]) tvec.push_back(v[i++]);
            else tvec.push_back(v[j++]);
        }

        while (i <= mid) {
            tvec.push_back(v[i++]);
        }

        while (j <= r) {
            tvec.push_back(v[j++]);
        }

        int k = 0;
        i = l;
        while (k < tvec.size()) {
            v[i] = tvec[k];
            ++i, ++k;
        }
    }

    void solve(MyVect& v, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            solve(v, l, mid);
            solve(v, mid + 1, r);
            merge(v, l, mid, r);
        }
    }

    void mysort(MyVect& v, const int &vs) {
        solve(v, 0, vs - 1);
    }
};


Solution sln;

int main(void)
{
    FILE* fp = nullptr;
    freopen_s(&fp, "merge.txt", "r", stdin);
    freopen_s(&fp, "output.txt", "a+", stdout);

    int T, N;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> N;
        v.resize(MAXN);
        vs = 0; // reset the vector size to 0
        for (int n = 0; n < N; ++n) {
            cin >> v[vs++];
        }
        /*
            post returning from this method your vector should be
            sorted one
        */
        cout << "Element before sorting -->" << endl;
        for (int i = 0; i < vs; ++i) cout << v[i] << " ";
        cout << endl;
        
        sln.mysort(v, vs);

        cout << "Element after sorting -->" << endl;
        for (int i = 0; i < vs; ++i) cout << v[i] << " ";
        cout << endl;

    }

    return 0;
}

#endif
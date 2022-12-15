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
    merge sort using Bottom up approach
    meaning, implement using iterative approach.
*/

//#define FORREF
#ifndef FORREF
#define MAXN 100000

// These are global scope, so we should take care of global scope
typedef vector<int> MyVect;
MyVect input;
int vs; // This is the actual vector size

// For merging step, you might need temp array to hold 
// intermediate steps in merging process
MyVect tvec;
typedef pair<int, int> pii;
typedef stack<pii> MyStack;
MyStack s;

/*
    This class is designed for the handling of
    merge sort
*/
class Solution {
public:
    void merge(MyVect& v, int l, int mid, int r) {
        int i = l, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= r) {
            if (v[i] <= v[j]) tvec[k++] = v[i++];
            else tvec[k++] = v[j++];
        }

        while (i <= mid) {
            tvec[k++] = v[i++];
        }

        while (j <= r) {
            tvec[k++] = v[j++];
        }

        int ki = 0;
        i = l;
        while (ki < k) {
            v[i++] = tvec[ki++];
        }
    }
    /*
        This method to be implement for mergesort  
        using bottom up approach.
        So the next question is, what is this bottom-up approach?

        Let's take one example here, 
        8
        v : 1,5,3,2,8,7,6,4

        Intuition :
        - Every array of size one is already sorted
        - Incase you have two seperate array which is sorted than the next step is 
          to merge them together to produce the bigger size sorted array and so on...
        - How to decide when to stop?
          a. Theoritically the stopping point is when you have no pair of same size array
             to be merged left out
          b. call for final merge with different size of two part and exit from the loop

          Let's check the cases?
          Case 01: Perfact ideal world with pair of 
          same size until you merged everything into one array

          case 02: This is not perfact world but the carryover can be merged together in one
          additional step
    */
    void mysort(MyVect& v, const int& vs) {
        int w = 1, i=0;
        if (vs % 2 != 0) i = 1;

        bool breakflag = false;
        while (true) {
            i = (vs % 2 != 0) ? 1 : 0;
            for (; i < vs;/* TBD - what is your incremental factor? */) {
                if (i + (2 * w) <= vs) {
                    merge(v, i, i + w - 1, i + 2 * w - 1);
                    i += (2 * w);
                }
                else // This is finally the case 02
                {
                    // you just merge the all left out element and return from this method
                    int bkp = i;
                    i = (vs % 2 != 0) ? 1 : 0;
                    merge(v, i, bkp-1, vs - 1);
                    breakflag = true;
                    i = vs;
                }
            }
            w *= 2;
            if (w >= vs || breakflag) break;
        }
        /*
            @Note - If the below was the case , it means that you have to 
            do one extra call to solve completely...
            l = 0, m = 0, r = vs-1 
        */
        if (vs%2 != 0) {
            merge(v, 0, 0, vs - 1);
        }
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
        input.resize(N);
        tvec.resize(N);
        vs = 0; // reset the vector size to 0
        for (int n = 0; n < N; ++n) {
            cin >> input[vs++];
        }
        /*
            post returning from this method your vector should be
            sorted one
        */
        cout << "Element before sorting -->" << endl;
        for (int i = 0; i < vs; ++i) cout << input[i] << " ";
        cout << endl;

        sln.mysort(input, vs);

        cout << "Element after sorting -->" << endl;
        for (int i = 0; i < vs; ++i) cout << input[i] << " ";
        cout << endl;

    }

    return 0;
}

#endif
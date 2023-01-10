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

#define FORREF
#ifndef FORREF

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // default -1 value is handles by giving the initial value to -1
        vector<vector<int>> result(m, vector<int>(n, -1));
        /*
            How you will able to handle the spiral kind of update in matrix
            TODO??
            Q. How do you manage the movement in the form of spiral?
            Analysis:
            dir [0, 1, 2, 3]
            dir [R, D, L, U]

            if(dir == 1) {
                minR++;
            }
            else if(dir == 2){
                maxC--;
            }
            else if(dir == 3){
                maxR--;
            }
            else if(dir == 0) {
                minC++;
            }
        */
        int minR = 0, maxR = m-1;
        int minC = 0, maxC = n-1;
        int dir = 0;

        while (head) {
            if (dir == 0) {
                int c = minC;
                while (c <= maxC && head) {
                    result[minR][c] = head->val;
                    head = head->next;
                    ++c;
                }
                if (!head) return result;
                ++dir;
            }
            if (dir == 1) {
                minR++;
                int r = minR;
                while (r <= maxR && head) {
                    result[r][maxC] = head->val;
                    head = head->next;
                    ++r;
                }
                if (!head) return result;
                ++dir;
            }
            if (dir == 2) {
                maxC--;
                int c = maxC;
                while (c >= minC && head) {
                    result[maxR][c] = head->val;
                    head = head->next;
                    --c;
                }
                if (!head) return result;
                ++dir;
            }

            if (dir == 3) {
                maxR--;
                int r = maxR;
                while (r >= minR && head) {
                    result[r][minC] = head->val;
                    head = head->next;
                    --r;
                }
                if (!head) return result;
                ++dir;
            }
            dir %= 4;
            ++minC;
        }

        return result;
    }
};

Solution sln;

int main(void)
{
    // head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
    int m = 3, n=5;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(0);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(8);
    head->next->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(0);
    head->next->next->next->next->next->next->next->next->next->next->next->next->next = nullptr;
    auto res = sln.spiralMatrix(m, n, head);
    for (auto v : res) {
        for (auto elem : v) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;


    return 0;
}

#endif // FORREF
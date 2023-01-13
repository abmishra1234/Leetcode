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
/*
    There are two possible approaches here
    1. Recursion 
    2. Iterative

    - Let's move first with iterative this time??

*/

class PolyNode {
public:
    int coefficient, power;
    PolyNode* next;
    PolyNode() : coefficient(0), power(0), next(nullptr) {}
    PolyNode(int x, int y) : coefficient(x), power(y), next(nullptr) {}
    PolyNode(int x, int y, PolyNode* n) : coefficient(x), power(y), next(n) {}
};

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* newhead = nullptr, *tail = nullptr;

        while (poly1 || poly2) {
            int p1 = -1,p2 = -1,c1 = 0 ,c2 = 0;
            if (poly1 && !poly2) {
                PolyNode* next = poly1->next;
                poly1->next = nullptr;

                if (!newhead) {
                    tail = newhead = poly1;
                }
                else
                {
                    tail->next = poly1;
                    tail = poly1;
                }
                poly1 = next;
            }
            else if (poly2 && !poly1) {
                PolyNode* next = poly2->next;
                poly2->next = nullptr;

                if (!newhead) {
                    tail = newhead = poly2;
                }
                else
                {
                    tail->next = poly2;
                    tail = poly2;
                }
                poly2 = next;
            }
            else
            {
                p1 = poly1->power;
                c1 = poly1->coefficient;
                p2 = poly2->power;
                c2 = poly2->coefficient;

                if (p1 == p2) {
                    PolyNode* n1 = poly1->next, * n2 = poly2->next;
                    poly1->next = poly2->next = nullptr;

                    int coeff = c1 + c2;
                    if (coeff != 0) {
                        poly1->coefficient = coeff;
                        if (!newhead) {
                            tail = newhead = poly1;
                        }
                        else
                        {
                            tail->next = poly1;
                            tail = poly1;
                        }
                    }
                    poly1 = n1;
                    poly2 = n2;
                }
                else
                {
                    if (p1 > p2) {
                        PolyNode* n1 = poly1->next;
                        poly1->next = nullptr;
                        if (!newhead) {
                            tail = newhead = poly1;
                        }
                        else
                        {
                            tail->next = poly1;
                            tail = poly1;
                        }
                        poly1 = n1;
                    }
                    else
                    {
                        PolyNode* n2 = poly2->next;
                        poly2->next = nullptr;
                        if (!newhead) {
                            tail = newhead = poly2;
                        }
                        else
                        {
                            tail->next = poly2;
                            tail = poly2;
                        }
                        poly2 = n2;
                    }
                }
            }
        }
        return newhead;
    }
};

int main(void)
{

    return 0;
}

#endif // FORREF
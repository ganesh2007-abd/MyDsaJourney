/*

Approach

1)Take 2 pointers p and q and traverse along the linked list
2)if there values are equal ,traverse untill what node that value is repeating because it is sorted (using q)
3)Always keepa trace of node 'prev' refering to node before p
4)connect p->next to q->next and maek q->next as NULL
5)Handle edge cases like head or head->next is NULL,the repetition starting from head itself requires to modify the head



*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        cout << "0";
        if (head == NULL || head->next == NULL)
            return head;
        bool starting = true;
        ListNode *p = head;
        ListNode *q = p->next;
        ListNode *prev;
        while (q != NULL)
        {
            cout << "Starting outer while looop" << endl;
            if (p->val == q->val)
            {
                while (q->next != NULL && q->next->val == p->val)
                {
                    q = q->next;
                }
                cout << "entered inside while" << endl;
                if (starting)
                {
                    cout << "1";
                    if (q->next == NULL)
                        return NULL;
                    head = q->next;
                    p = head;
                    q = p->next;
                }
                else
                {
                    cout << "enetred else" << endl;
                    if (q->next == NULL)
                    {
                        cout << "enetered here" << endl;
                        prev->next = NULL;
                        return head;
                    }
                    else
                    {
                        cout << "3" << endl;
                        ;
                        prev->next = q->next;
                        q->next = NULL;
                        p = prev->next;

                        q = p->next;
                    }
                }
                continue;
            }
            p = p->next;
            q = q->next;
            if (!starting)
            {
                prev = prev->next;
            }
            else
            {
                prev = head;
                starting = false;
            }
            cout << "completed 1 loop" << endl;
        }
        return head;
    }
};
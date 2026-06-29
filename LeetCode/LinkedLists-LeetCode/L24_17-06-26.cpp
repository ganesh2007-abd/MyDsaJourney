
/*

Approach

All you have to do is swap a pair of nodes
(reversing) and connect this new swapped node from prev pair of nodes


The problem is to swap nodes in pairs-->
1)So for swapping a pair of node 1,2 we should have a pointer on 2 and 1.I marked them as p and q
2)After swapping the nodes we have to connect the before pair and present pair of nodes.So always maintain a prev node to connect
3)There are some things to be initialised before the 1st run of loop.So use a bool and dowhile loop to execute it correctly


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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *p;
        ListNode *q;
        ListNode *prev;
        bool starting = true;
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return head;
        }
        do
        {
            if (starting)
            {
                p = head->next;
                q = head;
            }
            else
            {
                prev = q;
                p = p->next->next->next;
                q = q->next;
            }
            q->next = p->next;
            p->next = q;
            if (starting)
            {
                head = p;
            }
            if (!starting)
            {
                prev->next = p;
            }
            starting = false;
        } while (p->next != NULL && p->next->next != NULL && p->next->next->next != NULL);

        return head;
    }
};
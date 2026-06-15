/*


Approach

1)use slow and fast pointer
2)whenyou are traversing always keep first keep track of p and then step up p(p=p->next)
3)Because you will be requiring the before node of middle node while deleting middle node




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
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *t;
        // ListNode *p = (ListNode*)malloc(sizeof(ListNode));
        // p = head;
        // ListNode *q = (ListNode*)malloc(sizeof(ListNode));
        // q = head;
        // ListNode *t = (ListNode*)malloc(sizeof(ListNode));
        if (head == NULL)
            return NULL;
        else if (head->next == NULL)
            return NULL;
        else if (head->next->next == NULL)
        {
            head->next = NULL;
            return head;
        }
        else
        {
            while (q != NULL && q->next != NULL)
            {
                t = p;
                p = p->next;
                q = q->next->next;
            }
            t->next = p->next;
            p->next = NULL;
            // free(p);
            // free(q);
            // free(t);
            return head;
        }
    }
};
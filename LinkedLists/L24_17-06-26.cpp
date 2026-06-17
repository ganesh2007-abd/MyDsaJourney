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
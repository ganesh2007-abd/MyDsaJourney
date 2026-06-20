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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *lastnode = head;
        ListNode *q = head;
        ListNode *p;
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
            return head;
        int n = 1;
        while (lastnode->next != NULL)
        {
            lastnode = lastnode->next;
            n++;
        }
        // cout<<count;
        // return lastnode;
        k = k % n;
        if (k == 0)
            return head;
        int count = 0;
        while (count < n - k)
        {
            p = q;
            q = q->next;
            count++;
        }
        ListNode *newhead = q;
        while (q->next != NULL)
        {
            q = q->next;
        }
        p->next = NULL;
        q->next = head;
        head = newhead;
        return head;
    }
};
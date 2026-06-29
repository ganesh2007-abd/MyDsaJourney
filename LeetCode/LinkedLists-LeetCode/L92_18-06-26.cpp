
/*

Approach

1)Given the left and right position
2)traverse the linked list and make the nodes p and q stand on left and right positions resply
3)here also keep track of prev node(left node of leftpositioned node i.e p)
4)make a newnode called lastnode and initialise as q->next
4)untill p becomes q -- store p->next and connect p->next to lastnode and make new last as p and make new p as its befroe p->next
5)the do prev->next = p and return head
6)handle edge cases like if left or rigth positions are extrem left or right



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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == NULL || head->next == NULL)
            return head;
        bool modifyhead = false;
        ListNode *prev = head;
        ListNode *p = head;
        int count1 = 1;
        while (count1 != left)
        {
            prev = p;
            p = p->next;
            count1++;
        }
        int count2 = left;
        ListNode *q = p;
        while (count2 != right)
        {
            q = q->next;
            count2++;
        }
        if (prev == p)
            modifyhead = true;
        ListNode *r;
        ListNode *last = q->next;
        while (p != q)
        {
            r = p->next;
            p->next = last;
            last = p;
            p = r;
        }
        p->next = last;
        if (modifyhead)
        {
            head = q;
            return head;
        }
        prev->next = p;

        return head;
    }
};
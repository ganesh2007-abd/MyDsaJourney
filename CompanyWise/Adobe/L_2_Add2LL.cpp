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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *a = l1;
        ListNode *b = l2;
        int carry = 0;
        ListNode *ans = new ListNode();
        ListNode *curr = ans;
        while (a != NULL && b != NULL)
        {
            ListNode *newnode = new ListNode();
            newnode->val = (a->val + b->val + carry) % 10;
            curr->next = newnode;
            carry = (a->val + b->val + carry) / 10;
            a = a->next;
            b = b->next;
            curr = curr->next;
        }
        while (a != NULL)
        {
            ListNode *newnode = new ListNode();
            newnode->val = (a->val + carry) % 10;
            curr->next = newnode;
            carry = (a->val + carry) / 10;
            a = a->next;
            curr = curr->next;
        }
        while (b != NULL)
        {
            ListNode *newnode = new ListNode();
            newnode->val = (b->val + carry) % 10;
            curr->next = newnode;
            carry = (b->val + carry) / 10;
            b = b->next;
            curr = curr->next;
        }
        if (carry)
        {
            ListNode *newnode = new ListNode();
            newnode->val = carry;
            curr->next = newnode;
        }
        return ans->next;
    }
};
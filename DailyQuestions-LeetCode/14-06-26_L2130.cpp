/*

Approach

1)first travserse to middle of the linked list using slow,fast pointers
2)then reverse the second half of the linked list
3)start from head with new var ,traverse through it and update max along


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
    int pairSum(ListNode *head)
    {

        ListNode *q = head;
        int len = 1;
        // while(q -> next != NULL){
        //     len++;
        //     q = q->next;
        // }
        // vector<int> v;
        ListNode *p = head;
        // for(int i=0;i<len/2;i++){
        //     v.push_back(p->val);
        //     p = p->next;
        // }
        // int i=0;
        // while( p != NULL){
        //     v[len/2 - 1 - i] += p->val;
        //     i++;
        //     p=p->next;
        // }
        // int Max = INT_MIN;
        // for(int i=0;i<len/2;i++){
        //     Max = max(Max,v[i]);
        // }
        // return Max;

        if (head == NULL)
            return 0;
        while (q != NULL && q->next != NULL)
        {
            p = p->next;
            q = q->next->next;
            len++;
        }

        len *= 2;
        ListNode *prev = NULL;
        ListNode *Next;
        while (p != NULL)
        {
            Next = p->next;
            p->next = prev;
            prev = p;
            p = Next;
        }
        ListNode *t = head;
        int sum;
        int Max = INT_MIN;

        while (prev != NULL)
        {
            sum = prev->val + t->val;
            if (sum >= Max)
            {
                Max = sum;
            }
            prev = prev->next;
            t = t->next;
        }

        return Max;
    }
};
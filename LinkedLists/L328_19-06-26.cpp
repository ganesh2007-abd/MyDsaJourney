/*

Approach

1)initialise 2 pointers odd and even at 1st and 2nd nodes(So you have to handle edge cases of 0 and 1 size)
2)initialise 'se' pointer(starting node of even nodes) and set to 2nd node
3)all you have to do to connect odd nodes and even nodes together is doing -- odd->next=even->next -- then
  traverse the odd to its next node which means the latest odd node
4)then you connect even to odd->next node and dont lose the initial node of evens which is se beacsue after evry
linkage you have to connect the odd->next = se and then traverse the even to even-> next



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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *se = odd->next;
        while (even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            odd->next = se;
            even = even->next;
        }
        return head;
    }
};
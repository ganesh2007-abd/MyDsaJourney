/*

Approach

1)here we have to delete the node without having the actual head
2)which is impossible bcz without head we cant have tha prev node of node which is to be deleted(which is important for deletein)
3)so what we do is copy the node->next->val as its val and delete the next node
4)actually we are not deleting that node we are just changing the value thats it(that is not real deletion)


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
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
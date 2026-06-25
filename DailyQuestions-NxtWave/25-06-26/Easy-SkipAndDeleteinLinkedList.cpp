/*

approach

nothing to say -- its trivial

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node *next) : data(data), next(next) {}
};

class solution
{
public:
    Node *deleteNAfterMNodes(Node *head, int m, int n)
    {

        Node *q = head;
        Node *prev;
        int count1, count2;
        while (q != NULL)
        {
            count1 = 0;
            while (q != NULL && count1 < m)
            {
                prev = q;
                q = q->next;
                count1++;
            }
            count2 = 0;
            while (q != NULL && count2 < n)
            {
                prev->next = q->next;
                q->next = NULL;
                q = prev->next;
                count2++;
            }
        }
        return head;
    }
};

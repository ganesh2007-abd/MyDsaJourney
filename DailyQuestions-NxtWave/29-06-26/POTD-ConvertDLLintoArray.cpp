/*

*******Very simple problem***********

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        prev = next = NULL;
    }
};

class solution
{
public:
    vector<int> toArray(Node *node)
    {
        // Write Your Code Here..
        Node *temp = node->next;
        vector<int> v;
        while (node != NULL)
        {
            v.push_back(node->data);
            node = node->prev;
        }
        reverse(v.begin(), v.end());
        while (temp != NULL)
        {
            v.push_back(temp->data);
            temp = temp->next;
        }
        return v;
    }
};
/*

Approach

1)think from root node what we do actually is we find the height of left tree and also right treee if we got > 1 just simply set the bool to false and never change again
2)but keep updating the heights because we want it for height calculation

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class solution
{
public:
    int height(Node *root, bool &ans)
    {
        if (root == NULL)
            return 0;
        int lh = height(root->left, ans);
        int rh = height(root->right, ans);
        if (abs(lh - rh) > 1)
            ans = false;
        return 1 + max(lh, rh);
    }

    bool balanced(Node *root)
    {
        bool balance = true;
        int ht = height(root, balance);
        return balance;
    }
};
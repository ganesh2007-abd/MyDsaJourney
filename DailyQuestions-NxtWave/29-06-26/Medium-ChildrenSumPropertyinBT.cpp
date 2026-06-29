/*


Approach

1)think of code like -- lets first check wheather the present element is valid or not and then chekc its left subtree and right subtree
2)Base -- checking the current node si valid or not -- this involves many cases acording to type of nodes
3)if leaf node -- just simply return true
4)so you have to handle the node -- NULL,only right child node,only left child node,and normal node

*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class solution
{
public:
    bool childrenSumProperty(Node *root)
    {
        if (root == NULL)
            return true;

        if (root->left == NULL && root->right == NULL)
            return true;

        if (root->left == NULL)
        {
            if (root->data != root->right->data)
                return false;
        }
        else if (root->right == NULL)
        {
            if (root->data != root->left->data)
                return false;
        }
        else
        {
            if (root->data != root->left->data + root->right->data)
                return false;
        }

        return childrenSumProperty(root->left) &&
               childrenSumProperty(root->right);
    }
};
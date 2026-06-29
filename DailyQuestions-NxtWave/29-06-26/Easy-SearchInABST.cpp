
/*

Approach

1)iterative approach you can understand -- this is for recursive approach
2)when you target is < root->data you move left -- lese you move right
3)to find an element in a BST there is always one such path that exists
4)By following the left right rules if we fail to find the target we encounter the NULL
5)so we will add that too as base case



*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class solution
{
public:
    Node *search(Node *root, int target)
    {
        // Write your code here...
        //  while(root != NULL){
        //      if(root -> data == target){
        //          return root;
        //      }
        //      else if(target< root->data){
        //          root = root->left;
        //      }
        //      else{
        //          root=root->right;
        //      }
        //  }
        //  return NULL;

        if (root == NULL || root->data == target)
            return root;
        if (target < root->data)
        {
            return search(root->left, target);
        }
        else
        {
            return search(root->right, target);
        }
    }
};
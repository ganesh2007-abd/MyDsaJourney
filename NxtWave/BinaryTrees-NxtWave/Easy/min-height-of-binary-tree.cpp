/*


Approach

1)we should not simply do min(left,right) because it fails for the nodes having single child
2)if its right child is null then no matter of howmany nodes present in left it always returns 0 beacuse of min() comparision
3)so we handle the leaf,only right,only left nodes seperately


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
    int ShortestPath(Node *root)
    {
        // Write Your Code Here...
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        int l = INT_MAX;
        int r = INT_MAX;
        if (root->left != NULL)
        {
            l = ShortestPath(root->left);
        }
        if (root->right != NULL)
        {
            r = ShortestPath(root->right);
        }

        return 1 + min(l, r);
    }
};
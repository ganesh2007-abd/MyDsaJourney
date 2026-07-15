#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

class solution
{
public:
    Node *buildtree(vector<int> &postorder, int poststart, int postend, vector<int> &inorder, int instart, int inend, map<int, int> mpp)
    {
        if (poststart > postend || instart > inend)
            return NULL;
        Node *root = new Node(postorder[postend]);
        int inroot = mpp[root->data];
        int numsleft = inroot - instart;
        root->left = buildtree(postorder, poststart, poststart + numsleft - 1, inorder, instart, inroot - 1, mpp);
        root->right = buildtree(postorder, poststart + numsleft, postend - 1, inorder, inroot + 1, inend, mpp);

        return root;
    }

    Node *buildBinaryTree(vector<int> &inorder, vector<int> &postorder)
    {
        // Write your code here...
        map<int, int> mpp;
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            mpp[inorder[i]] = i;
        }
        Node *root = buildtree(postorder, 0, n - 1, inorder, 0, n - 1, mpp);
        return root;
    }
};
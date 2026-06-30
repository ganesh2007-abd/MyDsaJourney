/*

Approach

1)As we can access each level element sin level-order traversal we can simply sum up the elements and update the min each time


*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class solution
{
public:
    int locateMinimumLevel(Node *treeRoot)
    {
        if (treeRoot == NULL)
            return 0;
        // Write your code here...
        queue<Node *> q;
        q.push(treeRoot);
        int mini = INT_MAX;
        int miniidx = 1;
        int count = 1;
        long long sum = 0;
        while (!q.empty())
        {
            sum = 0;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                Node *temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                sum += temp->data;
            }
            if (sum < mini)
            {
                mini = sum;
                miniidx = count;
            }
            count++;
        }
        return miniidx;
    }
};
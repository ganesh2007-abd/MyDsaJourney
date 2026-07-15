#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class solution
{
public:
    // Encodes a tree to a single string.
    string serialize(Node *root)
    {
        if (!root)
            return "";
        string s = "";
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr == NULL)
            {
                s += "#,";
            }
            else
            {
                s += (to_string(curr->data) + ',');
            }
            if (curr != NULL)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    Node *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        Node *root = new Node(stoi(str));
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                curr->left = NULL;
            }
            else
            {
                Node *leftnode = new Node(stoi(str));
                curr->left = leftnode;
                q.push(leftnode);
            }
            getline(s, str, ',');
            if (str == "#")
            {
                curr->right = NULL;
            }
            else
            {
                Node *rightnode = new Node(stoi(str));
                curr->right = rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};
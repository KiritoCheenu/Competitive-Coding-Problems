#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data)
    {
        left = NULL;
        right = NULL;
    }
};

Node *flattenTree(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return NULL;
    if (root->left != NULL)
        flattenTree(root->left);
    if (root->right == NULL && root->left != NULL)
    {
        root->right = root->left;
        root->left = NULL;
    }
    if (root->right != NULL && root->left != NULL)
    {
        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        Node *t = root->right;
        while (t->right != NULL)
            t = t->right;
        t->right = temp;
    }
    flattenTree(root->right);
    return root;
}

void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->left != NULL)
    {
        flatten(root->left);
        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        Node *t = root->right;
        while (t->right != NULL)
            t = t->right;
        t->right = temp;
    }
    flatten(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    flatten(root);
    while (root != NULL)
    {
        cout << root->data;
        root = root->right;
    }
}

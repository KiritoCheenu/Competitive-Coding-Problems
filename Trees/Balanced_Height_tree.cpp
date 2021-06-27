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
int height(Node *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;

    cout << root->data << " ";
    if (isBalanced(root->left) == false)
        return false;
    if (isBalanced(root->right) == false)
        return false;

    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}
bool isBalancedOptimized(Node *root, int *height)
{
    if (root == NULL)
        return true;
    int lh = 0, rh = 0;
    if (isBalancedOptimized(root->left, &lh) == false)
        return false;
    if (isBalancedOptimized(root->right, &rh) == false)
        return false;
    // cout << *height << " ";
    *height = max(lh, rh) + 1;
    cout << "Data: " << root->data << " ";
    cout << "Height: " << *height << " ";
    cout << "Left: " << lh << " Right: " << rh << endl;
    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
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
    int height = 0;
    if (isBalancedOptimized(root, &height))
        cout << "Balanced Tree";
    else
        cout << "Unbalanced Tree";
}
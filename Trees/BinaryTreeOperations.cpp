#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *CreateNode(int data) {
    Node *newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *InsertNode(Node *root, int data) {
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}

void deletDeepest(struct Node *root,
                  struct Node *d_node) {
    queue<struct Node *> q;
    q.push(root);
    struct Node *temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            } else
                q.push(temp->right);
        }
        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            } else
                q.push(temp->left);
        }
    }
}

Node *deletion(struct Node *root, int key) {
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key)
            return NULL;
        else
            return root;
    }
    queue<struct Node *> q;
    q.push(root);
    struct Node *temp;
    struct Node *key_node = NULL;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->data == key)
            key_node = temp;
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    if (key_node != NULL) {
        int x = temp->data;
        deletDeepest(root, temp);
        key_node->data = x;
    }
    return root;
}

void inorder(Node *temp) {
    if (temp == NULL)
        return;
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

int main() {
    int n, deleteKey;
    cin >> n;
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        root = InsertNode(root, key);
    }
    inorder(root);
    cout << endl;
    cout << "Delete key: " << endl;
    cin >> deleteKey;
    root = deletion(root, deleteKey);
    inorder(root);
    return 0;
}
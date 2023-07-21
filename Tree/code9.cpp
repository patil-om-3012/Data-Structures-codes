// finding an elment in a BST

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

bool find(node *root, int key)
{
    if (root == nullptr || root->data == key)
    {
        return  root!= nullptr;
    }

    if (root->data > key)
    {
        return find(root->left, key);
    }

    if(root->data < key)
    {
        return find(root->right,key);
    }

    return false;
}

int main()
{
    node *root = newNode(6);
    node *p1 = newNode(4);
    node *p2 = newNode(8);
    root->left = p1;
    root->right = p2;
    p1->left = newNode(2);
    p1->right = newNode(5);
    p2->left = newNode(7);
    p2->right = newNode(9);
    p2->left->left = newNode(6);

    cout << find(root,9);
    cout << find(root,19);
}
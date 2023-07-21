//LCA of two nodes in a binary tree
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;

    return temp;
}

node* lca(node* root,node* n1,node* n2)
{
    node* left;node* right;
    if(root == nullptr)
    {
        return nullptr;
    }

    if(root == n1||root == n2)
    {
        return root;
    }

    left = lca(root->left,n1,n2);
    right = lca(root->right,n1,n2);

    if(left && right)
    {
        return root;
    }

    else
    {
        return left?left:right;
    }
}

int main()
{
    node* root = newNode(5);
    node* p1 = newNode(2);
    node* p2 = newNode(14);
    root->left = p1;root->right = p2;
    p1->left = newNode(1);p1->right = newNode(6);
    p2->left = newNode(7);p2->right = newNode(3);
}
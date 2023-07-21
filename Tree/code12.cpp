//LCA of a BST (Lowest Common Ancestor) and shoretst distance between two nodes in a BST

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

node* lca(node* root,int n1,int n2)
{
    if(root == nullptr)
    {
        return NULL;
    }

    if(n1 > root->data && n2 > root->data)
    {
        return lca(root->right,n1,n2);
    }

    if(n1 < root->data && n2 < root->data)
    {
        return lca(root->left,n1,n2);
    }

    return root;
}

int distance(node* temp,int x)
{
    if(temp == nullptr)
    {
        return 0 ;
    }

    if(temp->data == x)
    {
        return 0;
    }

    if(temp->data > x)
    {
        return 1+distance(temp->left,x);
    }
    return 1+distance(temp->right,x);
}

int shortestDistance(node*root,int n1,int n2)
{
    node* temp = lca(root,n1,n2);
    int d1 = distance(temp,n1);
    int d2 = distance(temp,n2);
    return d1+d1;
}

int main()
{
    node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    node* ans = lca(root,4,10);
    cout << ans->data;

    return 0;
}

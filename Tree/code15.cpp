//check for BST : corrcet approach

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

int findMin(node* root)
{
    if(root == nullptr)
    {
        return -1;
    }

    if(!root->left)
    {
        return root->data;
    }

    else{return findMin(root->left);}
}

int findMax(node* root)
{
    if(root == nullptr)
    {
        return -1;
    }

    if(!root->right)
    {
        return root->data;
    }

    else{return findMax(root->right);}
}

bool checkIsBST(node* root)
{
    if(root == nullptr)
    {
        return true;
    }

    if(root->left && root->data < findMax(root->left))
    {
        return false;
    }

    if(root->right && root->data > findMin(root->right))
    {
        return false;
    }

    if(!checkIsBST(root->left) || !checkIsBST(root->right))
    {
        return false;
    }

    return true;
}

int main()
{
    node* root = newNode(1);
    node* p1 = newNode(4);
    node* p2 = newNode(8);
    root->left = p1;root->right = p2;
    p1->left = newNode(2);p1->right = newNode(5);
    p2->left = newNode(7);p2->right = newNode(9);
    p2->left->left = newNode(6);

    cout << checkIsBST(root);
}

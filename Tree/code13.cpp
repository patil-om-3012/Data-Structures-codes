//check for a BST
//This a wrong approach as it only checks for the current node (See N.K.)

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

bool isBST(node* root)
{
    if(root == nullptr)
    {
        return true;
    }

    if((root->left!=NULL && root->left->data > root->data) || (root->right!=NULL && root->right->data < root->data))
    {
        return false;
    }

    if(!isBST(root->left) || !isBST(root->right))
    {
        return false;
    }

    return true;
}

int main()
{
    node* root = newNode(6);
    node* p1 = newNode(4);
    node* p2 = newNode(8);
    root->left = p1;root->right = p2;
    p1->left = newNode(2);p1->right = newNode(5);
    p2->left = newNode(7);p2->right = newNode(9);
    p2->left->left = newNode(6);

}

//inserting and deleting element in a BST

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

node* insert(node* root,int key)
{
    if(root == nullptr)
    {
        root->data = key;
        root->left = nullptr;
        root->right = nullptr;
    }

    if(root->data >  key)
    {
        root->left = insert(root->left,key);
    }

    if(root->data <  key)
    {
        root->right = insert(root->right,key);
    }

    return root;
}

node* maximumEle(node* root)
{
    if(root == nullptr)
    {
        return NULL;
    }

    else if(root->right == nullptr)
    {
        return root;
    }

    else
    {
        return maximumEle(root->right);
    }
}

node* deleteNode(node* root,int key)
{
    if(!root)
    {
        cout << 'Element not present';
        return NULL;
    }

    if(key < root->data)
    {
        root->left = deleteNode(root->left,key);
    }

    else if(key > root->data)
    {
        root->right = deleteNode(root->right,key);
    }

    else
    {
        if(root->left && root->right)
        {
            node* temp = maximumEle(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left,root->data);
        }

        else
        {
            node*temp = root;
            if(root->left == nullptr)
            {
                root = root->right;
            }
            if(root->right == nullptr)
            {
                root = root->left;
            }
            free(temp);
        }
    }

    return root;
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

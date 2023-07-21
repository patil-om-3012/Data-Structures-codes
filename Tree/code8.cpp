//mirror of a binary tree

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

void levelOrderTraversal(node* root)
{
    struct node* temp;
    queue<node*> q;

    if(root == nullptr)
    {
        return;
    }

    q.push(root);

    while(!q.empty())
    {
        temp = q.front();
        cout << temp->data;
        q.pop();
        if(temp->left) { q.push(temp->left);}
        if(temp->right) { q.push(temp->right);}
    }
}

node* mirror(node* root)
{
    if(root == nullptr)
    {
        return root;
    }

    node* temp;
    if(root)
    {
        mirror(root->left);
        mirror(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    return root;
}

int main()
{
    node* root = newNode(1);
    node* p1 = newNode(2);
    node* p2 = newNode(3);
    root->left = p1;root->right = p2;
    p1->left = newNode(4);p1->right = newNode(5);
    p2->left = newNode(6);p2->right = newNode(7);
    p2->left->left = newNode(6);

    root = mirror(root);
    levelOrderTraversal(root);
}
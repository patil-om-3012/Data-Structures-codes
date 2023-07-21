//number of leaves and full nodes in binary tree w/o recursion

#include <bits/stdc++.h>

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

int calLeaves(node* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    queue<node*> q;
    q.push(root);

    int count = 0;

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        
        if(!temp->left && !temp->right)
        {
            count++;
        }        

        else
        {
            if(temp->left) {q.push(temp->left);}
            if(temp->right) {q.push(temp->right);}
        }
    }

    return count;
}

int calFullNodes(node* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    queue<node*> q;
    q.push(root);

    int count = 0;

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        
        if(temp->left && temp->right)
        {
            count++;
            q.push(temp->left);
            q.push(temp->right);
        }        
    }

    return count;
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

    cout << calLeaves(root);
    cout << calFullNodes(root);
    
    return 0;
}
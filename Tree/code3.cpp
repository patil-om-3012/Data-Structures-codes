//calcualting height of bianry tree : recursive and iterative

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
    node* temp = new node();
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

int calRecursive(node* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    else
    {
        int leftHeight = calRecursive(root->left);
        int rightHeight = calRecursive(root->right);
        return 1 + std::max(leftHeight, rightHeight);
    }
}

int calItertaive(node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int height = 0;

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        height++;

        while(size--)
        {
            node* temp = q.front();

            if(temp->left) {q.push(temp->left);}
            if(temp->right) {q.push(temp->right);}

            q.pop();
        }
    }

    return height;
}

int main()
{
    node* root = newNode(5);
    node* p1 = newNode(2);
    node* p2 = newNode(14);
    root->left = p1;root->right = p2;
    p1->left = newNode(1);p1->right = newNode(6);
    p2->left = newNode(7);p2->right = newNode(3);
    p1->left->left = newNode(4);

    cout << calRecursive(root);
    cout << calItertaive(root);

    return 0;
}
// code to check if a tree is complete binary tree
// logic : first null node encountered must be the last non-null node.

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

bool checkIsCompleteBinary(node *root)
{
    bool foundNull = false;
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        if(temp->left)
        {
            if(foundNull)
            {
                return false;
            }
            q.push(temp->left);
        }

        else{foundNull = true;}

        if(temp->right)
        {
            if(foundNull)
            {
                return false;
            }
            q.push(temp->right);
        }

        else{foundNull = true;}
    }

    return true;
}

int main()
{
    node *root = newNode(6);
    node *p1 = newNode(4);
    node *p2 = newNode(8);
    root->left = p1;
    root->right = p2;
    p2->left = newNode(10);

    cout << checkIsCompleteBinary(root);
}

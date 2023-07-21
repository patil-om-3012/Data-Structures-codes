//given a sum. Check if there exists a path with given sum

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

bool pathExists(node* root,int sum)
{
    if (root == nullptr)
    {
        return (sum == 0);
    }

    int remainingSum = sum - root->data;

    if((root->left && root->right) || (!root->left && !root->right))
    {
        return pathExists(root->left,remainingSum) || pathExists(root->right,remainingSum);
    }

    else if(root->left) { return pathExists(root->left,remainingSum);}
    else { return(root->right,remainingSum);} 
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

    cout << pathExists(root,19);
    cout << pathExists(root,7);
}
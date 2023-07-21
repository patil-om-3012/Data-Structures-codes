//finding the diameter of a tree
//diameter can be either entirely from left or right subtree or from combination of both (left.height + right.height)

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

/*
int height(node* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left,right) + 1;
}

int diamater(node* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    int op1 = diamater(root->left);
    int op2 = diamater(root->right);
    int op3 = height(root->left) + height(root->right) + 1; //height->O(n); Here we call height inside diameter fn,Hence complexity becomes O(n^2)

    int ans = max(op1,max(op2,op3));
    return ans;
}
*/

//To reduce complexity and optimise to O(n), we make pair<int,int> first int stores diameter and second stores height

pair<int,int> optimiseDiameter(node* root)
{
    if(root == nullptr)
    {
        pair<int,int> p = {0,0};
        return p;
    }

    pair<int,int> left = optimiseDiameter(root->left);
    pair<int,int> right = optimiseDiameter(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second) + 1;

    return ans;    
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

    cout << optimiseDiameter(root).first;
}
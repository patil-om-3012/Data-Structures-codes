//finding max elemnt in binary tree : iterative and recurisve

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

int maxEleitertaive(node* root)
{
    int ans = INT_MIN;
    queue<node*> q;

    if(root!=NULL)
    {
        q.push(root);

        while(!q.empty())
        {
            node* temp= q.front();
            int ele = temp->data;
            q.pop();

            if(ele > ans)
            {
                ans = ele;
            }

            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }

    return ans;
}

int maxEleRecusive(node* root)
{
    int ans = INT_MIN;
    if(root != NULL)
    {
        int rootData = root->data;
        int left = maxEleRecusive(root->left);
        int right = maxEleRecusive(root->right);

        ans = max(max(right,left),rootData);
    }
    return ans;
}

int main()
{
    node* root = newNode(5);
    node* p1 = newNode(2);
    node* p2 = newNode(14);
    root->left = p1;root->right = p2;
    p1->left = newNode(1);p1->right = newNode(6);
    p2->left = newNode(7);p2->right = newNode(3);
    
    cout << "Max Element:" << maxEleRecusive(root);
    cout << "Max Element:" << maxEleitertaive(root);
}
//level with maximum sum

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

int maxLevel(node* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    queue<node*> q;
    q.push(root);

    int level = 0;
    int maxSum = 0;
    int ans;

    while(!q.empty())
    {
        int x = q.size();
        int sum;

        while(x--)
        {
            node* temp = q.front();
            q.pop();
            sum = 0;
            sum+=temp->data;
            if(temp->left) {q.push(temp->left);}
            if(temp->right) {q.push(temp->right);}
        }

        if(sum > maxSum) { ans = level;maxSum = sum;};
        level++;
    }

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

    cout << maxLevel(root);
}
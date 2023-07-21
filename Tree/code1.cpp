//Binary Tree operations : insert,delete,traversal

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

void preorder(node* root)
{
    if(root)
    {     
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
    }
}

void inorder(node* root)
{
    if(root)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

void postorder(node* root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
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

void remove(node* root,int key)
{
    if(root == nullptr)
    {
        return ;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        if(root->data == key)
        {
            return;
        }
        cout << "Element not present!";
        return;
    }

    node* last;
    node* temp;
    node* key_node = nullptr;

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->data == key)
        {
            key_node = temp;
        }

        if(temp->left)
        {
            last = temp;
            q.push(temp->left);
        }
        if(temp->right)
        {
            last = temp;
            q.push(temp->right);
        }
    }

    if(key_node)
    {
        key_node->data = temp->data;
        if(last -> right == temp)
        {
            last->right= nullptr;
        }
        last->left = nullptr;
        delete(temp);
        return ;
    }
    cout << "Element not present!";
    return;
}

int main()
{
    node* root = newNode(1);
    node* p1 = newNode(2);
    node* p2 = newNode(3);
    root->left = p1;root->right = p2;
    p1->left = newNode(4);p1->right = newNode(5);
    p2->left = newNode(6);p2->right = newNode(7);
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);
    cout<<endl;
    levelOrderTraversal(root);
    remove(root,5);
    remove(root,9);
    levelOrderTraversal(root);

    return 0;
}
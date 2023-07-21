//Revrese linked list in pairs
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

node* reverseInPair(node* head)
{
    node* temp = head;
    if(!head || !head->next)
    {
        return head;
    }

    temp = head->next;
    head->next = temp->next;
    temp->next = head;
    head = temp;

    head->next->next = reverseInPair(head->next->next);

    return head;
}

void traverse(node* head)
{
    while(head)
    {
        cout << head->data << " " ;
        head = head->next;
    }

    return;
}

int main()
{
    node* head = newNode(1);
    node* x = head->next = newNode(2);
    node* y = x->next = newNode(3);
    node* z = y->next = newNode(4);
    node* k = z->next = newNode(5);

    head = reverseInPair(head);
    traverse(head);
}
//reverse a singly linked list
//finding kth element from end of linked list
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
    return temp;
}

void traverse(node* head)
{
    if (head == nullptr)
    {
        return;
    }

    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }

    return;
}

node* reverse(node* head)
{
    node* prev = nullptr;
    node* current = head;
    node* next;
    while(current!=nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

int main()
{
    node* head = newNode(1);
    node* x = head->next = newNode(2);
    node* y = x->next = newNode(3);
    node* z = y->next = newNode(4);
    z->next = nullptr;
    node* t = reverse(head);
    traverse(t);
    return 0;
}
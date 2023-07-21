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

int kthEleFromEnd(node* head, int k)
{
    int n = 0;
    node* temp = head;
    while (temp != nullptr)
    {
        n++;
        temp = temp->next;
    }
    int count = 0;
    while (count != n - k )
    {
        count++;
        head = head->next;
    }

    return head->data;
}

int main()
{
    node* head = newNode(1);
    node* x = head->next = newNode(2);
    node* y = x->next = newNode(3);
    node* z = y->next = newNode(4);
    z->next = nullptr;
    //traverse(head);
    cout << kthEleFromEnd(head, 2);

    return 0;
}
//ref NK for more efficient approach
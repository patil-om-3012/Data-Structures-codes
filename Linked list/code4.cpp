//given two linked lists which merge into one at a particular node.Find the comnnon node
#include<bits/stdc++.h>

using namespace std;

struct node
{
    int data;struct node* next;
};

node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    return temp;
}

node* findCommonNode(node* head1,node* head2)
{
    unordered_map<int,node*> hashMap;
    while(head1!=NULL)
    {
        hashMap[head1->data] = head1;
        head1=head1->next;
    }
    while(head2->next!=nullptr)
    {
        if(hashMap.find(head2->data)!=hashMap.end())
        {
            return head2;
        }
        head2 = head2->next;
    }

    return nullptr;
}

int main()
{
    node* head1 = newNode(11);
    node* head2 = newNode(21);
    node* p1 = head1->next = newNode(12);
    node* p2 = head2->next = newNode(22);
    node* p3=p2->next = newNode(23);
    node* x = p3->next = p1->next = newNode(40);
    node* y = x->next = newNode(50);
    y->next = nullptr;
    cout << findCommonNode(head1,head2)->data;
    return 0;
}
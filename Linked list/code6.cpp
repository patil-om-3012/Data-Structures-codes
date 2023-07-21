//linked list is palindromic or not works for odd length linked list
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

bool isPalindrome(node* head)
{
    stack<int> s;
    node* slow = head;
    node* fast = head;

    while(fast)
    {
        slow = slow->next;
        s.push(slow->data);
        fast = fast->next->next;
    }
    s.pop();

    node* middleNode = slow;
    while(middleNode)
    {
        int t = middleNode->data;
        if(t == s.top())
        {
            s.pop();
            middleNode = middleNode->next;
        }

        else
        {
            return 0;
        }
    }

    return 1;

}

int main()
{
    node* head = newNode(1);
    node* x = head->next = newNode(2);
    node* y = x->next = newNode(3);
    node* z = y->next = newNode(2);
    node* k = z->next = newNode(1);
    cout << isPalindrome(head);
}
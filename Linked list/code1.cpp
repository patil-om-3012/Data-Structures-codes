//finding loop in a linked list

/*
Approaches
1.Bruteforce : take each node and see if its adjacent ptr points to the current node's adjacent ptr
2.Hash table implementation: Better than brute force. Space and time complexity: O(n) 
3.Efficient approach: (Floyd's cycle algorithm) time O(n),space o(1) implemented here.
Idea : two pointers fast and slow. If a loop exists,they will meet.*/

#include<bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    struct node* next;
};

struct node* addNode(struct node* head,int val)
{
    struct node *newNode,*cur;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    cur = head;
    if(cur == NULL)
    {
        head = newNode;
    }
    
    else
    {
        while(cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newNode;
    }

    return head;
}

bool findLoop(struct node* head)
{
    struct node* fast;
    struct node* slow;
    fast=slow=head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            return true;
        }
    }

    return false;

}

int main()
{
    struct node* head = NULL;
    head = addNode(head,1);
    head = addNode(head,2);
    head = addNode(head,3);
    //head->next->next = head->next;

    if(findLoop(head))
    {
        cout << "Loop exists" << endl;
    }
    
    else
    {
        cout << "No Loop exists" << endl;
    }

    return 0;
}
//implementing stack via an array
#include<bits/stdc++.h>

using namespace std;

struct Stack
{
    int top;
    int capacity;
    int* arr;

    Stack(int capacity)
    {
        this->top = -1;
        this->capacity = capacity;
        this->arr = new int[capacity];
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == capacity-1);
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value; //updates top value as well
        cout << value << " pushed to stack\n";
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return -1;
        }

        return arr[top--]; //updates the top value as well
    }

    int peak()
    {
        if(isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        return arr[top];
    }

};

int main()
{
    Stack s(5);
    s.push(12);
    cout << s.pop();
    s.peak();
    return 0;
}
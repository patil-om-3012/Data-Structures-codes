//parenthesis validity

#include<bits/stdc++.h>

using namespace std;

//if one wants to implement stack via array
struct Stack
{
    int top;
    int capacity;
    char* arr;

    Stack(int capacity)
    {
        this->top = -1;
        this->capacity = capacity;
        this->arr = new char[capacity];
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == capacity-1);
    }

    void push(char s)
    {
        if(!isFull())
        {
            top++;
            arr[top] = s;
            return;
        }

        cout << "Stack Overflow" << endl;
    }

    char pop(char s)
    {
        if(!isEmpty())
        {
            top--;
            return arr[top];
        }

        cout << "Stack Underflow" << endl;
        return '\0';
    }

    char peak()
    {
        if(!isEmpty())
        {
            return arr[top];
        }

        cout << "Stack Underflow" << endl;
        return '\0';
    }
};

bool isMatchingPair(char opening, char closing)
{
    if (opening == '(' && closing == ')')
        return true;
    if (opening == '{' && closing == '}')
        return true;
    if (opening == '[' && closing == ']')
        return true;
    return false;
}

bool checkParenthesesValidity(const string& expression)
{
    stack<char> s;

    for (char c : expression)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (s.empty() || !isMatchingPair(s.top(), c))
                return false;
            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (checkParenthesesValidity(expression))
        cout << "Valid expression" << endl;
    else
        cout << "Invalid expression" << endl;

    return 0;
}

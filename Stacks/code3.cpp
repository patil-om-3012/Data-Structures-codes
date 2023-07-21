//infix to postfix conversion
//The algorithm follows the concept of operator precedence and association. It ensures that higher precedence operators are placed later in the postfix expression
//and operators with the same precedence are placed in the order of their appearance.
//if it an alphabet,pop out and add to postfix expression
//if it is ( ,push it into stack
//if an operator : 1.if stack is empty || top of stack is ( , push it to stack. 2.if top of stack is operator, pop untill a LOWER precedence opeartor is found
//if closing parenthesis : pop all elemnts of stack untill opening parenthesis is encountered

#include<bits/stdc++.h>

using namespace std;

int priority(char c)
{
    if (c == '(')
        return 0;
    if (c == '+' || c == '-')
        return 1;
    return 2;
}

int main()
{
    string input;
    cout << "Enter the infix expression: ";
    cin >> input;

    stack<char> s;
    string postfix;

    for (char c : input)
    {
        if (isalnum(c)) // checks if the character is alphanumeric
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(')
                s.pop(); // Discard the opening parenthesis
        }
        else
        {
            while (!s.empty() && priority(s.top()) >= priority(c))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

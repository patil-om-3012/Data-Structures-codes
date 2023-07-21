//Evlauting a postfix epression

#include<bits/stdc++.h>

using namespace std;

bool isOperator(char c)
{
    return (c=='+' || c=='-' || c=='/' || c=='*');
}

int main()
{
    stack<int> s;
    string exp;
    cin >> exp;

    for(char letter:exp)
    {
        if(!isOperator(letter))
        {
            s.push(letter - '0'); //digit to integer
        }
        else
        {
            int a = s.top();
            s.pop();
            int b= s.top();
            s.pop();

            switch(letter)
            {
                case '+':s.push(b+a);break;
                case '-':s.push(b-a);break;
                case '*':s.push(b*a);break;
                case '/':s.push(b/a);break;
            }
        }
    }

    cout << s.top();
    return 0;
}
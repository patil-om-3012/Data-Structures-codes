//algorithm to revrese a stack

#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> s;
    for(int i=0;i<10;i++)
    {
        s.push(i);
    }
    queue<int> q;
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    for(int i=0;i<s.size();i++)
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
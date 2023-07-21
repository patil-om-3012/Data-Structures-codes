//design a stack that gives min element in constant time

#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack<int> s;
    stack<int> minStack;

    int ans = INT_MAX;

    s.push(3);
    minStack.push(min(INT_MAX,s.top()));
    ans = minStack.top();
}
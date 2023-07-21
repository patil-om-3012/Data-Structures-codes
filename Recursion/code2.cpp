//Generating n-bit binary strings
#include<bits/stdc++.h>

using namespace std;

vector<int> arr;

void binary(int n)
{
    if(n < 1)
    {
        cout << arr[0];
        return;
    }

    else
    {
        arr[n-1] = 0;
        binary(n-1);
        arr[n-1] = 1;
        binary(n);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    binary(n);
}
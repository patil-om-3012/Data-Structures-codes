#include<bits/stdc++.h>

using namespace std;

//fibonnaci series

int recurisveFib(int n)
{
    if(n == 0) {return 0;}
    if(n == 1) {return 1;}

    return recurisveFib(n-1) + recurisveFib(n-2);
}

int memoisation(int n) //top-down
{
    int dp[n+1] = {0}; //dp array always initialised 1 + number of elements
    //need to initiliase the dp array in C++
    if(n == 0) {return 1;}
    if(n == 1) {return 1;}

    if(dp[n]!=0)
    {
        return dp[n];
    }

    return dp[n] = memoisation(n-1) + memoisation(n-2);

} //TC,SC : O(n)

int tabulation(int n) //bottom-up
{
    int dp[n+1];

    if(n == 0) {return 1;}
    if(n == 1) {return 1;}

    dp[0] = 1; //base cases initialised by self
    dp[1] = 1;

    for(int i=2;i<=n;i++) //step-by-step bottom to up
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main()
{
    //cout << recurisveFib(5);
    //cout << memoisation(5);
    cout << tabulation(5);
}
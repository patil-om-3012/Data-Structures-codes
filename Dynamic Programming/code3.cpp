//Longest common subsequence --> memoisation

#include<bits/stdc++.h>

using namespace std;

int LCS(vector<vector<int>> &dp,int i,int j,string a,string b)
{
    if(i==a.length() || j==b.length())
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = 0;

    if(a[i] == b[j])
    {
        ans = 1 + LCS(dp,i+1,j+1,a,b);
    }

    else
    {
        ans = max(LCS(dp,i+1,j,a,b),LCS(dp,i,j+1,a,b));
    }

    return dp[i][j] = ans;
}

int main()
{
    string a;
    cin >> a;
    string b;
    cin >> b;

    int n = a.length() ; int m = b.length();

    vector<vector<int>> dp(n,vector<int>(m,-1)); // -1 since we dont know if 0 or how many characters have matched as dp[i][j] is not yet checked

    cout << LCS(dp,0,0,a,b);

}
//0-1 knapsack

#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &weights,vector<int> &values,int capacity,int x,vector<vector<int>> &dp)
{
    //base case
    if(capacity < 0)
    {
        return 0;
    }

    //dp array utilisation
    if(dp[x][capacity] != -1)
    {
        return dp[x][capacity];
    }

    int selected = solve(weights,values,capacity-weights[x],x-1,dp) + values[x];
    int notSelected = solve(weights,values,capacity,x-1,dp);
    
    return dp[x][capacity] = max(selected,notSelected);
}

int kanpsack(vector<int> weights,vector<int> values,int capacity)
{
    int n = weights.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));

    return solve(weights,values,capacity,n,dp);
}
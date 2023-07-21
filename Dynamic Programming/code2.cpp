//Maximum contigous subarray sum using DP

#include <bits/stdc++.h>

using namespace std;

int dpSum(vector<int> &arr,int n)
{
    int dp[n];
    //dp[n] = 0;
    int maxSum = 0;
    if(arr[0] < 0){dp[0] = 0;}
    else
    {
        dp[0] = arr[0];
    }

    for(int i=1;i<n;i++)
    {
        if(dp[i-1] + arr[i] > 0)
        {
            dp[i] = dp[i-1] + arr[i];
        }
        else{dp[i] = 0;}
    }

    for(int i=0;i<n;i++)
    {
        cout << dp[i] << endl;
    }

    for(int i=0;i<n;i++)
    {
        if(dp[i] > maxSum)
        {
            maxSum =  dp[i];
        }
    }
    return maxSum;
}

int main()
{
    vector<int> arr;
    arr.push_back(-2);
    arr.push_back(11);
    arr.push_back(-4);
    arr.push_back(13);
    arr.push_back(-5);
    arr.push_back(2);

    cout << dpSum(arr,6);
}
//Maximum product subarray 
//slight modification of kadane's : traverse from both isdes and return max(left,right)
//two traversals:for one travesal ref dp soln

#include<bits/stdc++.h>

using namespace std;

int maxProduct(vector<int> &arr)
{
    int n = arr.size();

    int prod = 1;
    int left = INT_MIN;
    int right = INT_MIN;

    for(int i=0;i<n;i++)
    {
        prod*=arr[i];
        left = max(left,prod);
        
        if(prod == 0)
        {
            prod = 1;
        }
    }

    prod = 1;

    for(int i=n-1;i>=0;i--)
    {
        prod*=arr[i];
        right = max(right,prod);
        
        if(prod == 0)
        {
            prod = 1;
        }
    }

    return max(left,right);

}

int main()
{
    vector<int> arr = {1,-12,1,4,-5,-3};
    cout << maxProduct(arr);
}
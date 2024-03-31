//Leetcode 1498 : Number of Subsequences That Satisfy the Given Sum Condition

#define mod 1000000007

class Solution {
public:
    long long power(int n){
        if(n <= 1) return (n+1);
        long long res = power(n/2);
        if(n%2) return (((res*res)%mod)*2)%mod;
        return ((res*res)%mod);
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 0;

        int i = 0;int j = nums.size()-1;

        while(i <= j){
            if(nums[i] + nums[j] <= target){
                ans = (ans+power((long long)j-i))%mod;
                i++;
            }
            else{
                j--;
            }
        }

        return ans;
    }
};

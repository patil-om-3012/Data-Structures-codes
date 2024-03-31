//Leetcode 3082. Find the Sum of the Power of All Subsequences

//Method 1:-
class Solution {
public:
    int m = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    
    long long power(int n){
        if(n <= 1) return (n+1);
        long long res = power(n/2);
        if(n%2) return (((res*res)%m)*2)%m;
        return ((res*res)%m);
    }
    
    long long solve(vector<int>& nums, int k, int i, int sum, int count){
        if(sum == k) {
            return power(nums.size() - count);
        }
        if(i >= nums.size() || sum > k ) return 0;
        if(dp[i][count][sum] != -1) return dp[i][count][sum];
        
        long long take = solve(nums, k, i + 1, sum + nums[i], count + 1);
        long long notTake = solve(nums, k, i + 1, sum, count);
        return dp[i][count][sum] = (take + notTake)%m;
    }
    
    int sumOfPower(vector<int>& nums, int k) {
        dp.resize(100, vector<vector<int>>(110, vector<int>(110, -1)));
        return solve(nums, k, 0, 0, 0);
    }
};

//method 2:optimised version of method 1
//Optimised version just by multiplying 2 when element is not taken and further adding 2^(n-i) to final ans

class Solution {
public:
    int m = 1e9 + 7;
    vector<vector<int>> dp;
    
    long long power(int n){
        if(n <= 1) return (n+1);
        long long res = power(n/2);
        if(n%2) return (((res*res)%m)*2)%m;
        return ((res*res)%m);
    }
    
    long long solve(vector<int>& nums, int k, int i, int sum){
        if(sum == k) {
            return power(nums.size() - i);
        }
        if(i >= nums.size() || sum > k ) return 0;
        if(dp[i][sum] != -1) return dp[i][sum];
        
        long long take = solve(nums, k, i + 1, sum + nums[i]);
        long long notTake = 2*solve(nums, k, i + 1, sum);
        return dp[i][sum] = (take + notTake)%m;
    }
    
    int sumOfPower(vector<int>& nums, int k) {
        dp.resize(100, vector<int>(110, -1));
        return solve(nums, k, 0, 0);
    }
};

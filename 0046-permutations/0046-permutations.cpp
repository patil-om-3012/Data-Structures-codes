class Solution {
public:
    void generatePermutation(vector<int> &cur,vector<vector<int>> &ans,vector<int>& nums)
    {
        if(cur.size() == nums.size())
        {
            ans.push_back(cur);
            return;
        }

        for(int n:nums)
        {
            if(find(cur.begin(),cur.end(),n) == cur.end())
            {
                cur.push_back(n);
                generatePermutation(cur,ans,nums);
                cur.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> cur = {};
        generatePermutation(cur,ans,nums);
        
        return ans;
    }
};
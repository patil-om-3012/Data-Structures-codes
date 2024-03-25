//Leetcode 1:Two sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> hashTable;

        for(int i=0;i<nums.size();i++)
        {
            int comp = target-nums[i];
            if(hashTable.find(comp) != hashTable.end())
            {
                return {hashTable[comp],i};
            }
            hashTable[nums[i]] = i;
        }

        return {};
    }
};

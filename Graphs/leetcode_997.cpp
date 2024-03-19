//Leetcode 997:Find the town judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1){
            return 1;
        }
        vector<int> inDegree(n,0);
        vector<int> outDegree(n,0);

        for(auto r:trust){
            inDegree[r[1]-1]++;
            outDegree[r[0]-1]++;
        }

        for(int i=0;i<n;i++){
            if(outDegree[i] == 0 && inDegree[i] == n-1){
                return i+1;
            }
        }

        return -1;
    }
};
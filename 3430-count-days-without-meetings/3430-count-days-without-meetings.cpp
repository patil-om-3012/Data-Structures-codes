class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(),[](vector<int>& a,vector<int>& b){
            return a[0] < b[0];
        });

        int ans = 0;
        int prev = 0;
        for(auto meet:meetings){
            if(prev < meet[0]-1){
                ans+= meet[0]-prev-1;
            }
            prev = max(prev,meet[1]);
        }

        if(prev < days){
            ans += days-prev;
        }

        return ans;
    }
};
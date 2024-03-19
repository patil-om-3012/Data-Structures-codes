//This is a solution of #Leetcode problem no.743 : Network delay time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];

        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int dest = times[i][1];
            int time = times[i][2];
            adj[source].push_back({time, dest});
        }
    
        vector<int> signalReceiveTime(n + 1, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, k});
    
        signalReceiveTime[k] = 0;
        
     
        while (!pq.empty()) {
            int currNodeTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            if (currNodeTime > signalReceiveTime[currNode]) {
                continue;
            }
          
            for (int i = 0; i < adj[currNode].size(); i++) {
                pair<int, int> edge = adj[currNode][i];
                int time = edge.first;
                int neighborNode = edge.second;
            
                if (signalReceiveTime[neighborNode] > currNodeTime + time) {
            
                    signalReceiveTime[neighborNode] = currNodeTime + time;
                    pq.push({signalReceiveTime[neighborNode], neighborNode});
                }
            }
        }
        
        int result = INT_MIN;
        for (int i = 1; i <= n; i++) {
            result = max(result, signalReceiveTime[i]);
        }
        
        if (result == INT_MAX) {
            return -1;
        }
        return result;
    }
};
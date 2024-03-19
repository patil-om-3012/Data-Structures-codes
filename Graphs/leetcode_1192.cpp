//Leetcode probl3m 1992: Critical connections in a network

class Solution {
public:
    void bridgeEdges(int src,int parent,int &time,vector<vector<int>>& adjList,vector<vector<int>> &ans,vector<int> &lowestTime,vector<int> &discoveryTime,vector<int>& visited)
    {
        visited[src] = 1;
        time++;
        discoveryTime[src] = lowestTime[src] = time;

        for(auto n:adjList[src])
        {
            if(!visited[n])
            {
                bridgeEdges(n,src,time,adjList,ans,lowestTime,discoveryTime,visited);
                lowestTime[src] = min(lowestTime[src],lowestTime[n]);
                if(lowestTime[n] > discoveryTime[src])
                {
                    ans.push_back({src,n});
                }
            }
            else if(n != parent)
            {
                lowestTime[src] = min(lowestTime[src],discoveryTime[n]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> ans;
        vector<vector<int>> adjList(n);
        for(auto connection:connections)
        {
            adjList[connection[0]].push_back(connection[1]);
            adjList[connection[1]].push_back(connection[0]);
        }
        vector<int> lowestTime(n,0);
        vector<int> discoveryTime(n,0);
        vector<int> visited(n,0);
        int time = 0;

        bridgeEdges(0,-1,time,adjList,ans,lowestTime,discoveryTime,visited);

        return ans;
    }
};
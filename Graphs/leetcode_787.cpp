//#Leecode problem 787:Cheapest Flights Within K Stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int k) {

        vector<vector<pair<int,int>>> adjList(n); //{dest,edgeWeight}

        for(auto details:flights)
        {
            adjList[details[0]].push_back({details[1],details[2]});
        }

        //Dijsktra compiled into BFS

        queue<pair<int,int>> q;
        q.push({src,0});
        int count = 0;
        vector<int> distance(n,INT_MAX);

        while(!q.empty() && count<=k)
        {
            int x = q.size();

            while(x--)
            {
                pair<int,int> temp = q.front();
                q.pop();

                for(auto neighbors:adjList[temp.first])
                {
                    if(neighbors.second + temp.second >=  distance[neighbors.first])
                    {
                        continue;
                    }
                    distance[neighbors.first] = neighbors.second + temp.second;
                    q.push({neighbors.first,distance[neighbors.first]});
                }
            }
            count++;
        }

        return distance[dest] == INT_MAX?-1:distance[dest];
    }
};
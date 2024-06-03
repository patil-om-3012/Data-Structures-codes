class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph,vector<int>& path,int cur){
        path.push_back(cur);
        if(cur == graph.size()-1){
            ans.push_back(path);
        }

        else{
            for(auto next:graph[cur]){
                dfs(graph,path,next);
            }
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;

        dfs(graph,path,0);
        return ans;
    }
};
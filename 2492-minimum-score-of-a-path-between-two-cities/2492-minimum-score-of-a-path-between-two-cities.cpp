class Solution {
public:

    void DFS(vector<vector<pair<int,int>>>&adj,int u,vector<bool>&visited,int &res){
        if(visited[u]==true) return;
        visited[u] = true;

        for(auto &[v,cost]:adj[u]){
            res = min(res,cost);
            if(!visited[v]){
                DFS(adj,v,visited,res);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool>visited(n+1,false);

        int res = 1e+9;
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto &road:roads){
            int u = road[0];
            int v  = road[1];
            int cost = road[2];

            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
        DFS(adj,1,visited,res);

        return res;
    }
};
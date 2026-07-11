class Solution {
public:
    void DFS(vector<vector<int>>&adj,int u,vector<bool>&visited,int &node,int &edge){
        visited[u] = true;
        node++;

        edge += adj[u].size();

        for(int &v:adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited,node,edge);
            }
        } 

    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // first make adjecency list 
        vector<vector<int>>adj(n);

        for(auto &e:edges){
            int u = e[0];
            int v = e[1];
            //undirected edge means 0->1 1->0
            adj[u].push_back(v);

            adj[v].push_back(u);
        }
        // number of complete cycles
        int res=0;
        vector<bool>visited(n,false);
        for(int i = 0;i<n;i++){
            int edge= 0;
            int node = 0;
            DFS(adj,i,visited,node,edge);

            if(edge == node* (node-1)){
                res++;
            }
        }
        return res;
    }
};
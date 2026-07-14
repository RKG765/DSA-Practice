



// if BFs using khan's algo is true then return true
class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inorder(numCourses);
        queue<int>q;

        for(auto &x:prerequisites){
            int u = x[0];
            int v = x[1];
            // directed graph 
            adj[u].push_back(v);
        }

        for(int u = 0;u<numCourses;u++){
            for(int v:adj[u]){
                inorder[v]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0)
                q.push(i);
        }
        int nodes = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            nodes++;

            for(int v:adj[u]){
                inorder[v]--;
                if(inorder[v]==0)
                    q.push(v);
            }
        }
        if(nodes==numCourses)
            return true;
        return false;
    }
};


// if cycclic is true then return false
class Solution2{
public:
    //finding cycle
    bool dfs(vector<vector<int>>&adj,int u,vector<bool>&visited,vector<int>&rec){
        visited[u] = true;
        rec[u] = true;

        for(int v:adj[u]){
            if(!visited[v]){
                dfs(adj,v,visited,rec);
            }
            if(rec[v])
                return true;
        }
        rec[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>>adj(numCourses);
       vector<bool>visited(numCourses,false);
       vector<int>rec(numCourses);

       for(auto &x:prerequisites){
            int u = x[0];
            int v = x[1];
            // directed graph 
            adj[u].push_back(v);
       }

       for(int i = 0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(adj,i,visited,rec))
                    return false;
            }
       }
       return true;
    }
};